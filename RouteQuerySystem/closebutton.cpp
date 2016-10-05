#include "closebutton.h"

CloseButton::CloseButton(QWidget *parent /* = nullptr */)
	:QPushButton(parent)
{
	resize(50, 50);
	setIcon(QIcon(":/MainWindow/close.png"));
	setIconSize(QSize(30, 30));
	setStyleSheet("background:transparent");
}