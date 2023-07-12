#include "Translator.h"
#include "QTextCodec"

Translator::Translator(QString path = "")
{
	filepath = path;
	json = readJson();

}

QJsonObject* Translator::readJson()
{
	QFile file(filepath);

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "Failed to open JSON file.";
		return nullptr;
	}

	// ��ȡJSON�ļ�����
	QByteArray jsonData = file.readAll();

	// ָ���ļ�����
	QTextCodec* codec = QTextCodec::codecForName("GBK");
	QString jsonString = codec->toUnicode(jsonData);

	// ����JSON����
	QJsonParseError parseError;
	QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8(), &parseError);
	//QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8(), &parseError);

	if (parseError.error != QJsonParseError::NoError) {
		qDebug() << "Failed to parse JSON:" << parseError.errorString();
		return nullptr;
	}


	// �������Ƿ�ɹ�
	if (jsonDoc.isNull())
	{
		qDebug() << "Failed to parse JSON data.";
		return nullptr;
	}

	// ��JSON����ת��Ϊ����
	json = new QJsonObject(jsonDoc.object());

	// ��ȡ�����е�����
	//QString name = jsonObject["name"].toString();
	//int age = jsonObject["age"].toInt();
	//QString name = (*json)["slsfac"].toString();
	//QString name2 = (*json)["rwnpal"].toString();
	
	// ��ӡ��ȡ������
	//qDebug() << "Name:" << name;
	//qDebug() << "Age:" << age;
	//qDebug() << name << name2;
}