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
	
	dialogData = nullptr;

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
	//! ����Ի�������ļ�ֵ��Ϣ
	QMap<QString, QString >* kv = new QMap<QString, QString>;
	//! ��������Label�ؼ���TextEdit�ؼ�
	QList<QLabel*> labelList = this->findChildren<QLabel*>();
	QList<QTextEdit*> textEditList = this->findChildren<QTextEdit*>();
	
	//! �Ѽ�ֵ��Ϣд�뵽QMap��
	for (int i = 0; i < labelList.size(); i++) 
	{
		kv->insert(labelList.at(i)->text(), textEditList.at(i)->toPlainText());
	}
	//! ��QMap����ȥ, ����|�ж��Ƿ����
	//! ���ڵ��ֵ
	QString title = this->windowTitle();
	//qDebug() << title;
	

	//! �رյ�ǰ����
	this->close();

	dialogData = kv;
}

