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
	//���ڵ�ļ�ֵ
	QMap<QString , QMap<QString , QString >*>* rootMapOut;

	//! ���ڵ�ļ�ֵ
	QMap<QString, QPair<QList<QList<QString>>, QList<QList<QString>>>*>* rootMap;
	//QList<QList<QString>>

	//! ���ڵ��˳��
	QList<QString>* rootOrder;

	//! �Ѷ���
	//���ڵ����Ե�˳��
	QMap<QString, QList<QString >*>* orderOut; 

	//! �򿪵��ļ�����
	QString filename;

public:
	//<QString, QMap<QString, QString >*>* getRootMap
};

