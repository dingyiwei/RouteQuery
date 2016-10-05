//帮助对话框

#pragma once

#include "ui_helpdialog.h"

//帮助对话框
class HelpDialog :public QDialog
{
public:
	HelpDialog(QWidget *parent = nullptr);

private:
	Ui::HelpDialogClass ui;
};