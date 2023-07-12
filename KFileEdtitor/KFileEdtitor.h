#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_KFileEdtitor.h"
#include "TreeWidget.h"
#include "DisplayWidget.h"
#include "ReadWrite.h"
#include "ItemDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class KFileEdtitorClass; };
QT_END_NAMESPACE

//! ��������
class KFileEdtitor : public QMainWindow
{
    Q_OBJECT

public:
    KFileEdtitor(QWidget *parent = nullptr);
    ~KFileEdtitor();
    void addPlot();

private:
    //! �õ������������
    void getData();
    //! ��ʾ�ļ������ڵ���Ϣ
    void displayItem();
    //! ˫�����ӽڵ㵯������ֵ
    void treeViewDoubleClick();
    //! ��TableWidget������ʾ����
    void treeViewClick();
    // �������á�
    void funDemo();

private:
    Ui::KFileEdtitorClass *ui;


public:

private:
    TreeWidget* treeWidget;
    DisplayWidget* displayWidget;
    ItemDialog* itemDialog;
    ReadWrite* fileRW;
    Data* data;
};
