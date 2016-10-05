//类型定义

#pragma once

#include <QVector>

#include <CGAL/Apollonius_graph_filtered_traits_2.h>
#include <CGAL/Apollonius_graph_2.h>
#include <CGAL/Simple_cartesian.h>

//CGAL库相关定义
typedef CGAL::Simple_cartesian<double> Kernel;
typedef CGAL::Apollonius_graph_filtered_traits_2<Kernel,
	CGAL::Integral_domain_without_division_tag> Gt;
typedef CGAL::Apollonius_graph_2<Gt> Apollonius;
typedef Apollonius::Site_2 Site_2;
typedef Apollonius::Point_2 Point_2;

//数据点属性数
const int NUM_OF_POINT_ATTRIBUTE = 4;

//结点
//x:结点横坐标（经度）
//y:结点纵坐标（纬度）
struct Node
{
	double x;
	double y;
};

//数据点
//category:数据点类型
//x:数据点横坐标（经度）
//y:数据点纵坐标（纬度）
//edgeIndex:所在边的序号
//regionIndex:所在区域序号
//weight:数据点权重
class Point
{
public:
	int category;
	double x;
	double y;
	int edgeIndex;
	int regionIndex;
	double weight[NUM_OF_POINT_ATTRIBUTE];

	bool operator==(const Point &other)
	{
		return abs(x - other.x) < 0.00001&&abs(y - other.y) < 0.00001;
	}
	bool operator!=(const Point &other)
	{
		return abs(x - other.x) > 0.00001 || abs(y - other.y) > 0.00001;
	}
};

//简化边
//u:端点1（结点）序号
//v:端点2（结点）序号
struct SimpleEdge
{
	int u;
	int v;
};

//边
//u:端点1（结点）序号
//v:端点2（结点）序号
//regionIndex:所在区域序号
//points:边上数据点序号
struct Edge
{
	int u;
	int v;
	int regionIndex;
	QVector<int> points;
};

//类型序列
using CategorySequence = QVector<int>;

//路径
//points:路径经过的数据点
//weight:路径权重，用于skyline查询
class Route
{
public:
	QVector<Point> points;
	double weight[NUM_OF_POINT_ATTRIBUTE];
};

//地图
using Map = QVector<Edge>;

//区域最西经度（图中最左）
const double LEFT = -125;

//区域最东经度（图中最右）
const double RIGHT = -114;

//区域最北纬度（图中最上）
const double TOP = 42;

//区域最南纬度（图中最下）
const double BOTTOM = -125;

//区域行数
const int ROW = 2;

//区域列数
const int COL = 1;