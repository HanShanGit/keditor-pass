#pragma once
#include "Data.h"
class ReadWrite
{
public:
	ReadWrite();
	~ReadWrite();

	//! ����K�ļ�
	Data* readData(QString filepath);

	//! д���޸ĺ��K�ļ��ڵ���Ϣ
	void writeData(QString filepath);
};

