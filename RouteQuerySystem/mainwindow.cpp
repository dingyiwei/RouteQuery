#include "mainwindow.h"
#include "dataprocessor.h"
#include "dijkstra.h"
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include <QPainter>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>
#include <QEventLoop>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//���ô����ޱ߿�
	setWindowFlags(Qt::FramelessWindowHint);

	//��ȡ��ͼ����
	DataProcessor *dp = new DataProcessor();
	nodes = dp->getNodes();
	points = dp->getPoints();
	caMap = dp->getMap();
	regions = dp->getRegions();
	delete dp;

	//��ʼ��չʾ��
	mapArea = new MapArea(&nodes, &points, &caMap, this);
	mapArea->move(0, 50);

	//����չʾ����Ӱ
	QGraphicsDropShadowEffect *graphicEffect = new QGraphicsDropShadowEffect(this);
	graphicEffect->setOffset(0, 0);
	graphicEffect->setColor(QColor("#bbbbbb"));
	graphicEffect->setBlurRadius(10);
	mapArea->setGraphicsEffect(graphicEffect);

	//��ʼ�����Ű�ť��
	zoomButtons = new ZoomButtons(this);
	zoomButtons->move(20, 70);

	//�������Ű�ť����Ӱ
	QGraphicsDropShadowEffect *zoomButtonsEffect = new QGraphicsDropShadowEffect(this);
	zoomButtonsEffect->setOffset(0, 0);
	zoomButtonsEffect->setColor(QColor("#bbbbbb"));
	zoomButtonsEffect->setBlurRadius(10);
	zoomButtons->setGraphicsEffect(zoomButtonsEffect);

	//��ʼ������
	mask = new QWidget(this);
	mask->setStyleSheet("background-color:black");
	mask->resize(this->size());

	//��ʼ��������
	navigationBar = new NavigationBar(this);
	navigationBar->move(-270, 0);
	navigationBar->show();

	//��ʼ���˵���ť
	menuButton = new MenuButton(this);

	//��ʼ���رհ�ť
	closeButton = new CloseButton(this);
	closeButton->move(750, 0);
	//�رմ���
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

	//��ʼ��������ť
	helpButton = new HelpButton(this);
	helpButton->move(700, 0);

	//���ñ�������Ӱ
	QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
	effect->setOffset(0, 2);
	effect->setColor(Qt::gray);
	effect->setBlurRadius(10);
	ui.menubar->setGraphicsEffect(effect);

	//���õ�������Ӱ
	QGraphicsDropShadowEffect *navigationBarEffect = new QGraphicsDropShadowEffect(this);
	navigationBarEffect->setOffset(2, 0);
	navigationBarEffect->setColor(QColor("#444444"));
	navigationBarEffect->setBlurRadius(10);
	navigationBar->setGraphicsEffect(navigationBarEffect);

	//��������͸����
	maskEffect = new QGraphicsOpacityEffect(this);
	maskEffect->setOpacity(0);
 	mask->setGraphicsEffect(maskEffect);
	mask->hide();

	//���õ���������
	timeLine = new QTimeLine(500, this);
	timeLine->setFrameRange(-270, 0);
	timeLine->setCurveShape(QTimeLine::EaseInOutCurve);
	//����������
	connect(timeLine, SIGNAL(frameChanged(int)), this, 
		SLOT(moveNavigationBar(int)));
	connect(menuButton, SIGNAL(clicked()), this, SLOT(openNavigation()));

	//��ʼ������Ի���
	inputDialog = new InputDialog(&nodes);
	//ƫ������
	connect(navigationBar->getPreferenceSettingButton(), SIGNAL(clicked()),
		inputDialog, SLOT(exec()));
	//ȷ������
	connect(inputDialog->getConfirmButton(), SIGNAL(clicked()), this, 
		SLOT(displayRoute()));

	//Voronoiͼ
	connect(navigationBar->getVoronoiButton(), SIGNAL(clicked()), this,
		SLOT(drawVoronoiGraph()));
	//�鿴���
	connect(navigationBar->getResultButton(), SIGNAL(clicked()), this,
		SLOT(displayRoute()));

	//�Ŵ�
	connect(zoomButtons->getZoomInButton(), SIGNAL(clicked()), this,
		SLOT(mapZoomIn()));
	//��С
	connect(zoomButtons->getZoomOutButton(), SIGNAL(clicked()), this,
		SLOT(mapZoomOut()));

	//��ʼ�������Ի���
	helpDialog = new HelpDialog();
	connect(helpButton, SIGNAL(clicked()), helpDialog, SLOT(exec()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
	winPos = pos();
	mousePos = event->globalPos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
	move(event->globalPos() - mousePos + winPos);
}

void MainWindow::moveNavigationBar(int xpos)
{
	navigationBar->move(xpos, 0);
	maskEffect->setOpacity((double)(-xpos-260) / (-520.0));
}

void MainWindow::openNavigation()
{
	setNavigationBar();
	hideMask();
}

void MainWindow::setNavigationBar()
{
	if (isNavigationOpen)
	{
		timeLine->setDirection(QTimeLine::Backward);
		timeLine->start();
	}
	else
	{
		mask->show();
		timeLine->setDirection(QTimeLine::Forward);
		timeLine->start();
	}
	isNavigationOpen = !isNavigationOpen;
}

void MainWindow::hideMask()
{
// 	QTimer *timer = new QTimer();
// 	timer->start(1);
	if (!isNavigationOpen/*&&!timer->isActive()*/)
	{
		mask->hide();
	}
}

void MainWindow::displayRoute()
{
	if (voronoi != nullptr)
	{
		delete voronoi;
		voronoi = nullptr;
	}
	if (skyline != nullptr)
	{
		delete skyline;
		skyline = nullptr;
	}

	//������
	Point start;
	start.x = inputDialog->getStartX();
	start.y = inputDialog->getStartY();
	start.category = -1;
	int startNodeIndex = inputDialog->getStartNodeIndex();

	//���ƫ��
	int preference = inputDialog->getPreference();

	//��������������
	double rowDistance = (TOP - BOTTOM) / ROW;
	double colDistance = (RIGHT - LEFT) / COL;
	int rowRegion = (int)((start.x - LEFT) / colDistance);
	int colRegion = (int)((TOP - start.y) / rowDistance);
	start.regionIndex = rowRegion*ROW + colRegion;

	//�����������
	QVector<int> categorySquence = inputDialog->getCategorySequence();

	//������������ݵ�
	QMap<int, QVector<Point>> partOfMap;
	for each(int category in categorySquence)
	{
		if (!partOfMap.contains(category))
		{
			partOfMap[category] = QVector<Point>();
		}
	}
	for each(int pointIndex in regions[start.regionIndex])
	{
		if (partOfMap.contains(points[pointIndex].category))
		{
			partOfMap[points[pointIndex].category].push_back(points[pointIndex]);
		}
	}

	//��������ڱߡ����
	QVector<SimpleEdge> simpleEdges;
	QMap<int, Node> selectedNodes;
	for (int i = 0; i < caMap.size(); ++i)
	{
		if (caMap[i].regionIndex == start.regionIndex)
		{
			simpleEdges.push_back({ caMap[i].u,caMap[i].v });
			simpleEdges.push_back({ caMap[i].v,caMap[i].u });
			selectedNodes[caMap[i].u] = nodes[caMap[i].u];
			selectedNodes[caMap[i].v] = nodes[caMap[i].v];
			if (startNodeIndex == caMap[i].u || startNodeIndex == caMap[i].v)
			{
				start.edgeIndex = i;
			}
		}
	}

	//Voronoiͼ
	voronoi = new Voronoi(partOfMap, categorySquence, start);

	//skyline��ѯ
	skyline = new Skyline(voronoi->getRoutes(), preference);

	//�������·��
	QVector<QVector<int>> routesIndexes;
	int pointsCount = 0;
	QVector<Route> skylineRoutes = skyline->getSkylineRoutes();
	//��·���е����ݵ����ѡ�н�㼯�����ٱ߼���ѡ�б߼�
	for each(Route route in skylineRoutes)
	{
		routesIndexes.push_back(QVector<int>());
		for each(Point p in route.points)
		{
			Node node = { p.x,p.y };
			int u = caMap[p.edgeIndex].u;
			int v = caMap[p.edgeIndex].v;
			int nodeIndex = nodes.size() + pointsCount;
			selectedNodes[nodeIndex] = node;
			simpleEdges.push_back({ u,nodeIndex });
			simpleEdges.push_back({ nodeIndex,v });
			simpleEdges.push_back({ nodeIndex,u });
			simpleEdges.push_back({ v,nodeIndex });
			routesIndexes[routesIndexes.size() - 1].push_back(nodeIndex);
			++pointsCount;
		}
	}

	//Dijkstra
	Dijkstra *dijkstra = new Dijkstra(simpleEdges, selectedNodes, routesIndexes);
	QVector<QVector<Node>> optimalRoutes = dijkstra->getOptimalRoutes();

	//����Voronoiͼ
	mapArea->setVoronoi(voronoi->getVoronois());

	//����·��
	mapArea->setRoute(optimalRoutes, skylineRoutes);

	//����·�������ť
	setResultButton(true);
}

void MainWindow::drawVoronoiGraph()
{
	//��ʾVoronoiͼ
	mapArea->setVoronoi(0, 0);

	//����Voronoiͼ�����ť
	setResultButton(false);
}

void MainWindow::mapZoomIn()
{
	mapArea->mapZoomIn();
}

void MainWindow::mapZoomOut()
{
	mapArea->mapZoomOut();
}

void MainWindow::setResultButton(const bool isRoute)
{
	//��ս����ť
	for each(ResultButton *button in resultButtons)
	{
		if (button != nullptr)
		{
			delete button;
			button = nullptr;
		}
	}
	resultButtons.clear();

	//�������ɰ�ť
	QString buttonText;
	int size;
	if (isRoute)
	{
		buttonText = QString::fromLocal8Bit("·��");
		size = mapArea->getRouteSize();
	}
	else
	{
		buttonText = "Voronoi ";
		size = mapArea->getVoronoisSize();
	}
	for (int i = 0; i < size; ++i)
	{
		//��ʼ����ť
		ResultButton *button = new ResultButton(i,
			buttonText + QString::number(i + 1),
			ui.scrollAreaWidgetContents);

		//���ð�ť��Ӱ
		QGraphicsDropShadowEffect *buttonEffect = 
			new QGraphicsDropShadowEffect(ui.scrollAreaWidgetContents);
		buttonEffect->setColor(QColor("#cccccc"));
		buttonEffect->setOffset(0, 0);
		buttonEffect->setBlurRadius(5);
		button->setGraphicsEffect(buttonEffect);

		if (isRoute)
		{
			//��ʾ·��
			connect(button->getButton(), SIGNAL(clicked()), this, SLOT(setRouteIndex()));
		}
		else
		{
			//��ʾVoronoiͼ
			connect(button->getButton(), SIGNAL(clicked()), this, SLOT(setVoronoiIndex()));
		}
		button->show();
		resultButtons.push_back(button);
	}
	ui.noInfomationLabel->hide();
}

void MainWindow::setRouteIndex()
{
	int index = ((ResultButton*)((QPushButton*)sender())->parent())->getIndex();
	mapArea->setRoute(index);
}

void MainWindow::setVoronoiIndex()
{
	int index = ((ResultButton*)((QPushButton*)sender())->parent())->getIndex();
	int routeIndex = index / mapArea->getVoronoiSize();
	int voronoiIndex = index%mapArea->getVoronoiSize();
	mapArea->setVoronoi(routeIndex, voronoiIndex);
}