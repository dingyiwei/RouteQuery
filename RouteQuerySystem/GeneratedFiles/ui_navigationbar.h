/********************************************************************************
** Form generated from reading UI file 'navigationbar.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIGATIONBAR_H
#define UI_NAVIGATIONBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NavigationBarClass
{
public:
    QPushButton *preferenceSettingButton;
    QPushButton *voronoiButton;
    QPushButton *resultButton;
    QWidget *widget;

    void setupUi(QWidget *NavigationBarClass)
    {
        if (NavigationBarClass->objectName().isEmpty())
            NavigationBarClass->setObjectName(QStringLiteral("NavigationBarClass"));
        NavigationBarClass->resize(250, 600);
        NavigationBarClass->setStyleSheet(QStringLiteral("background-color:#7fa8f3;"));
        preferenceSettingButton = new QPushButton(NavigationBarClass);
        preferenceSettingButton->setObjectName(QStringLiteral("preferenceSettingButton"));
        preferenceSettingButton->setGeometry(QRect(0, 100, 250, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(16);
        preferenceSettingButton->setFont(font);
        preferenceSettingButton->setStyleSheet(QLatin1String("QPushButton {border:none;color:white}\n"
"QPushButton:hover {background-color:rgb(118, 158, 226);}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/MainWindow/cross.png"), QSize(), QIcon::Normal, QIcon::Off);
        preferenceSettingButton->setIcon(icon);
        preferenceSettingButton->setIconSize(QSize(32, 32));
        voronoiButton = new QPushButton(NavigationBarClass);
        voronoiButton->setObjectName(QStringLiteral("voronoiButton"));
        voronoiButton->setGeometry(QRect(0, 160, 250, 60));
        voronoiButton->setFont(font);
        voronoiButton->setStyleSheet(QLatin1String("QPushButton {border:none;color:white;padding-left:14px;}\n"
"QPushButton:hover {background-color:rgb(118, 158, 226);}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/MainWindow/triangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        voronoiButton->setIcon(icon1);
        voronoiButton->setIconSize(QSize(32, 32));
        resultButton = new QPushButton(NavigationBarClass);
        resultButton->setObjectName(QStringLiteral("resultButton"));
        resultButton->setGeometry(QRect(0, 220, 250, 60));
        resultButton->setFont(font);
        resultButton->setStyleSheet(QLatin1String("QPushButton {border:none;color:white;}\n"
"QPushButton:hover {background-color:rgb(118, 158, 226);}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/MainWindow/circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        resultButton->setIcon(icon2);
        resultButton->setIconSize(QSize(32, 32));
        widget = new QWidget(NavigationBarClass);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, -1, 251, 601));
        widget->raise();
        preferenceSettingButton->raise();
        voronoiButton->raise();
        resultButton->raise();

        retranslateUi(NavigationBarClass);

        QMetaObject::connectSlotsByName(NavigationBarClass);
    } // setupUi

    void retranslateUi(QWidget *NavigationBarClass)
    {
        NavigationBarClass->setWindowTitle(QApplication::translate("NavigationBarClass", "Form", 0));
        preferenceSettingButton->setText(QApplication::translate("NavigationBarClass", " \345\201\217\345\245\275\350\256\276\347\275\256", 0));
        voronoiButton->setText(QApplication::translate("NavigationBarClass", " Voronoi\345\233\276", 0));
        resultButton->setText(QApplication::translate("NavigationBarClass", " \346\237\245\347\234\213\347\273\223\346\236\234", 0));
    } // retranslateUi

};

namespace Ui {
    class NavigationBarClass: public Ui_NavigationBarClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIGATIONBAR_H
