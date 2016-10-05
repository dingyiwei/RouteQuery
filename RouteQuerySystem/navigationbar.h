//导航栏

#pragma once

#include "ui_navigationbar.h"

//导航栏
class NavigationBar :public QWidget
{
	Q_OBJECT
public:
	NavigationBar(QWidget *parent = nullptr);

	//获得偏好设置指针
	QPushButton *getPreferenceSettingButton();

	//获得Voronoi图指针
	QPushButton *getVoronoiButton();

	//获得查看结果指针
	QPushButton *getResultButton();

private:
	Ui::NavigationBarClass ui;
};