#include "categorybutton.h"

CategoryButton::CategoryButton(const QString &text,QWidget *parent /* = nullptr */)
	:QPushButton(parent)
{
	resize(80, 25);
	this->setText(text);
	setStyleSheet("QPushButton{background-color:#7fa8f2;border:none;color:white;}\n"
		"QPushButton:hover{background-color:#96b6f2;}\n"
		"QPushButton:pressed{background-color:#b4ccfa;}");
}