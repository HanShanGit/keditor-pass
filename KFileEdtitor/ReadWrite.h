#pragma once
#include "Data.h"
#include "qtextbrowser.h"

//! ��д�����ļ���
class ReadWrite
{
public:
	ReadWrite();
	~ReadWrite();

	//! ����K�ļ�
	Data* readData(QString filepath,QTextBrowser* display);// Ҫ���ÿɰ�display��ʾĬ������nullptr

	//! д���޸ĺ��K�ļ��ڵ���Ϣ
	void writeData(QString filepath);

	
};

