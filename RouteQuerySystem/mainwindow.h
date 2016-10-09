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

//������
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

	private slots:

	//�ƶ�������
	void moveNavigationBar(int xpos);

	//��/�رյ�����
	void openNavigation();

	//չʾ·��
	void displayRoute();

	//����Voronoiͼ
	void drawVoronoiGraph();

	//�Ŵ��ͼ
	void mapZoomIn();

	//��С��ͼ
	void mapZoomOut();

	//����·�����
	void setRouteIndex();

	//����Voronoiͼ���
	void setVoronoiIndex();

	void hideLoading();

	signals:
	void computeVoronoiDone();

private:
	//����¼��������϶�����
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

	//���õ���������
	void setNavigationBar();

	//��������
	void hideMask();

	//���ý����ť
	//bool isRoute:�Ƿ�Ϊ·�������trueʱ����·����ť��falseʱ����Voronoi��ť
	void setResultButton(const bool isRoute);

	void computeVoronoi();

	void operateVoronoi();

	Ui::MainWindowClass ui;

	//��������
	QPoint winPos;

	//�������
	QPoint mousePos;

	//������
	NavigationBar *navigationBar;

	//�˵���ť
	MenuButton *menuButton;

	//�رհ�ť
	CloseButton *closeButton;

	//������ť
	HelpButton *helpButton;

	//��ͼ��·����Voronoiͼչʾ��
	MapArea *mapArea;

	//�Ŵ���С��ť��
	ZoomButtons *zoomButtons;

	//�����ť
	QVector<ResultButton *> resultButtons;

	//ʱ���ߣ������ƶ��������͵��뵭������
	QTimeLine *timeLine;

	//����
	QWidget *mask;

	//������Ч
	QGraphicsOpacityEffect *maskEffect;

	//ƫ�����öԻ���
	InputDialog *inputDialog;

	//�����Ի���
	HelpDialog *helpDialog;

	Loading *loading;

	QThread thread;

	//������״̬
	bool isNavigationOpen = false;

	//��㼯
	QVector<Node> nodes;

	//���ݵ㼯
	QVector<Point> points;

	//��ͼ���߼���
	Map caMap;

	//����������ż�
	QVector<QVector<int>> regions;

	//Voronoiͼ�㷨����
	Voronoi *voronoi = nullptr;

	//skyline��ѯ
	Skyline *skyline = nullptr;

	QVector<Route> m_skylineRoutes;
	QVector<QVector<Node>> m_optimalRoutes;
};

#endif // MAINWINDOW_H
