#include "helpdialog.h"
#include <QGraphicsDropShadowEffect>

HelpDialog::HelpDialog(QWidget * parent)
	:QDialog(parent)
{
	ui.setupUi(this);
	//���ô����ޱ߿�
	setWindowFlags(Qt::FramelessWindowHint);
	//���ñ���͸��
	setAttribute(Qt::WA_TranslucentBackground);

	//����ͶӰ
	QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
	effect->setColor(QColor(0, 0, 0, 70));
	effect->setOffset(0, 0);
	effect->setBlurRadius(10);
	ui.widget->setGraphicsEffect(effect);

	//�رմ���
	connect(ui.closeButton, SIGNAL(clicked()), this, SLOT(close()));
}
