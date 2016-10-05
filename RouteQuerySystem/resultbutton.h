//结果按钮，单击可查看相应路径/Voronoi图

#pragma once

#include "ui_resultbutton.h"

//结果按钮，单击可查看相应路径/Voronoi图
class ResultButton :public QPushButton
{
public:
	//int index:按钮序号
	//QString information:按钮文本
	ResultButton(const int index, const QString &information,
		QWidget *parent = nullptr);

	//获得按钮序号
	int getIndex() const;

	//获得按钮指针
	QPushButton *getButton() const;

private:
	Ui::ResultButtonClass ui;

	//按钮序号
	int index;
};