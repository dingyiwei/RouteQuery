//������

#pragma once

#include "ui_navigationbar.h"

//������
class NavigationBar :public QWidget
{
	Q_OBJECT
public:
	NavigationBar(QWidget *parent = nullptr);

	//���ƫ������ָ��
	QPushButton *getPreferenceSettingButton();

	//���Voronoiͼָ��
	QPushButton *getVoronoiButton();

	//��ò鿴���ָ��
	QPushButton *getResultButton();

private:
	Ui::NavigationBarClass ui;
};