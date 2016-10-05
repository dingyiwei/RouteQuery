/********************************************************************************
** Form generated from reading UI file 'zoombuttons.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZOOMBUTTONS_H
#define UI_ZOOMBUTTONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ZoomButtonsClass
{
public:
    QPushButton *zoomInButton;
    QPushButton *zoomOutButton;

    void setupUi(QWidget *ZoomButtonsClass)
    {
        if (ZoomButtonsClass->objectName().isEmpty())
            ZoomButtonsClass->setObjectName(QStringLiteral("ZoomButtonsClass"));
        ZoomButtonsClass->resize(101, 30);
        ZoomButtonsClass->setStyleSheet(QStringLiteral("background:transparent;"));
        zoomInButton = new QPushButton(ZoomButtonsClass);
        zoomInButton->setObjectName(QStringLiteral("zoomInButton"));
        zoomInButton->setGeometry(QRect(0, 0, 50, 30));
        zoomInButton->setStyleSheet(QLatin1String("QPushButton{border-top-left-radius:15px;border-bottom-left-radius:15px;border-width:1px;background-color:#ffd078;}\n"
"QPushButton:hover{background-color:#ffdc9a;}"));
        zoomOutButton = new QPushButton(ZoomButtonsClass);
        zoomOutButton->setObjectName(QStringLiteral("zoomOutButton"));
        zoomOutButton->setGeometry(QRect(51, 0, 50, 30));
        zoomOutButton->setStyleSheet(QLatin1String("QPushButton{border-top-right-radius:15px;border-bottom-right-radius:15px;border-width:1px;background-color:#ffd078;}\n"
"QPushButton:hover{background-color:#ffdc9a;}"));

        retranslateUi(ZoomButtonsClass);

        QMetaObject::connectSlotsByName(ZoomButtonsClass);
    } // setupUi

    void retranslateUi(QWidget *ZoomButtonsClass)
    {
        zoomInButton->setText(QApplication::translate("ZoomButtonsClass", "+", 0));
        zoomOutButton->setText(QApplication::translate("ZoomButtonsClass", "-", 0));
        Q_UNUSED(ZoomButtonsClass);
    } // retranslateUi

};

namespace Ui {
    class ZoomButtonsClass: public Ui_ZoomButtonsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZOOMBUTTONS_H
