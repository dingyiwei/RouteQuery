#include "helpdialog.h"
#include <QGraphicsDropShadowEffect>

HelpDialog::HelpDialog(QWidget * parent)
	:QDialog(parent)
{
	ui.setupUi(this);
	//设置窗口无边框
	setWindowFlags(Qt::FramelessWindowHint);
	//设置背景透明
	setAttribute(Qt::WA_TranslucentBackground);

	//设置投影
	QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
	effect->setColor(QColor(0, 0, 0, 70));
	effect->setOffset(0, 0);
	effect->setBlurRadius(10);
	ui.widget->setGraphicsEffect(effect);

	//关闭窗口
	connect(ui.closeButton, SIGNAL(clicked()), this, SLOT(close()));
}
