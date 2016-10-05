#include "inputdialog.h"
#include "categorybutton.h"
#include <fstream>
#include <QGraphicsDropShadowEffect>

InputDialog::InputDialog(QVector<Node> *nodes, QWidget *parent /* = nullptr */)
	:QDialog(parent)
{
	ui.setupUi(this);
	//���ô����ޱ߿�
	setWindowFlags(Qt::FramelessWindowHint);
	//���ñ���͸��
	setAttribute(Qt::WA_TranslucentBackground);

	//����ͶӰ
	QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
	effect->setColor(QColor(0, 0, 0, 70));
	effect->setOffset(0, 0);
	effect->setBlurRadius(10);
	ui.widget->setGraphicsEffect(effect);

	//��ʼ����ѡ��
	initComboBox();

	this->nodes = nodes;

	//�رմ���
	connect(ui.closeButton, SIGNAL(clicked()), this, SLOT(cancelSettings()));
	//ȡ��
	connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(cancelSettings()));
	//ȷ��
	connect(ui.confirmButton, SIGNAL(clicked()), this, SLOT(confirmSettings()));
	//��������
	connect(ui.addCategoryButton, SIGNAL(clicked()), this, SLOT(addCategory()));
	//��λ
	connect(ui.locateButton, SIGNAL(clicked()), this, SLOT(locateNode()));
}

QVector<int> InputDialog::getCategorySequence() const
{
	return categorySequence;
}

double InputDialog::getStartX() const
{
	return ui.longitudeLineEdit->text().toDouble();
}

double InputDialog::getStartY() const
{
	return ui.latitudeLineEdit->text().toDouble();
}

Node InputDialog::getStartNode() const
{
	return (*nodes)[startNodeIndex];
}

int InputDialog::getStartNodeIndex() const
{
	return startNodeIndex;
}

QPushButton *InputDialog::getConfirmButton() const
{
	return ui.confirmButton;
}

int InputDialog::getPreference() const
{
	if (ui.radioButton0->isChecked())
	{
		return 0;
	}
	else if (ui.radioButton1->isChecked())
	{
		return 1;
	}
	else if (ui.radioButton2->isChecked())
	{
		return 2;
	}
	else
	{
		return 3;
	}
}

void InputDialog::initComboBox()
{
	QStringList texts;
	//��ȡ������Ϣ
	std::ifstream filein("Categories.txt");
	std::string cate;
	while (filein >> cate)
	{
		texts << QString::fromStdString(cate);
	}
	ui.comboBox->addItems(texts);
}

void InputDialog::addCategory()
{
	//�������Ͱ�ť
	QString text = ui.comboBox->currentText();
	CategoryButton *categoryButton = new CategoryButton(text, this);
	categories.insert(categories.end(), categoryButton);

	//ɾȥ����
	connect(categoryButton, SIGNAL(clicked()), this, SLOT(removeCategory()));

	//�ڷ����Ͱ�ť
	categoryButton->show();
	arrangeButtons();

	//������ʱ��������
	int index = ui.comboBox->currentIndex();
	tempCateSq.push_back(index);
}

void InputDialog::removeCategory()
{
	//��ð�ť���
	CategoryButton *categoryButton = (CategoryButton*)sender();
	int index = categories.indexOf(categoryButton);

	//ɾȥ��ť
	delete categories[index];
	categories.remove(index);

	//���°ڷ����Ͱ�ť
	arrangeButtons();
}

void InputDialog::arrangeButtons()
{
	for (int i = 0; i < categories.size(); ++i)
	{
		categories[i]->move(i % 3 * BUTTON_X_INCREMENT + BUTTON_X_START
			, i / 3 * BUTTON_Y_INCREMENT + BUTTON_Y_START);
		categories[i]->show();
	}
}

void InputDialog::confirmSettings()
{
	//ȷ��ʱ���������и���
	categorySequence = tempCateSq;
	//�رնԻ���
	close();
}

void InputDialog::cancelSettings()
{
	//������Ͱ�ť
	for each (CategoryButton *button in categories)
	{
		delete button;
	}
	categories.clear();

	//���������������������Ͱ�ť
	for each(int category in categorySequence)
	{
		QString text = ui.comboBox->itemText(category);
		CategoryButton *categoryButton = new CategoryButton(text, this);
		connect(categoryButton, SIGNAL(clicked()), this, SLOT(removeCategory()));
		categories.push_back(categoryButton);
	}
	arrangeButtons();

	//�رնԻ���
	close();
}

void InputDialog::locateNode()
{
	//�����޶�λģ�飬��˶�λ�������ѡһ�����
	std::srand(time(0));
	int index = rand() % (*nodes).size();
	ui.longitudeLineEdit->setText(QString::number((*nodes)[index].x));
	ui.latitudeLineEdit->setText(QString::number((*nodes)[index].y));
	startNodeIndex = index;
}