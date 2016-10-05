//优先队列Dijkstra

#pragma once

#include "definition.h"
#include <QMap>

//优先队列Dijkstra
class Dijkstra
{
private:
	//优先队列中的元素
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
	//QVector<SimpleEdge> edges:边集
	//QMap<int,Node> nodes:结点集（以边的端点序号为索引）
	//QVector<QVector<int>> routes:路径集，包含若干路径，每条路径由nodes中的索引组成
	Dijkstra(const QVector<SimpleEdge> &edges, const QMap<int, Node> &nodes,
		const QVector<QVector<int>> &routes);

	//获得最短路径集
	QVector<QVector<Node>> getOptimalRoutes() const;

private:
	//初始化有向图
	void initGraph();

	//以起点序号和终点序号查询最短路径
	//int sourceNode:起点序号
	//int targetNode:终点序号
	QVector<Node> query(int sourceNode, int targetNode);

	//最短路径集
	QVector<QVector<Node>> optimalRoutes;

	//边集
	QVector<SimpleEdge> edges;

	//结点集
	QMap<int, Node> nodes;

	//邻接表链表
	QMap<int, int> head;
	QVector<int> nextv;
	QVector<int> tail;
	QVector<double> val;

	//起点到各点的最短距离
	QMap<int, double> dis;
};