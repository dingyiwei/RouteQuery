/********************************************************************************
** Form generated from reading UI file 'inputdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTDIALOG_H
#define UI_INPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputDialogClass
{
public:
    QWidget *widget;
    QLabel *label_4;
    QPushButton *closeButton;
    QLabel *label;
    QLineEdit *longitudeLineEdit;
    QLineEdit *latitudeLineEdit;
    QPushButton *locateButton;
    QLabel *label_2;
    QRadioButton *radioButton0;
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QRadioButton *radioButton3;
    QLabel *label_3;
    QComboBox *comboBox;
    QPushButton *addCategoryButton;
    QPushButton *confirmButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *InputDialogClass)
    {
        if (InputDialogClass->objectName().isEmpty())
            InputDialogClass->setObjectName(QStringLiteral("InputDialogClass"));
        InputDialogClass->resize(410, 310);
        widget = new QWidget(InputDialogClass);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(5, 5, 400, 300));
        widget->setStyleSheet(QStringLiteral("background:white;"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 0, 100, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(12);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        closeButton = new QPushButton(widget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(350, 0, 50, 50));
        closeButton->setStyleSheet(QStringLiteral("background:transparent;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/MainWindow/close_black.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeButton->setIcon(icon);
        closeButton->setIconSize(QSize(30, 30));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 60, 50, 30));
        label->setFont(font);
        longitudeLineEdit = new QLineEdit(widget);
        longitudeLineEdit->setObjectName(QStringLiteral("longitudeLineEdit"));
        longitudeLineEdit->setGeometry(QRect(90, 60, 80, 30));
        longitudeLineEdit->setFont(font);
        latitudeLineEdit = new QLineEdit(widget);
        latitudeLineEdit->setObjectName(QStringLiteral("latitudeLineEdit"));
        latitudeLineEdit->setGeometry(QRect(180, 60, 80, 30));
        latitudeLineEdit->setFont(font);
        locateButton = new QPushButton(widget);
        locateButton->setObjectName(QStringLiteral("locateButton"));
        locateButton->setGeometry(QRect(270, 60, 30, 30));
        locateButton->setStyleSheet(QStringLiteral("background:transparent;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/MainWindow/locate.png"), QSize(), QIcon::Normal, QIcon::Off);
        locateButton->setIcon(icon1);
        locateButton->setIconSize(QSize(30, 30));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 100, 50, 30));
        label_2->setFont(font);
        radioButton0 = new QRadioButton(widget);
        radioButton0->setObjectName(QStringLiteral("radioButton0"));
        radioButton0->setGeometry(QRect(90, 110, 68, 16));
        radioButton0->setChecked(true);
        radioButton1 = new QRadioButton(widget);
        radioButton1->setObjectName(QStringLiteral("radioButton1"));
        radioButton1->setGeometry(QRect(165, 110, 55, 16));
        radioButton2 = new QRadioButton(widget);
        radioButton2->setObjectName(QStringLiteral("radioButton2"));
        radioButton2->setGeometry(QRect(225, 110, 71, 16));
        radioButton3 = new QRadioButton(widget);
        radioButton3->setObjectName(QStringLiteral("radioButton3"));
        radioButton3->setGeometry(QRect(300, 110, 89, 16));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 140, 50, 30));
        label_3->setFont(font);
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(90, 140, 100, 30));
        comboBox->setFont(font);
        comboBox->setStyleSheet(QLatin1String("QComboBox{border-width:1px;border-style:solid;border-color:#888888;border-radius:2px 2px 2px 2px}\n"
"QComboBox::drop-down{border-width:1px;border-style:solid;border-left-color:#888888;}\n"
"QComboBox::down-arrow{image:url(:/MainWindow/down_arrow.png);width:12px;}"));
        addCategoryButton = new QPushButton(widget);
        addCategoryButton->setObjectName(QStringLiteral("addCategoryButton"));
        addCategoryButton->setGeometry(QRect(200, 140, 30, 30));
        addCategoryButton->setStyleSheet(QStringLiteral("background:transparent"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/MainWindow/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addCategoryButton->setIcon(icon2);
        addCategoryButton->setIconSize(QSize(30, 30));
        confirmButton = new QPushButton(widget);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setGeometry(QRect(200, 240, 80, 40));
        QFont font1;
        confirmButton->setFont(font1);
        confirmButton->setStyleSheet(QLatin1String("QPushButton{background-color:#7fa8f3;border:none;color:white;font-size:14px;border-radius:4px 4px 4px 4px}\n"
"QPushButton:hover{background-color:#96b6f2;}\n"
"QPushButton:pressed{background-color:#b4ccfa;}"));
        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(290, 240, 80, 40));
        cancelButton->setFont(font1);
        cancelButton->setStyleSheet(QLatin1String("QPushButton{background-color:#7fa8f3;border:none;color:white;font-size:14px;border-radius:4px 4px 4px 4px}\n"
"QPushButton:hover{background-color:#96b6f2;}\n"
"QPushButton:pressed{background-color:#b4ccfa;}"));

        retranslateUi(InputDialogClass);

        QMetaObject::connectSlotsByName(InputDialogClass);
    } // setupUi

    void retranslateUi(QDialog *InputDialogClass)
    {
        InputDialogClass->setWindowTitle(QApplication::translate("InputDialogClass", "Dialog", 0));
        label_4->setText(QApplication::translate("InputDialogClass", "\345\201\217\345\245\275\350\256\276\347\275\256", 0));
        closeButton->setText(QString());
        label->setText(QApplication::translate("InputDialogClass", "\350\265\267\347\202\271\357\274\232", 0));
        longitudeLineEdit->setPlaceholderText(QApplication::translate("InputDialogClass", "\347\273\217\345\272\246", 0));
        latitudeLineEdit->setPlaceholderText(QApplication::translate("InputDialogClass", "\347\272\254\345\272\246", 0));
        locateButton->setText(QString());
        label_2->setText(QApplication::translate("InputDialogClass", "\345\201\217\345\245\275\357\274\232", 0));
        radioButton0->setText(QApplication::translate("InputDialogClass", "\346\200\247\344\273\267\346\257\224\351\253\230", 0));
        radioButton1->setText(QApplication::translate("InputDialogClass", "\350\267\235\347\246\273\347\237\255", 0));
        radioButton2->setText(QApplication::translate("InputDialogClass", "\351\201\223\350\267\257\347\225\205\351\200\232", 0));
        radioButton3->setText(QApplication::translate("InputDialogClass", "\346\227\266\351\227\264\347\237\255", 0));
        label_3->setText(QApplication::translate("InputDialogClass", "\347\261\273\345\236\213\357\274\232", 0));
        addCategoryButton->setText(QString());
        confirmButton->setText(QApplication::translate("InputDialogClass", "\347\241\256\345\256\232", 0));
        cancelButton->setText(QApplication::translate("InputDialogClass", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class InputDialogClass: public Ui_InputDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIALOG_H
