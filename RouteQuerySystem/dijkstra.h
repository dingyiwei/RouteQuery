//���ȶ���Dijkstra

#pragma once

#include "definition.h"
#include <QMap>

//���ȶ���Dijkstra
class Dijkstra
{
private:
	//���ȶ����е�Ԫ��
	class QueueElement
	{
	public:
		int x;
		double y;
		bool operator<(const QueueElement &other) const
		{
			return y > other.y;
		}
	};

public:
	//QVector<SimpleEdge> edges:�߼�
	//QMap<int,Node> nodes:��㼯���ԱߵĶ˵����Ϊ������
	//QVector<QVector<int>> routes:·��������������·����ÿ��·����nodes�е��������
	Dijkstra(const QVector<SimpleEdge> &edges, const QMap<int, Node> &nodes,
		const QVector<QVector<int>> &routes);

	//������·����
	QVector<QVector<Node>> getOptimalRoutes() const;

private:
	//��ʼ������ͼ
	void initGraph();

	//�������ź��յ���Ų�ѯ���·��
	//int sourceNode:������
	//int targetNode:�յ����
	QVector<Node> query(int sourceNode, int targetNode);

	//���·����
	QVector<QVector<Node>> optimalRoutes;

	//�߼�
	QVector<SimpleEdge> edges;

	//��㼯
	QMap<int, Node> nodes;

	//�ڽӱ�����
	QMap<int, int> head;
	QVector<int> nextv;
	QVector<int> tail;
	QVector<double> val;

	//��㵽�������̾���
	QMap<int, double> dis;
};