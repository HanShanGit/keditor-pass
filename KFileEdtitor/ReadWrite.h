#pragma once
#include "Data.h"
#include "qtextbrowser.h"


//! ��д�����ļ���
class ReadWrite : public QObject
{
	//Q_OBJECT
public:
	ReadWrite();
	~ReadWrite();

public slots:
	//! ����K�ļ�
	Data* readData(QString filepath,QTextBrowser* display);// Ҫ���ÿɰ�display��ʾĬ������nullptr

	//! ֻд���޸ĺ�K�ļ��Ľڵ���Ϣ
	void writeDataRoot(QString filepath, Data* data);

	//! д���޸Ľڵ�������K�ļ�
	void writeData(QString filepath, Data* data);

	//! ����
	void testSlots();
};

