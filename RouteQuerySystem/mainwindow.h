#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QTimeLine>
#include <QGraphicsOpacityEffect>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QThread>
#include <CGAL/Qt/ApolloniusGraphGraphicsItem.h>
#include "ui_mainwindow.h"
#include "navigationbar.h"
#include "menubutton.h"
#include "closebutton.h"
#include "helpbutton.h"
#include "inputdialog.h"
#include "helpdialog.h"
#include "maparea.h"
#include "zoombuttons.h"
#include "resultbutton.h"
#include "loading.h"
#include "definition.h"
#include "voronoi.h"
#include "skyline.h"

//主窗口
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

	private slots:

	//移动导航栏
	void moveNavigationBar(int xpos);

	//打开/关闭导航栏
	void openNavigation();

	//展示路径
	void displayRoute();

	//绘制Voronoi图
	void drawVoronoiGraph();

	//放大地图
	void mapZoomIn();

	//缩小地图
	void mapZoomOut();

	//设置路径序号
	void setRouteIndex();

	//设置Voronoi图序号
	void setVoronoiIndex();

	void hideLoading();

	signals:
	void computeVoronoiDone();

private:
	//鼠标事件，用于拖动窗口
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

	//设置导航栏动画
	void setNavigationBar();

	//隐藏遮罩
	void hideMask();

	//设置结果按钮
	//bool isRoute:是否为路径结果，true时设置路径按钮，false时设置Voronoi按钮
	void setResultButton(const bool isRoute);

	void computeVoronoi();

	void operateVoronoi();

	Ui::MainWindowClass ui;

	//窗口坐标
	QPoint winPos;

	//鼠标坐标
	QPoint mousePos;

	//导航栏
	NavigationBar *navigationBar;

	//菜单按钮
	MenuButton *menuButton;

	//关闭按钮
	CloseButton *closeButton;

	//帮助按钮
	HelpButton *helpButton;

	//地图、路径、Voronoi图展示区
	MapArea *mapArea;

	//放大缩小按钮组
	ZoomButtons *zoomButtons;

	//结果按钮
	QVector<ResultButton *> resultButtons;

	//时间线，用于移动导航栏和淡入淡出动画
	QTimeLine *timeLine;

	//遮罩
	QWidget *mask;

	//遮罩特效
	QGraphicsOpacityEffect *maskEffect;

	//偏好设置对话框
	InputDialog *inputDialog;

	//帮助对话框
	HelpDialog *helpDialog;

	Loading *loading;

	QThread thread;

	//导航栏状态
	bool isNavigationOpen = false;

	//结点集
	QVector<Node> nodes;

	//数据点集
	QVector<Point> points;

	//地图（边集）
	Map caMap;

	//各区域结点序号集
	QVector<QVector<int>> regions;

	//Voronoi图算法处理
	Voronoi *voronoi = nullptr;

	//skyline查询
	Skyline *skyline = nullptr;

	QVector<Route> m_skylineRoutes;
	QVector<QVector<Node>> m_optimalRoutes;
};

#endif // MAINWINDOW_H
