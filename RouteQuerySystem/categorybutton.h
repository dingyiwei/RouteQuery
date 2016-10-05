//类型按钮

#pragma once

#include <QPushButton>

//类型按钮
class CategoryButton :public QPushButton
{
public:
	//QString text:类型文本
	CategoryButton(const QString &text, QWidget *parent = nullptr);

};