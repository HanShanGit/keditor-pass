#pragma once
#include <QString>
#include "QMap"

//! ���ڵ�ļ�ֵ��������ֵ
class Data
{
public:
	Data();
	~Data();
public:
	//! �Ѷ���
	QMap<QString , QMap<QString , QString >*>* rootMapOut;

	//! ���ڵ�ļ�ֵ
	QMap<QString, QPair<QList<QString >, QList<QString >>*>* rootMap;

	//! ���ڵ��˳��
	QList<QString>* rootOrder;

	//! ���ڵ����Ե�˳��
	QMap<QString , QList<QString >*>* order;

	//! �򿪵��ļ�����
	QString filename;

public:
	//<QString, QMap<QString, QString >*>* getRootMap
};

