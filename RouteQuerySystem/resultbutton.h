//�����ť�������ɲ鿴��Ӧ·��/Voronoiͼ

#pragma once

#include "ui_resultbutton.h"

//�����ť�������ɲ鿴��Ӧ·��/Voronoiͼ
class ResultButton :public QPushButton
{
public:
	//int index:��ť���
	//QString information:��ť�ı�
	ResultButton(const int index, const QString &information,
		QWidget *parent = nullptr);

	//��ð�ť���
	int getIndex() const;

	//��ð�ťָ��
	QPushButton *getButton() const;

private:
	Ui::ResultButtonClass ui;

	//��ť���
	int index;
};