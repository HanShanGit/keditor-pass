#pragma once
#include <QString>
#include "QMap"

//! ���ڵ�ļ�ֵ��������ֵ
class Data
{
public:
	//! ���ڵ�ļ�ֵ
	QMap<QString , QMap<QString , QString >*>* rootMap;

	//! ���ڵ����Ե�˳��
	QMap<QString , QList<QString >*>* order;

public:
	//<QString, QMap<QString, QString >*>* getRootMap
};

