#pragma once
#include "Data.h"

//! ˫���������ݺ�����޸�
class Viewer
{
public:
	//! ˢ�����ڵ��޸ĺ������ֵ
	void freshItem();

	//! ��ԭ�����ڵ��ָ���滻Ϊ�޸ĺ��ָ��
	void changePointer(QMap<QString, QString >* oldPointer, Data* data);


};

