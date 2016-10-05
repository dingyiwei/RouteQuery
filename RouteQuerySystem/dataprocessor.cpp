#include "dataprocessor.h"
#include <fstream>
#include <QMessageBox>

DataProcessor::DataProcessor()
{
	//读取结点
	std::ifstream filein("CaNodes.txt");
	int index;
	double x, y;
	while (filein >> index >> x >> y)
	{
		Node node = { x,y };
		nodes.push_back(node);
	}
	filein.close();

	regions.resize(ROW*COL);
	int category;
	double rowDistance = (TOP - BOTTOM) / ROW;
	double colDistance = (RIGHT - LEFT) / COL;

	//读取数据点
	filein.open("CaPoints_weight.txt");
	while (filein >> category >> x >> y)
	{
		Point p;
		p.category = category;
		p.x = x;
		p.y = y;
		int rowRegion = (int)((x - LEFT) / colDistance);
		int colRegion = (int)((TOP - y) / rowDistance);
		p.regionIndex = rowRegion*ROW + colRegion;
		regions[p.regionIndex].push_back(points.size());
		for (int i = 0; i < NUM_OF_POINT_ATTRIBUTE; ++i)
		{
			filein >> p.weight[i];
			p.weight[i] /= 100;
		}

		points.push_back(p);
	}
	filein.close();

	//读取边
	int startNodeIndex, endNodeIndex, numOfPoints, pointIndex;
	double length;
	filein.open("CaMap2.txt");
	while (filein >> startNodeIndex >> endNodeIndex >> length >> numOfPoints)
	{
		Edge edge;
		edge.u = startNodeIndex;
		edge.v = endNodeIndex; 
		int rowRegion = (int)((nodes[startNodeIndex].x - LEFT) / colDistance);
		int colRegion = (int)((TOP - nodes[startNodeIndex].y) / rowDistance);
		edge.regionIndex = rowRegion*ROW + colRegion;
		for (int i = 0; i < numOfPoints; ++i)
		{
			filein >> pointIndex;
			edge.points.push_back(pointIndex - 1);
			points[pointIndex - 1].edgeIndex = map.size();
		}
		map.push_back(edge);
	}
	filein.close();
}

QVector<Node> DataProcessor::getNodes() const
{
	return nodes;
}

QVector<Point> DataProcessor::getPoints() const
{
	return points;
}

Map DataProcessor::getMap() const
{
	return map;
}

QVector<QVector<int>> DataProcessor::getRegions() const
{
	return regions;
}