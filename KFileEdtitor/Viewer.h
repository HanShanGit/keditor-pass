#pragma once
#include "Data.h"

class Viewer
{
public:
	//! �����ڵ�ˢ���޸ĺ������ֵ
	void freshItem();

	//! ��ԭ�����ڵ��ָ���滻Ϊ�޸ĺ��ָ��
	void changePointer(QMap<QString, QString >* oldPointer, Data* data);



};

