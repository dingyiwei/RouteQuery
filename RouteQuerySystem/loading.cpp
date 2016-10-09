#include "loading.h"
#include <QMovie>

Loading::Loading(QWidget * parent)
	:QWidget(parent)
{
	this->resize(120, 120);
	this->move(340, 240);
	loadingLabel = new QLabel(this);

	this->setStyleSheet("background-color:#ffffff;border-top-left-radius:10px;border-top-right-radius:10px;border-bottom-left-radius:10px;border-bottom-right-radius:10px;");
	loadingLabel->move(10, 10);
	QMovie *loadingMovie = new QMovie(":/MainWindow/loading.gif");
	
	loadingLabel->setMovie(loadingMovie);
	loadingMovie->start();
}
