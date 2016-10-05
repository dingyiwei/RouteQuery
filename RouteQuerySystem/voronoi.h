//Voronoi图

#pragma once

#include "definition.h"

#include <QMap>

//Voronoi图
class Voronoi
{
public:
	//QMap<int,QVecto<Point>> map:以类型为索引的数据点集
	//CategorySequence cateSq:类型序列
	//Point start:起点
	Voronoi(const QMap<int, QVector<Point>> &map, const CategorySequence &cateSq,
		const Point &start);

	//获得单个路径的Voronoi图
	//int index:路径序号
	QVector<Apollonius> getVoronoi(const int index) const;

	//获得Voronoi图集
	QVector<QVector<Apollonius>> getVoronois() const;

	//获得单个路径
	//int index:路径序号
	Route getRoute(const int index) const;

	//获得路径集
	QVector<Route> getRoutes() const;

private:
	//建立第一个Voronoi图
	//int index:路径序号
	//QVector<Point> points:相应的数据点集
	void buildFirstGraph(const int index, const QVector<Point> &points);

	//建立其他Voronoi图
	//int index:路径序号
	//QVector<Point> points:相应的数据点集
	void buildOtherGraph(const int index, const QVector<Point> &points);

	//裁剪相同路径
	void prune();

	//Voronoi图集
	QVector<QVector<Apollonius>> ags;

	//路径集
	QVector<Route> routes;

	//加权比例
	const double RATIO = 0.8;
};