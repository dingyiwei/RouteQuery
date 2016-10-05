#include "menubutton.h"

MenuButton::MenuButton(QWidget *parent /* = nullptr */)
	:QPushButton(parent)
{
	resize(75, 50);
	setIcon(QIcon(":/MainWindow/menu.png"));
	setIconSize(QSize(30, 30));
	setStyleSheet("background:transparent");
}