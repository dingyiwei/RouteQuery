//���Ű�ť��

#pragma once

#include "ui_zoombuttons.h"

//���Ű�ť��
class ZoomButtons :public QWidget
{
public:
	ZoomButtons(QWidget *parent = nullptr);

	//��÷Ŵ�ťָ��
	QPushButton *getZoomInButton() const;

	//�����С��ťָ��
	QPushButton *getZoomOutButton() const;

private:
	Ui::ZoomButtonsClass ui;
};