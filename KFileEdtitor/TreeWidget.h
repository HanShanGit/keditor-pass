#pragma once

#include <QWidget>
#include "ui_TreeWidget.h"
#include "QTreeView"
#include "QTableView"
#include "QPushButton"
#include "QVBoxLayout"
#include "QSplitter"

QT_BEGIN_NAMESPACE
namespace Ui { class TreeWidgetClass; };
QT_END_NAMESPACE

class TreeWidget : public QWidget
{
	Q_OBJECT

public:
	TreeWidget(QWidget *parent = nullptr);
	~TreeWidget();

private:
	Ui::TreeWidgetClass *ui;
	//! ���ڵ�
	QTreeView* treeItem;

	//! ���ڵ�����
	QTableView* itemAttr;
};
