#include "ReadWrite.h"
#include "QFile"
#include "qtextstream.h"
#include "qtextbrowser.h"

ReadWrite::ReadWrite()
{
	
}

ReadWrite::~ReadWrite()
{

}

Data* ReadWrite::readData(QString filepath, QTextBrowser* display)
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
		//display->append(str);
		//! ��������ʾ��QText����
		//! ��ʾ�������ݻ��ǿ�ֻ��ʾѡ�����
		
		//! �ж�ѡ�
		if (str.at(0) == '*') 
		{
			if (str == "*NODE" || str == "*ELEMENT_SOLID" || str == "*KEYWORD" || str == "*PARAMETER_DUPLICATION" || str == "*END")
				continue;
			display->append(str);
			re->rootOrder->append(str);
			str = str.simplified();
			kItem = str;
			itemMap = new QMap<QString, QString>();
			itemOrder = new QList<QString>();
		}
		//! ���ѡ�����ֵ
		else if (str.at(0) == '$' && str.at(1) != '#') 
		{
			display->append(str);
			str = str.simplified();
			QStringList key = str.split(" "); // �±�1��ʼ�����һ��ΪunusedҪ����
			
			int len = key.length();
			/*if (key[len - 1].mid(0, 6) == "unused")
			{
				--len;
			}*/
			
			line = file.readLine(); // ���Ե�ֵ �±�0��ʼ
			
			QString strvalue(line);			
			strvalue.remove("\n");
			display->append(strvalue);
			strvalue = strvalue.simplified();
			
			QStringList value = strvalue.split(" "); // �±�0��ʼ

			for (int i = 0; i < len - 1; i++)
			{
				QT_TRY{
					itemOrder->append(key[i + 1]);
					if(key[i + 1].mid(0,6)=="unused")
						itemMap->insert(key[i + 1], "NONE");
					else
						itemMap->insert(key[i + 1], value[i]);														
				}
				QT_CATCH(...)
				{

				}
			}
			re->rootMap->insert(kItem, itemMap);
			re->order->insert(kItem, itemOrder);
		}
	}

	file.close();

	return re;
}

void ReadWrite::writeData(QString filepath)
{

}