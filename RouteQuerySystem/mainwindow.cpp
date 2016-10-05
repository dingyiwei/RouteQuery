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

	//设置窗口无边框
	setWindowFlags(Qt::FramelessWindowHint);

	//读取地图数据
	DataProcessor *dp = new DataProcessor();
	nodes = dp->getNodes();
	points = dp->getPoints();
	caMap = dp->getMap();
	regions = dp->getRegions();
	delete dp;

	//初始化展示区
	mapArea = new MapArea(&nodes, &points, &caMap, this);
	mapArea->move(0, 50);

	//设置展示区阴影
	QGraphicsDropShadowEffect *graphicEffect = new QGraphicsDropShadowEffect(this);
	graphicEffect->setOffset(0, 0);
	graphicEffect->setColor(QColor("#bbbbbb"));
	graphicEffect->setBlurRadius(10);
	mapArea->setGraphicsEffect(graphicEffect);

	//初始化缩放按钮组
	zoomButtons = new ZoomButtons(this);
	zoomButtons->move(20, 70);

	//设置缩放按钮组阴影
	QGraphicsDropShadowEffect *zoomButtonsEffect = new QGraphicsDropShadowEffect(this);
	zoomButtonsEffect->setOffset(0, 0);
	zoomButtonsEffect->setColor(QColor("#bbbbbb"));
	zoomButtonsEffect->setBlurRadius(10);
	zoomButtons->setGraphicsEffect(zoomButtonsEffect);

	//初始化遮罩
	mask = new QWidget(this);
	mask->setStyleSheet("background-color:black");
	mask->resize(this->size());

	//初始化导航栏
	navigationBar = new NavigationBar(this);
	navigationBar->move(-270, 0);
	navigationBar->show();

	//初始化菜单按钮
	menuButton = new MenuButton(this);

	//初始化关闭按钮
	closeButton = new CloseButton(this);
	closeButton->move(750, 0);
	//关闭窗口
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

	//初始化帮助按钮
	helpButton = new HelpButton(this);
	helpButton->move(700, 0);

	//设置标题栏阴影
	QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
	effect->setOffset(0, 2);
	effect->setColor(Qt::gray);
	effect->setBlurRadius(10);
	ui.menubar->setGraphicsEffect(effect);

	//设置导航栏阴影
	QGraphicsDropShadowEffect *navigationBarEffect = new QGraphicsDropShadowEffect(this);
	navigationBarEffect->setOffset(2, 0);
	navigationBarEffect->setColor(QColor("#444444"));
	navigationBarEffect->setBlurRadius(10);
	navigationBar->setGraphicsEffect(navigationBarEffect);

	//设置遮罩透明度
	maskEffect = new QGraphicsOpacityEffect(this);
	maskEffect->setOpacity(0);
 	mask->setGraphicsEffect(maskEffect);
	mask->hide();

	//设置导航栏动画
	timeLine = new QTimeLine(500, this);
	timeLine->setFrameRange(-270, 0);
	timeLine->setCurveShape(QTimeLine::EaseInOutCurve);
	//导航栏弹出
	connect(timeLine, SIGNAL(frameChanged(int)), this, 
		SLOT(moveNavigationBar(int)));
	connect(menuButton, SIGNAL(clicked()), this, SLOT(openNavigation()));

	//初始化输入对话框
	inputDialog = new InputDialog(&nodes);
	//偏好设置
	connect(navigationBar->getPreferenceSettingButton(), SIGNAL(clicked()),
		inputDialog, SLOT(exec()));
	//确认输入
	connect(inputDialog->getConfirmButton(), SIGNAL(clicked()), this, 
		SLOT(displayRoute()));

	//Voronoi图
	connect(navigationBar->getVoronoiButton(), SIGNAL(clicked()), this,
		SLOT(drawVoronoiGraph()));
	//查看结果
	connect(navigationBar->getResultButton(), SIGNAL(clicked()), this,
		SLOT(displayRoute()));

	//放大
	connect(zoomButtons->getZoomInButton(), SIGNAL(clicked()), this,
		SLOT(mapZoomIn()));
	//缩小
	connect(zoomButtons->getZoomOutButton(), SIGNAL(clicked()), this,
		SLOT(mapZoomOut()));

	//初始化帮助对话框
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

	//获得起点
	Point start;
	start.x = inputDialog->getStartX();
	start.y = inputDialog->getStartY();
	start.category = -1;
	int startNodeIndex = inputDialog->getStartNodeIndex();

	//获得偏好
	int preference = inputDialog->getPreference();

	//获得起点所在区域
	double rowDistance = (TOP - BOTTOM) / ROW;
	double colDistance = (RIGHT - LEFT) / COL;
	int rowRegion = (int)((start.x - LEFT) / colDistance);
	int colRegion = (int)((TOP - start.y) / rowDistance);
	start.regionIndex = rowRegion*ROW + colRegion;

	//获得类型序列
	QVector<int> categorySquence = inputDialog->getCategorySequence();

	//获得区域内数据点
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

	//获得区域内边、结点
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

	//Voronoi图
	voronoi = new Voronoi(partOfMap, categorySquence, start);

	//skyline查询
	skyline = new Skyline(voronoi->getRoutes(), preference);

	//获得最优路径
	QVector<QVector<int>> routesIndexes;
	int pointsCount = 0;
	QVector<Route> skylineRoutes = skyline->getSkylineRoutes();
	//将路径中的数据点加入选中结点集，其临边加入选中边集
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

	//设置Voronoi图
	mapArea->setVoronoi(voronoi->getVoronois());

	//设置路径
	mapArea->setRoute(optimalRoutes, skylineRoutes);

	//设置路径结果按钮
	setResultButton(true);
}

void MainWindow::drawVoronoiGraph()
{
	//显示Voronoi图
	mapArea->setVoronoi(0, 0);

	//设置Voronoi图结果按钮
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
	//清空结果按钮
	for each(ResultButton *button in resultButtons)
	{
		if (button != nullptr)
		{
			delete button;
			button = nullptr;
		}
	}
	resultButtons.clear();

	//重新生成按钮
	QString buttonText;
	int size;
	if (isRoute)
	{
		buttonText = QString::fromLocal8Bit("路径");
		size = mapArea->getRouteSize();
	}
	else
	{
		buttonText = "Voronoi ";
		size = mapArea->getVoronoisSize();
	}
	for (int i = 0; i < size; ++i)
	{
		//初始化按钮
		ResultButton *button = new ResultButton(i,
			buttonText + QString::number(i + 1),
			ui.scrollAreaWidgetContents);

		//设置按钮阴影
		QGraphicsDropShadowEffect *buttonEffect = 
			new QGraphicsDropShadowEffect(ui.scrollAreaWidgetContents);
		buttonEffect->setColor(QColor("#cccccc"));
		buttonEffect->setOffset(0, 0);
		buttonEffect->setBlurRadius(5);
		button->setGraphicsEffect(buttonEffect);

		if (isRoute)
		{
			//显示路径
			connect(button->getButton(), SIGNAL(clicked()), this, SLOT(setRouteIndex()));
		}
		else
		{
			//显示Voronoi图
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