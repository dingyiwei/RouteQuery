#include <resultbutton.h>

ResultButton::ResultButton(const int index, const QString &information,
	QWidget *parent /* = nullptr */) :QPushButton(parent)
{
	ui.setupUi(this);
	ui.label->setParent(ui.pushButton);
	move(5, 5 + 55 * index);
	ui.label->setText(information);
	this->index = index;
}

int ResultButton::getIndex() const
{
	return index;
}

QPushButton *ResultButton::getButton() const
{
	return ui.pushButton;
}