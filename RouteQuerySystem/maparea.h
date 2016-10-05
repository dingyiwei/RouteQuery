//��ͼ��·����Voronoiͼչʾ��

#pragma once

#include "definition.h"
#include "ui_maparea.h"

#include <QGraphicsScene>
#include <QPainterPath>
#include <QGraphicsPathItem>
#include <QGraphicsItemGroup>
#include <CGAL/Qt/ApolloniusGraphGraphicsItem.h>

//��ͼ��·����Voronoiͼչʾ��
class MapArea :public QWidget
{
public:
	//QVector<Node> *nodes:��㼯ָ��
	//QVector<Point> *points:���ݵ㼯ָ��
	//Map *caMap:��ͼ���߼���ָ��
	MapArea(QVector<Node> *nodes, QVector<Point> *points, Map *caMap,
		QWidget *parent = nullptr);

	//�����µ�Voronoiͼ
	//QVector<QVector<Apollonius>> ags:Voronoiͼ��
	void setVoronoi(const QVector<QVector<Apollonius>> &ags);

	//����Voronoiͼ������չʾ
	//routeIndex:·�����
	//index:�������
	void setVoronoi(const int routeIndex, const int index);

	//�����µ�·��
	//QVector<QVector<Node>> routes:����Dijsktra���������·����
	//QVector<Route> routePoints:����skyline����������·����
	void setRoute(const QVector<QVector<Node>> &routes,
		const QVector<Route> &routePoints);

	//����·��
	//int routeIndex:·�����
	void setRoute(const int routeIndex);

	//���·����
	int getRouteSize() const;

	//���·���е��������
	int getVoronoiSize() const;

	//���Voronoiͼ��
	int getVoronoisSize() const;

	public slots:
	//�Ŵ��ͼ
	void mapZoomIn();

	//��С��ͼ
	void mapZoomOut();

private:
	//���Ƶ�ͼ
	void drawMap();

	//���õ�ͼ����
	void translate();

	Ui::MapAreaClass ui;

	//��㼯ָ��
	QVector<Node> *nodes;

	//���ݵ㼯ָ��
	QVector<Point> *points;

	//��ͼ���߼���ָ��
	Map *caMap;

	//����
	QGraphicsScene *scene;

	//��ͼ
	QPainterPath mapPath;
	//��ͼitem
	QGraphicsPathItem *pathItem;

	//��ͼ����
	double scale;

	//��ͼ��������
	const double SCALE_INCREMENT = 1.1;

	//Voronoiͼ��
	QVector<QVector<Apollonius>> ags;

	//����Dijkstra���������·������㣩��
	QVector<QVector<Node>> routes;

	//����skyline��ѯ�������·�������ݵ㣩��
	QVector<Route> routePoints;

	//���ݵ�ͼ��
	QGraphicsItemGroup *pointItemGroup;

	//�Ƿ�Ϊ�µ�Voronoiͼ
	bool isNewVoronoi = true;

	//Voronoiͼitem
	CGAL::Qt::ApolloniusGraphGraphicsItem<Apollonius, Kernel> *agi = nullptr;

	//·��item
	QGraphicsPathItem *routeItem = nullptr;
};