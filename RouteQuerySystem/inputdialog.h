//输入对话框

#pragma once

#include "ui_inputdialog.h"
#include "categorybutton.h"
#include "definition.h"
#include <QVector>

//输入对话框
class InputDialog :public QDialog
{
	Q_OBJECT
public:
	//QVector<Node> *nodes:结点集指针
	InputDialog(QVector<Node> *nodes, QWidget *parent = nullptr);

	//获得类型序列
	QVector<int> getCategorySequence() const;

	//获得起点横坐标
	double getStartX() const;

	//获得起点纵坐标
	double getStartY() const;

	//获得起点结点
	Node getStartNode() const;

	//获得起点结点序号
	int getStartNodeIndex() const;

	//获得偏好
	int getPreference() const;

	//获得确定按钮指针
	QPushButton *getConfirmButton() const;

	private slots:
	//增加类型
	void addCategory();

	//删去类型
	void removeCategory();

	//确认设置
	void confirmSettings();

	//取消设置
	void cancelSettings();

	//定位起点
	void locateNode();

private:
	//初始化多选框
	void initComboBox();

	//摆放类型按钮
	void arrangeButtons();

	Ui::InputDialogClass ui;

	//类型序列
	QVector<int> categorySequence;

	//类型按钮指针集
	QVector<CategoryButton*> categories;

	//临时类型序列
	QVector<int> tempCateSq;

	//结点集指针
	QVector<Node> *nodes;

	//起点结点序号
	int startNodeIndex;

	//类型按钮横坐标起点
	const int BUTTON_X_START = 90;

	//类型按钮横坐标增量
	const int BUTTON_X_INCREMENT = 90;

	//类型按钮纵坐标起点
	const int BUTTON_Y_START = 180;

	//类型按钮纵坐标增量
	const int BUTTON_Y_INCREMENT = 30;
};