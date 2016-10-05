//����Ի���

#pragma once

#include "ui_inputdialog.h"
#include "categorybutton.h"
#include "definition.h"
#include <QVector>

//����Ի���
class InputDialog :public QDialog
{
	Q_OBJECT
public:
	//QVector<Node> *nodes:��㼯ָ��
	InputDialog(QVector<Node> *nodes, QWidget *parent = nullptr);

	//�����������
	QVector<int> getCategorySequence() const;

	//�����������
	double getStartX() const;

	//������������
	double getStartY() const;

	//��������
	Node getStartNode() const;

	//�����������
	int getStartNodeIndex() const;

	//���ƫ��
	int getPreference() const;

	//���ȷ����ťָ��
	QPushButton *getConfirmButton() const;

	private slots:
	//��������
	void addCategory();

	//ɾȥ����
	void removeCategory();

	//ȷ������
	void confirmSettings();

	//ȡ������
	void cancelSettings();

	//��λ���
	void locateNode();

private:
	//��ʼ����ѡ��
	void initComboBox();

	//�ڷ����Ͱ�ť
	void arrangeButtons();

	Ui::InputDialogClass ui;

	//��������
	QVector<int> categorySequence;

	//���Ͱ�ťָ�뼯
	QVector<CategoryButton*> categories;

	//��ʱ��������
	QVector<int> tempCateSq;

	//��㼯ָ��
	QVector<Node> *nodes;

	//��������
	int startNodeIndex;

	//���Ͱ�ť���������
	const int BUTTON_X_START = 90;

	//���Ͱ�ť����������
	const int BUTTON_X_INCREMENT = 90;

	//���Ͱ�ť���������
	const int BUTTON_Y_START = 180;

	//���Ͱ�ť����������
	const int BUTTON_Y_INCREMENT = 30;
};