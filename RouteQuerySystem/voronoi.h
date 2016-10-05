//Voronoiͼ

#pragma once

#include "definition.h"

#include <QMap>

//Voronoiͼ
class Voronoi
{
public:
	//QMap<int,QVecto<Point>> map:������Ϊ���������ݵ㼯
	//CategorySequence cateSq:��������
	//Point start:���
	Voronoi(const QMap<int, QVector<Point>> &map, const CategorySequence &cateSq,
		const Point &start);

	//��õ���·����Voronoiͼ
	//int index:·�����
	QVector<Apollonius> getVoronoi(const int index) const;

	//���Voronoiͼ��
	QVector<QVector<Apollonius>> getVoronois() const;

	//��õ���·��
	//int index:·�����
	Route getRoute(const int index) const;

	//���·����
	QVector<Route> getRoutes() const;

private:
	//������һ��Voronoiͼ
	//int index:·�����
	//QVector<Point> points:��Ӧ�����ݵ㼯
	void buildFirstGraph(const int index, const QVector<Point> &points);

	//��������Voronoiͼ
	//int index:·�����
	//QVector<Point> points:��Ӧ�����ݵ㼯
	void buildOtherGraph(const int index, const QVector<Point> &points);

	//�ü���ͬ·��
	void prune();

	//Voronoiͼ��
	QVector<QVector<Apollonius>> ags;

	//·����
	QVector<Route> routes;

	//��Ȩ����
	const double RATIO = 0.8;
};