//skyline查询算法

#pragma once

#include "definition.h"

//skyline查询算法
class Skyline
{
public:
	//对路径集进行数据处理和裁剪
	//QVector<Route> routes:路径集
	//int preference:偏好
	Skyline(QVector<Route> &routes, const int preference);

	//获得skyline查询裁剪后的路径集
	QVector<Route> getSkylineRoutes()
	{
		return skylineRoutes;
	}

private:
	//初始化路径权重
	void initWeight(QVector<Route> &routes);

	//裁剪
	void prune(QVector<Route> &routes);

	//根据偏好对路径排序
	void sort();

	//经过裁剪后得到的skyline路径集
	QVector<Route> skylineRoutes;

	//偏好
	int preference;
};