#include "maparea.h"
#include <QGraphicsScene>
#include <QPainterPath>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>

MapArea::MapArea(QVector<Node> *nodes, QVector<Point> *points, Map *caMap,
	QWidget *parent /* = nullptr */) :QWidget(parent)
{
	ui.setupUi(this);

	//初始化比例
	scale = 100;

	//初始化画布
	scene = new QGraphicsScene();
	ui.graphicsView->setScene(scene);

	//绘制地图
	this->nodes = nodes;
	this->points = points;
	this->caMap = caMap;
	drawMap();

	//初始化路径item
	routeItem = new QGraphicsPathItem();
	scene->addItem(routeItem);

	//初始化Voronoi图item
	agi = nullptr;

	//初始化数据点图标组
	pointItemGroup = new QGraphicsItemGroup();
	scene->addItem(pointItemGroup);
}

void MapArea::drawMap()
{
	if (nodes == nullptr || points == nullptr || caMap == nullptr)
	{
		return;
	}
	for each(Edge e in *caMap)
	{
		double x1 = (*nodes)[e.u].x;
		double y1 = (*nodes)[e.u].y;
		double x2 = (*nodes)[e.v].x;
		double y2 = (*nodes)[e.v].y;
		mapPath.moveTo(x1, y1);
		mapPath.lineTo(x2, y2);
	}
	pathItem = new QGraphicsPathItem(mapPath);
	pathItem->setPen(QPen(QBrush(Qt::black), 1/scale));
	scene->addItem(pathItem);
	ui.graphicsView->scale(scale, -scale);
}

void MapArea::setVoronoi(const QVector<QVector<Apollonius>> &ags)
{
	this->ags = ags;
	isNewVoronoi = true;
}

void MapArea::setVoronoi(const int routeIndex, const int index)
{
	routeItem->hide();
	if (!isNewVoronoi)
	{
		scene->removeItem(agi);
		isNewVoronoi = false;
	}
	if (agi != nullptr)
	{
		delete agi;
		agi = nullptr;
	}
	agi = new CGAL::Qt::ApolloniusGraphGraphicsItem<Apollonius, Kernel>
		(&ags[routeIndex][index]);
	agi->setEdgesPen(QPen(QBrush(Qt::blue), 1 / scale));
	agi->setSitesPen(QPen(QBrush(Qt::red), 1 / scale));
	scene->addItem(agi);
}

void MapArea::setRoute(const QVector<QVector<Node>> &routes, 
	const QVector<Route> &routePoints)
{
	this->routes = routes;
	this->routePoints = routePoints;
	setRoute(0);
}

void MapArea::setRoute(const int routeIndex)
{
	if (agi != nullptr)
	{
		agi->hide();
	}
	for each(QGraphicsEllipseItem *item in pointItemGroup->childItems())
	{
		pointItemGroup->removeFromGroup(item);
		delete item;
		item = nullptr;
	}
	QPainterPath routePath;
	routePath.moveTo(routes[routeIndex][0].x, routes[routeIndex][0].y);
	for each(Node node in routes[routeIndex])
	{
		routePath.lineTo(node.x, node.y);
	}

	for each(Point p in routePoints[routeIndex].points)
	{
		QString iconName = ":/MapArea/icons/" + QString::number(p.category) + ".png";
		QGraphicsPixmapItem *pointItem = new QGraphicsPixmapItem(QPixmap(iconName));
		pointItem->setScale(1 / scale);
		pointItem->setPos(p.x, p.y);
		pointItem->setOffset(-16, -37);
		pointItem->setRotation(180);
		pointItemGroup->addToGroup(pointItem);
	}
	routeItem->show();
	routeItem->setPath(routePath);
	routeItem->setPen(QPen(QBrush(Qt::green), 3 / scale));
}

void MapArea::mapZoomIn()
{
	scale *= SCALE_INCREMENT;
	ui.graphicsView->scale(SCALE_INCREMENT, SCALE_INCREMENT);
	translate();
}

void MapArea::mapZoomOut()
{
	scale /= SCALE_INCREMENT;
	ui.graphicsView->scale(1 / SCALE_INCREMENT, 1 / SCALE_INCREMENT);
	translate();
}

void MapArea::translate()
{
	pathItem->setPen(QPen(QBrush(Qt::black), 1 / scale));
	if (routeItem != nullptr)
	{
		routeItem->setPen(QPen(QBrush(Qt::green), 3 / scale));
	}
	if (agi != nullptr)
	{
		agi->setEdgesPen(QPen(QBrush(Qt::blue), 1 / scale));
		agi->setSitesPen(QPen(QBrush(Qt::red), 1 / scale));
	}
	for each(QGraphicsPixmapItem *item in pointItemGroup->childItems())
	{
		item->setScale(1 / scale);
	}
}

int MapArea::getRouteSize() const
{
	return routes.size();
}

int MapArea::getVoronoiSize() const
{
	return ags[0].size();
}

int MapArea::getVoronoisSize() const
{
	return ags.size()*ags[0].size();
}