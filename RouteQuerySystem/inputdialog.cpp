#include "inputdialog.h"
#include "categorybutton.h"
#include <fstream>
#include <QGraphicsDropShadowEffect>

InputDialog::InputDialog(QVector<Node> *nodes, QWidget *parent /* = nullptr */)
	:QDialog(parent)
{
	ui.setupUi(this);
	//设置窗口无边框
	setWindowFlags(Qt::FramelessWindowHint);
	//设置背景透明
	setAttribute(Qt::WA_TranslucentBackground);

	//设置投影
	QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
	effect->setColor(QColor(0, 0, 0, 70));
	effect->setOffset(0, 0);
	effect->setBlurRadius(10);
	ui.widget->setGraphicsEffect(effect);

	//初始化多选框
	initComboBox();

	this->nodes = nodes;

	//关闭窗口
	connect(ui.closeButton, SIGNAL(clicked()), this, SLOT(cancelSettings()));
	//取消
	connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(cancelSettings()));
	//确定
	connect(ui.confirmButton, SIGNAL(clicked()), this, SLOT(confirmSettings()));
	//增加类型
	connect(ui.addCategoryButton, SIGNAL(clicked()), this, SLOT(addCategory()));
	//定位
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
	//读取类型信息
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
	//增加类型按钮
	QString text = ui.comboBox->currentText();
	CategoryButton *categoryButton = new CategoryButton(text, this);
	categories.insert(categories.end(), categoryButton);

	//删去类型
	connect(categoryButton, SIGNAL(clicked()), this, SLOT(removeCategory()));

	//摆放类型按钮
	categoryButton->show();
	arrangeButtons();

	//更新临时类型序列
	int index = ui.comboBox->currentIndex();
	tempCateSq.push_back(index);
}

void InputDialog::removeCategory()
{
	//获得按钮序号
	CategoryButton *categoryButton = (CategoryButton*)sender();
	int index = categories.indexOf(categoryButton);

	//删去按钮
	delete categories[index];
	categories.remove(index);

	//重新摆放类型按钮
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
	//确认时将类型序列更新
	categorySequence = tempCateSq;
	//关闭对话框
	close();
}

void InputDialog::cancelSettings()
{
	//清空类型按钮
	for each (CategoryButton *button in categories)
	{
		delete button;
	}
	categories.clear();

	//用类型序列重新设置类型按钮
	for each(int category in categorySequence)
	{
		QString text = ui.comboBox->itemText(category);
		CategoryButton *categoryButton = new CategoryButton(text, this);
		connect(categoryButton, SIGNAL(clicked()), this, SLOT(removeCategory()));
		categories.push_back(categoryButton);
	}
	arrangeButtons();

	//关闭对话框
	close();
}

void InputDialog::locateNode()
{
	//由于无定位模块，因此定位即随机挑选一个结点
	std::srand(time(0));
	int index = rand() % (*nodes).size();
	ui.longitudeLineEdit->setText(QString::number((*nodes)[index].x));
	ui.latitudeLineEdit->setText(QString::number((*nodes)[index].y));
	startNodeIndex = index;
}