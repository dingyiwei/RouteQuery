#include "voronoi.h"
#include <QMessageBox>
#include <omp.h>

Voronoi::Voronoi(const QMap<int, QVector<Point>> &map, const CategorySequence &cateSq,
	const Point &start)
{
	if (cateSq.size() == 0)
	{
		return;
	}

	ags.resize(NUM_OF_POINT_ATTRIBUTE);
	routes.resize(NUM_OF_POINT_ATTRIBUTE);

	m_map = map;
	m_cateSq = cateSq;
	m_start = start;
	
}

void Voronoi::operate()
{
#pragma omp parallel for
	for (int i = 0; i < NUM_OF_POINT_ATTRIBUTE; ++i)
	{
		buildGraph(i);
	}

	prune();
}

QVector<Apollonius> Voronoi::getVoronoi(const int index) const
{
	return ags[index];
}

QVector<QVector<Apollonius>> Voronoi::getVoronois() const
{
	return ags;
}

Route Voronoi::getRoute(const int index) const
{
	return routes[index];
}

QVector<Route> Voronoi::getRoutes() const
{
	return routes;
}

void Voronoi::buildGraph(const int index)
{
	buildFirstGraph(index, m_map[m_cateSq[m_cateSq.size() - 1]]);

	for (int j = m_cateSq.size() - 2; j >= 0; --j)
	{
		buildOtherGraph(index, m_map[m_cateSq[j]]);
	}

	Point lastPoint = m_start;
	routes[index].points.push_back(m_start);
	for (int j = 0; j < NUM_OF_POINT_ATTRIBUTE; ++j)
	{
		lastPoint.weight[j] = 0;
	}
	for (int j = 0; j < ags[index].size(); ++j)
	{
		Apollonius::Vertex_handle vertex =
			ags[index][j].nearest_neighbor(Point_2(lastPoint.x, lastPoint.y));
		double x = vertex->site().x();
		double y = vertex->site().y();
		for each(Point p in m_map[m_cateSq[j]])
		{
			if (abs(p.x - x) < 0.0001 && abs(p.y - y) < 0.0001)
			{
				lastPoint = p;
				break;
			}
		}
		routes[index].points.push_back(lastPoint);
	}
}

void Voronoi::buildFirstGraph(const int index, const QVector<Point> &points)
{
	Apollonius ag;
	for each(Point p in points)
	{
		ag.insert(Site_2(Point_2(p.x, p.y), p.weight[index]));
	}
	ags[index].push_front(ag);
}

void Voronoi::buildOtherGraph(const int index, const QVector<Point> &points)
{
	Apollonius ag;
	for each(Point p in points)
	{
		Point_2 point_2(p.x, p.y);
		Apollonius::Vertex_handle vertex = ags[index][0].nearest_neighbor(point_2);
		ag.insert(Site_2(point_2, p.weight[index] * (2 - RATIO) +
			vertex->site().weight()*RATIO));
	}
	ags[index].push_front(ag);
}

void Voronoi::prune()
{
	bool isToPrune[NUM_OF_POINT_ATTRIBUTE] = { false };
	for (int i = 0; i < routes.size(); ++i)
	{
		for (int j = i + 1; j < routes.size(); ++j)
		{
			bool flag = false;
			for (int k = 0; k < routes[0].points.size(); ++k)
			{
				if (routes[i].points[k] != routes[j].points[k])
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				isToPrune[i] = true;
				break;
			}
		}
	}
	for (int i = NUM_OF_POINT_ATTRIBUTE - 1; i >= 0; --i)
	{
		if (isToPrune[i])
		{
			routes.remove(i);
			ags.remove(i);
		}
	}
}