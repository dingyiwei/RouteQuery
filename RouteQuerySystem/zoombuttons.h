//缩放按钮组

#pragma once

#include "ui_zoombuttons.h"

//缩放按钮组
class ZoomButtons :public QWidget
{
public:
	ZoomButtons(QWidget *parent = nullptr);

	//获得放大按钮指针
	QPushButton *getZoomInButton() const;

	//获得缩小按钮指针
	QPushButton *getZoomOutButton() const;

private:
	Ui::ZoomButtonsClass ui;
};