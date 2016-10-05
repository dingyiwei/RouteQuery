//skyline��ѯ�㷨

#pragma once

#include "definition.h"

//skyline��ѯ�㷨
class Skyline
{
public:
	//��·�����������ݴ���Ͳü�
	//QVector<Route> routes:·����
	//int preference:ƫ��
	Skyline(QVector<Route> &routes, const int preference);

	//���skyline��ѯ�ü����·����
	QVector<Route> getSkylineRoutes()
	{
		return skylineRoutes;
	}

private:
	//��ʼ��·��Ȩ��
	void initWeight(QVector<Route> &routes);

	//�ü�
	void prune(QVector<Route> &routes);

	//����ƫ�ö�·������
	void sort();

	//�����ü���õ���skyline·����
	QVector<Route> skylineRoutes;

	//ƫ��
	int preference;
};