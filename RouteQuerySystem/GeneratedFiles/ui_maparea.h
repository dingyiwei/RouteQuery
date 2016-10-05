/********************************************************************************
** Form generated from reading UI file 'maparea.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPAREA_H
#define UI_MAPAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapAreaClass
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QWidget *MapAreaClass)
    {
        if (MapAreaClass->objectName().isEmpty())
            MapAreaClass->setObjectName(QStringLiteral("MapAreaClass"));
        MapAreaClass->resize(600, 550);
        graphicsView = new QGraphicsView(MapAreaClass);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 600, 550));
        graphicsView->setStyleSheet(QLatin1String("QGraphicsView{background-color:white;}\n"
"QScrollBar:vertical{width:8px;padding-top:9px;padding-bottom:9px;}\n"
"QGraphicsView QScrollBar::handle:vertical{width:8px;border-radius:4px;}"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        retranslateUi(MapAreaClass);

        QMetaObject::connectSlotsByName(MapAreaClass);
    } // setupUi

    void retranslateUi(QWidget *MapAreaClass)
    {
        MapAreaClass->setWindowTitle(QApplication::translate("MapAreaClass", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class MapAreaClass: public Ui_MapAreaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPAREA_H
