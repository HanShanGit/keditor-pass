#pragma once
#include "Data.h"
#include "qtextbrowser.h"


//! ��д�����ļ���
class ReadWrite
{
	//Q_OBJECT
public:
	ReadWrite();
	~ReadWrite();

public slots:
	//! ����K�ļ�
	Data* readData(QString filepath,QTextBrowser* display);// Ҫ���ÿɰ�display��ʾĬ������nullptr

	//! д���޸ĺ��K�ļ��ڵ���Ϣ
	void writeData(QString filepath, Data* data);

	//! ����
	void fileTest() {
		int i = 1;

	}
};

