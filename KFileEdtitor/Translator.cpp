#include "Translator.h"
#include "QTextCodec"

Translator::Translator(QString path)
{
	filepath = path;
	json = nullptr;
	json = readJson();

	// ��ȡ�����е�����
	//QString name = (*json)["rwnpal"].toString();
	//qDebug() << name2;
	
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
	QJsonObject* re = new QJsonObject(jsonDoc.object());

	// ��ȡ�����е�����

	QString name2 = re->value("rwnpal").toString();
	qDebug() << name2;
	return re;
}

void Translator::TestJson()
{
	QString name2 = json->value("rwnpal").toString();
	qDebug() << name2;
}