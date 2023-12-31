#include "ItemDialog.h"
#include "qlayout.h"
#include "QLabel"
#include "QTextEdit"
#include "QDebug"

ItemDialog::ItemDialog(QWidget*parent)
	: QDialog(parent)
	, ui(new Ui::ItemWidgetClass())
{
	save = new QPushButton(u8"保存", this);
	cacel = new QPushButton(u8"取消", this);
	save->setVisible(false);
	cacel->setVisible(false);
	
	dialogMapData = nullptr;
	krows = nullptr;
	vrows = nullptr;
	//onlyValue = nullptr;

	ui->setupUi(this);
	connect(this->save, &QPushButton::clicked, this, &ItemDialog::getDialogData);
	//connect(this->save, &QPushButton::clicked, new KFileEdtitor(), &KFileEdtitor::freshData);
	connect(this->cacel, &QPushButton::clicked, this, &QWidget::close);
}

ItemDialog::~ItemDialog()
{
	delete ui;
}

void ItemDialog::getDialogData()
{
	//! 储存对话框里面的QMap键值信息
	QMap<QString, QString >* kv = new QMap<QString, QString>;
	//! 遍历所有Label控件和TextEdit控件
	QList<QLabel*> labelList = this->findChildren<QLabel*>(); // 有顺序
	QList<QTextEdit*> textEditList = this->findChildren<QTextEdit*>(); // 有顺序
	onlyValue = this->findChildren<QTextEdit*>();
	//! 把键值信息写入到QMap中
	krows = new QList<QString>;
	vrows = new QList<QString>;
	int kCount = labelList.size();
	for (int i = 0; i < labelList.size(); i++) 
	{
		krows->append(labelList.at(i)->text());
		vrows->append(textEditList.at(i)->toPlainText());
	}	

	//! 关闭当前窗体
	this->close();

}

