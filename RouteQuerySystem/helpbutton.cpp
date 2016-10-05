#include "helpbutton.h"

HelpButton::HelpButton(QWidget * parent)
	:QPushButton(parent)
{
	resize(50, 50);
	setIcon(QIcon(":/MainWindow/help.png"));
	setIconSize(QSize(30, 30));
	setStyleSheet("background:transparent");
}
