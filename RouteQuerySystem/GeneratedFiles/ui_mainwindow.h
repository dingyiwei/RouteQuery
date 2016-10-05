/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QWidget *menubar;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *noInfomationLabel;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(800, 600);
        MainWindowClass->setStyleSheet(QStringLiteral("background-color:#eeeeee;"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        menubar = new QWidget(centralWidget);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(-5, 0, 810, 50));
        menubar->setStyleSheet(QStringLiteral("background-color:#7fa8f2;"));
        label = new QLabel(menubar);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 0, 200, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(18);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color:white"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(600, 50, 200, 550));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 200, 550));
        noInfomationLabel = new QLabel(scrollAreaWidgetContents);
        noInfomationLabel->setObjectName(QStringLiteral("noInfomationLabel"));
        noInfomationLabel->setGeometry(QRect(70, 250, 71, 31));
        QFont font1;
        font1.setPointSize(12);
        noInfomationLabel->setFont(font1);
        scrollArea->setWidget(scrollAreaWidgetContents);
        MainWindowClass->setCentralWidget(centralWidget);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindowClass", "\350\267\257\345\276\204\346\237\245\350\257\242\347\263\273\347\273\237", 0));
        noInfomationLabel->setText(QApplication::translate("MainWindowClass", "\346\232\202\346\227\240\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
