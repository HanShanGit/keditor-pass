#pragma once
#include "QMap"
#include "QString"
#include <QJsonDocument>
#include <QJsonObject>
#include "QFile"
#include "QIODevice"
#include "QDebug"
//! �ı�����
class Translator //: public QObject
{
	//Q_OBJECT
public:
	//! �洢��������
	QJsonObject* json;
	//! �����ļ�·��
	QString filepath;

public:
	Translator(QString filepath);
	Translator();
	~Translator();

private:
	//! ��ȡ�����ļ�
	QJsonObject* readJson();

public:
	void TestJson();
	
};

