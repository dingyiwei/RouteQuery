#include "navigationbar.h"

NavigationBar::NavigationBar(QWidget *parent /* = nullptr */)
	:QWidget(parent)
{
	ui.setupUi(this);
}

QPushButton * NavigationBar::getPreferenceSettingButton()
{
	return ui.preferenceSettingButton;
}

QPushButton * NavigationBar::getVoronoiButton()
{
	return ui.voronoiButton;
}

QPushButton * NavigationBar::getResultButton()
{
	return ui.resultButton;
}