#include "ItemDialog.h"
#include "qlayout.h"
#include "QLabel"
#include "QTextEdit"
#include "QDebug"

ItemDialog::ItemDialog(QWidget*parent)
	: QDialog(parent)
	, ui(new Ui::ItemWidgetClass())
{
	save = new QPushButton(u8"����", this);
	cacel = new QPushButton(u8"ȡ��", this);
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
	//! ����Ի��������QMap��ֵ��Ϣ
	QMap<QString, QString >* kv = new QMap<QString, QString>;
	//! ����Ի��������QPair��ֵ��Ϣ
	//QPair<QList<QList<QString>>, QList<QList<QString>>>* kvPair = new QPair<QList<QList<QString>>, QList<QList<QString>>>;
	//auto kList = kvPair->first;
	//auto vList = kvPair->first;
	//! ��������Label�ؼ���TextEdit�ؼ�
	QList<QLabel*> labelList = this->findChildren<QLabel*>(); // ��˳��
	QList<QTextEdit*> textEditList = this->findChildren<QTextEdit*>(); // ��˳��
	onlyValue = this->findChildren<QTextEdit*>();
	//! �Ѽ�ֵ��Ϣд�뵽QMap��
	krows = new QList<QString>;
	vrows = new QList<QString>;
	int kCount = labelList.size();
	for (int i = 0; i < labelList.size(); i++) 
	{
		//if (labelList.at(i)->text().mid(0, 6) == "unused")
		//{
		//	kList.append(*krow);
		//	vList.append(*vrow);
		//	krow = new QList<QString>;
		//	vrow = new QList<QString>;
		//}
		krows->append(labelList.at(i)->text());
		vrows->append(textEditList.at(i)->toPlainText());
		//kv->insert(labelList.at(i)->text(), textEditList.at(i)->toPlainText());
	}

	//! ��QMap����ȥ, ����|�ж��Ƿ����
	//! ���ڵ��ֵ
	QString title = this->windowTitle();
	//qDebug() << title;
	

	//! �رյ�ǰ����
	this->close();

	//dialogMapData = kv;
}

