/********************************************************************************
** Form generated from reading UI file 'helpdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPDIALOG_H
#define UI_HELPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpDialogClass
{
public:
    QWidget *widget;
    QLabel *label;
    QPushButton *closeButton;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *HelpDialogClass)
    {
        if (HelpDialogClass->objectName().isEmpty())
            HelpDialogClass->setObjectName(QStringLiteral("HelpDialogClass"));
        HelpDialogClass->resize(560, 460);
        HelpDialogClass->setStyleSheet(QStringLiteral("background:transparent;"));
        widget = new QWidget(HelpDialogClass);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(5, 5, 550, 450));
        widget->setStyleSheet(QStringLiteral("background:white;"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 75, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        closeButton = new QPushButton(widget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(500, 0, 50, 50));
        closeButton->setStyleSheet(QStringLiteral("background:transparent;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/MainWindow/close_black.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeButton->setIcon(icon);
        closeButton->setIconSize(QSize(30, 30));
        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 50, 550, 400));
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        retranslateUi(HelpDialogClass);

        QMetaObject::connectSlotsByName(HelpDialogClass);
    } // setupUi

    void retranslateUi(QDialog *HelpDialogClass)
    {
        label->setText(QApplication::translate("HelpDialogClass", "\345\270\256\345\212\251", 0));
        closeButton->setText(QString());
        textBrowser->setHtml(QApplication::translate("HelpDialogClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:14pt; font-weight:600;\">1.\350\275\257\344\273\266\346\246\202\350\277\260</span><span style=\" font-size:14pt;\"> </span></p>\n"
"<p style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:12pt; font-weight:600;\">1.1 \345\274\200\345\217\221\347\233\256\347\232\204</span><span style=\" fon"
                        "t-size:12pt;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:11pt;\">\346\231\256\351\200\232\347\232\204\345\234\260\345\233\276\350\267\257\345\276\204\350\247\204\345\210\222\350\275\257\344\273\266\345\276\200\345\276\200\346\234\211\351\231\220\345\210\266\342\200\224\342\200\224\345\217\252\350\203\275\344\273\216\346\237\220\344\270\200\347\211\271\345\256\232\350\265\267\347\202\271\345\210\260\346\237\220\344\270\200\347\211\271\345\256\232\347\273\210\347\202\271\357\274\214\350\277\231\345\234\250\347\233\256\346\240\207\346\230\257\346\230\216\347\241\256\347\232\204\346\203\205\345\206\265\344\270\213\346\230\257\351\200\202\347\224\250\347\232\204\343\200\202\344\275\206\346\230\257\346\234\211\346\227\266\357\274\214\346\210\221\344\273\254\345\217\252\346\230\257\346\203\263\347\273\217\350\277\207"
                        "\346\237\220\344\272\233\347\261\273\345\236\213\347\232\204\347\202\271\357\274\214\350\200\214\346\262\241\346\234\211\346\230\216\347\241\256\347\232\204\347\233\256\346\240\207\343\200\202\346\257\224\345\246\202\357\274\214\345\270\214\346\234\233\345\205\210\345\216\273\347\234\213\347\224\265\345\275\261\357\274\214\347\204\266\345\220\216\345\220\203\351\245\255\357\274\214\345\206\215\345\216\273\351\205\222\345\220\247\343\200\202\350\277\231\347\247\215\346\203\205\345\206\265\344\270\213\357\274\214\346\210\221\344\273\254\345\217\252\346\230\257\345\270\214\346\234\233\345\276\227\345\210\260\346\273\241\350\266\263\350\246\201\346\261\202\347\232\204\350\267\257\345\276\204\357\274\214\345\257\271\347\273\217\350\277\207\347\232\204\347\261\273\345\236\213\347\202\271\345\205\267\344\275\223\344\275\215\347\275\256\346\230\257\346\262\241\346\234\211\350\246\201\346\261\202\343\200\202\345\233\240\346\255\244\357\274\214\346\210\221\344\273\254\345\270\214\346\234\233\350\256\276\350\256\241\345\207"
                        "\272\344\270\200\346\254\276\345\217\257\344\273\245\346\273\241\350\266\263\350\277\231\347\247\215\351\234\200\346\261\202\347\232\204\350\275\257\344\273\266\343\200\202\345\220\214\346\227\266\357\274\214\345\276\227\345\210\260\347\232\204\350\267\257\345\276\204\350\277\230\351\234\200\350\246\201\346\273\241\350\266\263\347\224\250\346\210\267\346\211\200\350\256\276\345\256\232\347\232\204\345\201\217\345\245\275\357\274\214\345\246\202\347\224\250\346\227\266\350\276\203\347\237\255\343\200\201\350\276\203\345\260\221\346\213\245\345\240\265\347\255\211\343\200\202</span><span style=\" font-size:11pt;\"> </span></p>\n"
"<p style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:x-large; font-weight:600;\">1.2 \345\237\272\346\234\254\345\216\237\347\220\206</span> </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0"
                        "px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:11pt;\">\346\225\260\346\215\256\347\202\271\344\277\241\346\201\257\344\270\272\347\276\216\345\233\275\345\212\240\345\260\274\347\246\217\345\260\274\344\272\232\345\267\236\347\232\204\350\267\257\347\275\221\344\277\241\346\201\257\343\200\202</span><span style=\" font-size:11pt;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:11pt;\">\351\200\232\350\277\207\345\273\272\347\253\213\345\212\240\346\235\203V</span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:11pt; color:#333333; background-color:#ffffff;\">oronoi\345\233\276\345\257\271\350\267\257\347\275\221\344\277\241\346\201\257\350"
                        "\277\233\350\241\214\345\244\204\347\220\206\357\274\214\345\257\271\345\244\204\347\220\206\345\220\216\345\276\227\345\210\260\347\232\204\350\267\257\345\276\204\350\277\233\350\241\214skyline\346\237\245\350\257\242\357\274\214\346\216\222\351\231\244\351\202\243\344\272\233\350\242\253\346\224\257\351\205\215\347\232\204\350\267\257\345\276\204\344\273\216\350\200\214\345\276\227\345\210\260\346\234\200\347\273\210\347\232\204\347\273\223\346\236\234\343\200\202</span><span style=\" font-size:11pt;\"> </span></p>\n"
"<p style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:x-large; font-weight:600;\">1.3 \344\270\273\350\246\201\345\212\237\350\203\275</span> </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275"
                        "\257\351\233\205\351\273\221 Light,sans-serif'; font-size:11pt;\">\346\240\271\346\215\256\347\224\250\346\210\267\350\276\223\345\205\245\347\232\204\347\261\273\345\236\213\347\202\271\345\272\217\345\210\227\345\222\214\345\201\217\345\245\275\357\274\214\345\273\272\347\253\213\345\271\266\344\270\224\345\261\225\347\244\272V</span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:11pt; color:#333333; background-color:#ffffff;\">oronoi\345\233\276\357\274\214\346\217\220\344\276\233\346\234\200\347\273\210\347\232\204\347\254\246\345\220\210\347\224\250\346\210\267\351\234\200\350\246\201\347\232\204\350\276\203\344\274\230\350\267\257\345\276\204\343\200\202</span><span style=\" font-size:11pt;\"> </span></p>\n"
"<p style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:xx-large; fo"
                        "nt-weight:600;\">2.\350\275\257\344\273\266\344\275\277\347\224\250\350\277\207\347\250\213</span> </p>\n"
"<p style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:x-large; font-weight:600;\">2.1 \344\275\277\347\224\250\346\255\245\351\252\244</span> </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:11pt;\">\347\225\214\351\235\242\345\267\246\344\276\247\347\232\204\350\217\234\345\215\225\346\240\217\346\234\211\342\200\234\345\201\217\345\245\275\350\256\276\347\275\256\342\200\235\343\200\201\342\200\234Voronoi\345\233\276\342\200\235\345\222\214\342\200\234\346\237\245\347\234\213\347\273\223\346\236\234\342\200\235\344\270\211\344\270\252\351\200\211"
                        "\351\241\271\343\200\202\351\246\226\345\205\210\347\202\271\345\207\273\342\200\234\345\201\217\345\245\275\350\256\276\347\275\256\342\200\235\351\200\211\351\241\271\357\274\214\345\234\250\345\274\271\345\207\272\347\232\204\350\217\234\345\215\225\346\240\217\351\207\214\350\277\233\350\241\214\350\265\267\347\202\271\343\200\201\347\273\217\350\277\207\347\261\273\345\236\213\347\202\271\344\273\245\345\217\212\347\224\250\346\210\267\345\201\217\345\245\275\347\232\204\350\256\276\347\275\256\357\274\214\347\202\271\345\207\273\342\200\234\347\241\256\345\256\232\342\200\235\345\256\214\346\210\220\350\256\276\347\275\256\343\200\202\347\204\266\345\220\216\347\202\271\345\207\273\342\200\234Voronoi\345\233\276\342\200\235\351\200\211\351\241\271\357\274\214\345\217\257\344\273\245\346\237\245\347\234\213\347\224\237\346\210\220\347\232\204Voronoi\345\233\276\343\200\202\346\234\200\347\273\210\347\202\271\345\207\273\342\200\234\346\237\245\347\234\213\347\273\223\346\236\234\342\200\235\357\274\214\345"
                        "\217\257\344\273\245\347\234\213\345\210\260</span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:11pt; color:#333333; background-color:#ffffff;\">skyline\350\267\257\345\276\204\347\273\223\346\236\234\347\232\204\345\233\276\345\275\242\345\214\226\345\261\225\347\244\272\357\274\214\347\202\271\345\207\273\345\217\263\344\276\247\347\232\204\350\267\257\345\276\204\345\220\215\347\247\260\345\217\257\344\273\245\346\237\245\347\234\213\344\270\215\345\220\214\347\232\204\347\273\223\346\236\234\343\200\202</span><span style=\" font-size:11pt;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/HelpDialog/help/navigationbar.png\" /> </p>\n"
"<p style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-"
                        "serif'; font-size:x-large; font-weight:600;\">2.2 \350\276\223\345\205\245</span> </p>\n"
"<p style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/HelpDialog/help/inputdialog.png\" /> </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:11pt;\">\351\246\226\345\205\210\351\200\232\350\277\207\347\273\217\347\272\254\345\272\246\345\256\232\344\275\215\350\265\267\347\202\271\343\200\202\347\204\266\345\220\216\351\200\211\346\213\251\347\224\250\346\210\267\345\201\217\345\245\275\357\274\214\345\217\257\351\200\211\351\200\211\351\241\271\344\270\272\342\200\234\346\200\247\344\273\267\346\257\224\351\253\230\342\200\235\343\200\201\342\200\234\350\267\235\347\246\273\347\237\255\342\200\235\343\200\201\342\200\234\351\201\223\350\267\257\347\225\205"
                        "\351\200\232\342\200\235\345\222\214\342\200\234\346\227\266\351\227\264\347\237\255\342\200\235\343\200\202\346\234\200\345\220\216\351\200\232\350\277\207\342\212\225\345\217\267\346\267\273\345\212\240\351\234\200\350\246\201\347\273\217\350\277\207\347\232\204\347\261\273\345\236\213\347\202\271\357\274\214\345\246\202airport\343\200\202</span><span style=\" font-size:11pt;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:11pt;\">\345\256\214\346\210\220\346\211\200\346\234\211\347\232\204\350\276\223\345\205\245\345\206\205\345\256\271\345\220\216\347\202\271\345\207\273\342\200\234\347\241\256\345\256\232\342\200\235\343\200\202</span><span style=\" font-size:11pt;\"> </span></p>\n"
"<p style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><spa"
                        "n style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:x-large; font-weight:600;\">2.3 \350\276\223\345\207\272</span> </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:11pt;\">\351\200\232\350\277\207\345\267\246\344\276\247\347\232\204\350\217\234\345\215\225\346\240\217\345\217\257\344\273\245\346\237\245\347\234\213\350\276\223\345\207\272\347\273\223\346\236\234\343\200\202</span><span style=\" font-size:11pt;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:11pt;\">\347\202\271\345\207\273\342\200\234V</span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273"
                        "\221 Light,sans-serif'; font-size:11pt; color:#333333; background-color:#ffffff;\">oronoi\345\233\276</span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:11pt;\">\342\200\235\351\200\211\351\241\271\345\217\257\344\273\245\346\237\245\347\234\213\347\224\237\346\210\220\347\232\204</span><a name=\"OLE_LINK1\"></a><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:11pt;\">V</span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:11pt; color:#333333; background-color:#ffffff;\">oronoi\345\233\276\343\200\202</span><span style=\" font-size:11pt;\"> </span></p>\n"
"<p style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/HelpDialog/help/voronoi.png\" /> </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text"
                        "-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:11pt; color:#333333; background-color:#ffffff;\">\347\202\271\345\207\273\342\200\234\346\237\245\347\234\213\347\273\223\346\236\234\342\200\235\351\200\211\351\241\271\345\217\257\344\273\245\346\237\245\347\234\213skyline\350\267\257\345\276\204\347\273\223\346\236\234\343\200\202</span><span style=\" font-size:11pt;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/HelpDialog/help/route.png\" /> </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:11pt; color:#333333; background-color:#ffffff;\">\345\234\260\345\233\276\345\267\246\344\270\212\346\226\271\347\232\204\342\200\234+\342\200\235\345\222\214"
                        "\342\200\234-\342\200\235\345\217\257\344\273\245\345\257\271\345\234\260\345\233\276\350\277\233\350\241\214\346\224\276\345\244\247\346\210\226\350\200\205\347\274\251\345\260\217\343\200\202</span><span style=\" font-size:11pt;\"> </span></p>\n"
"<p style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:xx-large; font-weight:600;\">3.\350\275\257\344\273\266\347\273\264\346\212\244</span> </p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221 Light,sans-serif'; font-size:11pt;\">\350\275\257\344\273\266\345\275\223\345\211\215\347\211\210\346\234\254\345\217\267\357\274\2321.0</span><span style=\" font-size:11pt;\"> </span></p></body></html>", 0));
        Q_UNUSED(HelpDialogClass);
    } // retranslateUi

};

namespace Ui {
    class HelpDialogClass: public Ui_HelpDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDIALOG_H
