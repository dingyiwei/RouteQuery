#include "zoombuttons.h"

ZoomButtons::ZoomButtons(QWidget *parent /* = nullptr */)
	:QWidget(parent)
{
	ui.setupUi(this);
}

QPushButton *ZoomButtons::getZoomInButton() const
{
	return ui.zoomInButton;
}

QPushButton *ZoomButtons::getZoomOutButton() const
{
	return ui.zoomOutButton;
}