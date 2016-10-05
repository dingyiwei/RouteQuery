//���Ͷ���

#pragma once

#include <QVector>

#include <CGAL/Apollonius_graph_filtered_traits_2.h>
#include <CGAL/Apollonius_graph_2.h>
#include <CGAL/Simple_cartesian.h>

//CGAL����ض���
typedef CGAL::Simple_cartesian<double> Kernel;
typedef CGAL::Apollonius_graph_filtered_traits_2<Kernel,
	CGAL::Integral_domain_without_division_tag> Gt;
typedef CGAL::Apollonius_graph_2<Gt> Apollonius;
typedef Apollonius::Site_2 Site_2;
typedef Apollonius::Point_2 Point_2;

//���ݵ�������
const int NUM_OF_POINT_ATTRIBUTE = 4;

//���
//x:�������꣨���ȣ�
//y:��������꣨γ�ȣ�
struct Node
{
	double x;
	double y;
};

//���ݵ�
//category:���ݵ�����
//x:���ݵ�����꣨���ȣ�
//y:���ݵ������꣨γ�ȣ�
//edgeIndex:���ڱߵ����
//regionIndex:�����������
//weight:���ݵ�Ȩ��
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

//�򻯱�
//u:�˵�1����㣩���
//v:�˵�2����㣩���
struct SimpleEdge
{
	int u;
	int v;
};

//��
//u:�˵�1����㣩���
//v:�˵�2����㣩���
//regionIndex:�����������
//points:�������ݵ����
struct Edge
{
	int u;
	int v;
	int regionIndex;
	QVector<int> points;
};

//��������
using CategorySequence = QVector<int>;

//·��
//points:·�����������ݵ�
//weight:·��Ȩ�أ�����skyline��ѯ
class Route
{
public:
	QVector<Point> points;
	double weight[NUM_OF_POINT_ATTRIBUTE];
};

//��ͼ
using Map = QVector<Edge>;

//�����������ȣ�ͼ������
const double LEFT = -125;

//��������ȣ�ͼ�����ң�
const double RIGHT = -114;

//�����γ�ȣ�ͼ�����ϣ�
const double TOP = 42;

//��������γ�ȣ�ͼ�����£�
const double BOTTOM = -125;

//��������
const int ROW = 2;

//��������
const int COL = 1;