/********************************************************************************
** Form generated from reading UI file 'resultbutton.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTBUTTON_H
#define UI_RESULTBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResultButtonClass
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *ResultButtonClass)
    {
        if (ResultButtonClass->objectName().isEmpty())
            ResultButtonClass->setObjectName(QStringLiteral("ResultButtonClass"));
        ResultButtonClass->resize(170, 50);
        label = new QLabel(ResultButtonClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 150, 30));
        label->setStyleSheet(QStringLiteral("background:transparent;"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(true);
        pushButton = new QPushButton(ResultButtonClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 170, 50));
        pushButton->setStyleSheet(QLatin1String("QPushButton{background-color:white;border:none;}\n"
"QPushButton:hover{background-color:#ffdc9a;}\n"
"QPushButton:pressed{background-color:#ffe5b5;}"));
        pushButton->raise();
        label->raise();

        retranslateUi(ResultButtonClass);

        QMetaObject::connectSlotsByName(ResultButtonClass);
    } // setupUi

    void retranslateUi(QWidget *ResultButtonClass)
    {
        label->setText(QString());
        pushButton->setText(QString());
        Q_UNUSED(ResultButtonClass);
    } // retranslateUi

};

namespace Ui {
    class ResultButtonClass: public Ui_ResultButtonClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTBUTTON_H
