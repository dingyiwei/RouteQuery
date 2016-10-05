//���ݽӿ�

#pragma once

#include "definition.h"

//���ݽӿ�
class DataProcessor
{
public:
	DataProcessor();

	//��ý�㼯
	QVector<Node> getNodes() const;

	//������ݵ㼯
	QVector<Point> getPoints() const;

	//��ñ߼�������ͼ
	Map getMap() const;

	//���������Ϊ�����Ľ�����
	QVector<QVector<int>> getRegions() const;

private:
	//���
	QVector<Node> nodes;

	//���ݵ�
	QVector<Point> points;

	//�߼�������ͼ
	Map map;

	//������Ϊ�����Ľ�����
	QVector<QVector<int>> regions;

};