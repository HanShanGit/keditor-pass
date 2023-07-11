#include "ReadWrite.h"
#include "QFile"
#include "qtextstream.h"

ReadWrite::ReadWrite()
{
	
}

ReadWrite::~ReadWrite()
{

}

Data* ReadWrite::readData(QString filepath)
{
	Data* re = new Data();
	QFile file(filepath);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return nullptr;

	QTextStream in(&file);
	QString kItem; //! ��һ��ѡ�����
	QMap<QString, QString>* itemMap; //! �ڵ��������Ϣ
	QList<QString>* itemOrder; //! �ڵ����Ե�˳��

	//! ���ж�ȡ�ļ�
	while (!in.atEnd()) 
	{
		QByteArray line = file.readLine();
		QString str(line);
		str.remove("\n");

		//! ��������ʾ��QText����
		//! ��ʾ�������ݻ��ǿ�ֻ��ʾѡ�����

		str = str.simplified();
		//! �ж�ѡ�
		if (str.at(0) == '*') 
		{
			if (str == "*NODE" || str == "*ELEMENT_SOLID" || str == "*KEYWORD" || str == "*PARAMETER_DUPLICATION" || str == "*END")
				continue;
			kItem = str;
			itemMap = new QMap<QString, QString>();
			itemOrder = new QList<QString>();
		}
		//! ���ѡ�����ֵ
		else if (str.at(0) == '$' && str.at(1) != '#') 
		{
			QStringList key = str.split(" "); // �±�1��ʼ�����һ��ΪunusedҪ����
			int len = key.length();
			if (key[len - 1].mid(0, 6) == "unused")
			{
				--len;
			}
			
			line = file.readLine(); // ���Ե�ֵ �±�0��ʼ
			QString strvalue(line);
			strvalue.remove("\n");
			strvalue = strvalue.simplified();
			QStringList value = strvalue.split(" "); // �±�0��ʼ

			for (int i = 0; i < len - 1; i++)
			{
				QT_TRY{
					itemMap->insert(key[i + 1], value[i]);
					itemOrder->append(key[i + 1]);
				}
				QT_CATCH(...)
				{

				}
			}
			re->rootMap->insert(kItem, itemMap);
		}
	}

	file.close();

	return re;
}

void ReadWrite::writeData(QString filepath)
{

}