#include "skyline.h"
#include <set>
#include <algorithm>

Skyline::Skyline(QVector<Route> &routes, const int preference)
{
	this->preference = preference;

	initWeight(routes);

	prune(routes);

	sort();
}

void Skyline::initWeight(QVector<Route> &routes)
{
	for (int i = 0; i < routes.size(); ++i)
	{
		for each(Point p in routes[i].points)
		{
			for (int j = 0; j < NUM_OF_POINT_ATTRIBUTE; ++j)
			{
				routes[i].weight[j] += p.weight[j];
			}
		}
	}
}

void Skyline::prune(QVector<Route> &routes)
{
	int *judge = new int[routes.size()];

	for (int i = 0; i < routes.size(); ++i)
	{
		judge[i] = 0;
		for each(Route _route in routes)
		{
			int dominate = 0, dominated = 0;
			for (int j = 0; j < NUM_OF_POINT_ATTRIBUTE; ++j)
			{
				if (routes[i].weight[j] < _route.weight[j])
				{
					++dominated;
				}
				else if (routes[i].weight[j] > _route.weight[j])
				{
					++dominate;
				}
			}
			if (dominate > 0 && dominated == 0)
			{
				++judge[i];
			}
		}
	}

	for (int i = 0; i < routes.size(); i++)
	{
		if (judge[i] == 0)
		{
			skylineRoutes.push_back(routes[i]);
		}
	}
}

void Skyline::sort()
{
	QVector<Route> temp = skylineRoutes;
	skylineRoutes.clear();

	while (!temp.empty())
	{
		double max = 0;
		int index = 0;
		for (int i = 0; i < temp.size(); ++i)
		{
			if (temp[i].weight[preference] > max)
			{
				max = temp[i].weight[preference];
				index = i;
			}
		}
		skylineRoutes.push_back(temp[index]);
		temp.remove(index);
	}
}