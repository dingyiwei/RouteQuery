#pragma once

#include <QWidget>
#include <QLabel>

class Loading :public QWidget
{
public:
	Loading(QWidget *parent = nullptr);

private:
	QLabel *loadingLabel;
};