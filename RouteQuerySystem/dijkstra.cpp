#include "dijkstra.h"
#include <queue>
#include <fstream>

Dijkstra::Dijkstra(const QVector<SimpleEdge> &edges, const QMap<int, Node> &nodes, 
	const QVector<QVector<int>> &routes)
{
	this->edges = edges;
	this->nodes = nodes;

	nextv.insert(nextv.begin(), edges.size() + 1, -1);
	tail.insert(tail.begin(), edges.size() + 1, -1);
	val.insert(val.begin(), edges.size() + 1, -1);

	for (QMap<int, Node>::const_iterator it(nodes.begin()); it != nodes.end(); ++it)
	{
		head[it.key()] = 0;
	}
	initGraph();
	optimalRoutes.resize(routes.size());

	//°´ÕÕÂ·¾¶Ë³ÐòÑ°ÕÒ×î¶ÌÂ·¾¶
	for (int i = 0; i < routes.size(); ++i)
	{
		for (int j = 0; j < routes[i].size() - 1; ++j)
		{
			optimalRoutes[i].append(query(routes[i][j], routes[i][j + 1]));
		}
	}
}

QVector<QVector<Node>> Dijkstra::getOptimalRoutes() const
{
	return optimalRoutes;
}

void Dijkstra::initGraph()
{
	for (int i = 0; i < edges.size(); ++i)
	{
		int size = i + 1;
		int u = edges[i].u;
		int v = edges[i].v;
		nextv[size] = head[u];
		head[u] = size;
		tail[size] = v;
//		dis[v] = INT_MAX;
		val[size] = sqrt(pow(nodes[u].x - nodes[v].x, 2) + 
			pow(nodes[u].y - nodes[v].y, 2));
	}
}

QVector<Node> Dijkstra::query(int sourceNode, int targetNode)
{
	std::priority_queue<QueueElement> priorityQueue;
	priorityQueue.push({ sourceNode,0 });
	QMap<int, int> prev;

	for (QMap<int, Node>::iterator it(nodes.begin()); it != nodes.end(); ++it)
	{
		dis[it.key()] = INT_MAX;
	}
	dis[sourceNode] = 0;
	while (!priorityQueue.empty())
	{
		QueueElement topElement = priorityQueue.top();
		priorityQueue.pop();
		if (topElement.y > dis[topElement.x])
		{
			continue;
		}
		for (int i = head[topElement.x]; i != 0; i = nextv[i])
		{
			int j = tail[i];
			if (dis[j] > dis[topElement.x] + val[i])
			{
				dis[j] = dis[topElement.x] + val[i];
				priorityQueue.push({ j,dis[j] });
				prev[j] = topElement.x;
			}
		}
	}
	QVector<Node> subRoute;
	int k = targetNode;
	while (k != sourceNode)
	{
		subRoute.push_front(nodes[k]);
		k = prev[k];
		if (k == 0)
		{
			break;
		}
	}

	return subRoute;
}