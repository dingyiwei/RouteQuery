//地图、路径、Voronoi图展示区

#pragma once

#include "definition.h"
#include "ui_maparea.h"

#include <QGraphicsScene>
#include <QPainterPath>
#include <QGraphicsPathItem>
#include <QGraphicsItemGroup>
#include <CGAL/Qt/ApolloniusGraphGraphicsItem.h>

//地图、路径、Voronoi图展示区
class MapArea :public QWidget
{
public:
	//QVector<Node> *nodes:结点集指针
	//QVector<Point> *points:数据点集指针
	//Map *caMap:地图（边集）指针
	MapArea(QVector<Node> *nodes, QVector<Point> *points, Map *caMap,
		QWidget *parent = nullptr);

	//设置新的Voronoi图
	//QVector<QVector<Apollonius>> ags:Voronoi图集
	void setVoronoi(const QVector<QVector<Apollonius>> &ags);

	//设置Voronoi图，用于展示
	//routeIndex:路径序号
	//index:类型序号
	void setVoronoi(const int routeIndex, const int index);

	//设置新的路径
	//QVector<QVector<Node>> routes:经过Dijsktra计算后的最短路径集
	//QVector<Route> routePoints:经过skyline计算后的最优路径集
	void setRoute(const QVector<QVector<Node>> &routes,
		const QVector<Route> &routePoints);

	//设置路径
	//int routeIndex:路径序号
	void setRoute(const int routeIndex);

	//获得路径数
	int getRouteSize() const;

	//获得路径中点的类型数
	int getVoronoiSize() const;

	//获得Voronoi图数
	int getVoronoisSize() const;

	public slots:
	//放大地图
	void mapZoomIn();

	//缩小地图
	void mapZoomOut();

private:
	//绘制地图
	void drawMap();

	//设置地图比例
	void translate();

	Ui::MapAreaClass ui;

	//结点集指针
	QVector<Node> *nodes;

	//数据点集指针
	QVector<Point> *points;

	//地图（边集）指针
	Map *caMap;

	//画布
	QGraphicsScene *scene;

	//地图
	QPainterPath mapPath;
	//地图item
	QGraphicsPathItem *pathItem;

	//地图比例
	double scale;

	//地图缩放增量
	const double SCALE_INCREMENT = 1.1;

	//Voronoi图集
	QVector<QVector<Apollonius>> ags;

	//经过Dijkstra计算后的最短路径（结点）集
	QVector<QVector<Node>> routes;

	//经过skyline查询后的最优路径（数据点）集
	QVector<Route> routePoints;

	//数据点图标
	QGraphicsItemGroup *pointItemGroup;

	//是否为新的Voronoi图
	bool isNewVoronoi = true;

	//Voronoi图item
	CGAL::Qt::ApolloniusGraphGraphicsItem<Apollonius, Kernel> *agi = nullptr;

	//路径item
	QGraphicsPathItem *routeItem = nullptr;
};