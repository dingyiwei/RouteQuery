//数据接口

#pragma once

#include "definition.h"

//数据接口
class DataProcessor
{
public:
	DataProcessor();

	//获得结点集
	QVector<Node> getNodes() const;

	//获得数据点集
	QVector<Point> getPoints() const;

	//获得边集，即地图
	Map getMap() const;

	//获得以区域为索引的结点序号
	QVector<QVector<int>> getRegions() const;

private:
	//结点
	QVector<Node> nodes;

	//数据点
	QVector<Point> points;

	//边集，即地图
	Map map;

	//以区域为索引的结点序号
	QVector<QVector<int>> regions;

};