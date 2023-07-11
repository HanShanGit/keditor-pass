#include "KFileEdtitor.h"
#include "qfiledialog.h"
#include <QHeaderView>


KFileEdtitor::KFileEdtitor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KFileEdtitorClass())
{
    ui->setupUi(this);

    treeWidget = new TreeWidget(ui->centralWidget);
    treeWidget->setMinimumSize(200, 400);
    ui->verticalLayout->addWidget(treeWidget);

    displayWidget = new DisplayWidget(ui->centralWidget);
    displayWidget->setMinimumSize(400, 400);
	ui->horizontalLayout->addWidget(displayWidget);

    fileRW = new ReadWrite();
    data = nullptr;

    addPlot();
}

KFileEdtitor::~KFileEdtitor()
{
    delete ui;
}

void KFileEdtitor::addPlot()
{
    connect(ui->actionOpen, &QAction::triggered, this, &KFileEdtitor::getData);
    connect(treeWidget->treeItem, &QTreeWidget::doubleClicked, this, &KFileEdtitor::treeViewDoubleClick);
    connect(treeWidget->treeItem, &QTreeWidget::clicked, this, &KFileEdtitor::treeViewClick);
}

void KFileEdtitor::getData()
{
    QString filepath = QFileDialog::getOpenFileName(// ��������
        this, "open k file",
        ".",
        "k files (*.k);;All files (*.*)");
    if (filepath == nullptr)
        return;
    
    this->data = fileRW->readData(filepath, displayWidget->textDisplay);
    
    //displayWidget->textDisplay->append(filepath);
    displayItem();
}

void KFileEdtitor::displayItem()
{
    treeWidget->treeItem->setRootIsDecorated(false);
    for each (auto s in *(data->rootOrder))
    {
        QTreeWidgetItem* childItem1 = new QTreeWidgetItem(treeWidget->root);
        childItem1->setIcon(0, QIcon("E:/Logo/sec.png"));
        childItem1->setText(0, s.mid(1));
    }
    treeWidget->treeItem->expandAll();  // չ�����нڵ�
}

void KFileEdtitor::treeViewDoubleClick()
{

    displayWidget->textDisplay->append("treeViewDoubleClick");
}

void KFileEdtitor::treeViewClick()
{
    if (this->data == nullptr)
        return;

    //treeWidget->itemAttr->clearContents(); // ������е�Ԫ�������
    //! �õ���ǰ����ļ�
    QTreeWidgetItem* item = treeWidget->treeItem->currentItem();

    /* ��������ģ�� */
    QStandardItemModel* model = new QStandardItemModel();
    /* ���ñ�������(��������ΪQStringList����) */
    model->setHorizontalHeaderLabels({ u8"����", u8"ֵ" });
    model->setItem(0, 0, new QStandardItem(u8"����"));
    model->setItem(0, 1, new QStandardItem(item->text(0)));

    /* ���ñ����ͼ���� */
    treeWidget->itemAttr->setModel(model);
    treeWidget->itemAttr->verticalHeader()->hide();//����ʾ���  
    

    //! ���ؼ�������ֵ����ʾ
    QMap<QString, QString >* itemValue = nullptr;
    QList<QString >* valueOrder = nullptr;

    itemValue = data->rootMap->value('*'+item->text(0));  // nullptr
    valueOrder = data->order->value('*' + item->text(0));

    if (itemValue == nullptr || valueOrder == nullptr)
        return;

    int lineCount = 0;
    for each (auto k in *valueOrder)
    {
        model->setItem(lineCount, 0, new QStandardItem(k));
        model->setItem(lineCount, 1, new QStandardItem(itemValue->value(k)));
        lineCount++;
    }

    /* ��ʾ */
    treeWidget->itemAttr->show();
}