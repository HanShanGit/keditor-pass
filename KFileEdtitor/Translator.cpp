#include "Translator.h"
#include <QJsonDocument>
#include <QJsonObject>
#include "QFile"
#include "QIODevice"
#include "QDebug"

//Translator::Translator(QString path="")
//{
//	//filepath = path;
//	//json = readJson();
//}

//QJsonObject* Translator::readJson()
//{
//	QFile file(filepath);
//
//	if (!file.open(QIODevice::ReadOnly))
//	{
//		qDebug() << "Failed to open JSON file.";
//		return nullptr;
//	}
//
//	// ��ȡJSON�ļ�����
//	QByteArray jsonData = file.readAll();
//
//	// ����JSON����
//	QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
//
//	// �������Ƿ�ɹ�
//	if (jsonDoc.isNull())
//	{
//		qDebug() << "Failed to parse JSON data.";
//		return nullptr;
//	}
//
//	// ��JSON����ת��Ϊ����
//	json = &(jsonDoc.object());
//
//	// ��ȡ�����е�����
//	//QString name = jsonObject["name"].toString();
//	//int age = jsonObject["age"].toInt();
//
//	// ��ӡ��ȡ������
//	//qDebug() << "Name:" << name;
//	//qDebug() << "Age:" << age;
//}