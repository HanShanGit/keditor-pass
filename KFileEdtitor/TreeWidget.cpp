#include "TreeWidget.h"
#include <QStandardItemModel>

TreeWidget::TreeWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::TreeWidgetClass())
{
	ui->setupUi(this);

	QSplitter* splitter = new QSplitter(Qt::Vertical);

	treeItem = new QTreeView(splitter);
	itemAttr = new QTableView(splitter);

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(splitter);

	this->setLayout(layout);
	

	// ���� QStandardItemModel ��Ϊ��������ģ��
	QStandardItemModel* model = new QStandardItemModel();

	// �������ڵ�
	root = new QStandardItem(u8"������ֵ����");
	
	root->setIcon(QIcon("E:/Logo/fir.png"));
	model->appendRow(root);//model->insertRow(0, rootItem);

	// ���� QTreeView ����������ģ��
	treeItem->setModel(model);
	treeItem->expandAll();  // չ�����нڵ�

	treeItem->show();
}

TreeWidget::~TreeWidget()
{
	delete ui;

}
