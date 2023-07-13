#include "ReadThread.h"
#include "qfile.h"

ReadThread::ReadThread(QString f, QTextBrowser* d)
{
	filepath = f;
	display = d;
	data = nullptr;
	ready = false;
}

void ReadThread::run()
{	
	QFile file(filepath);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return;
		//return nullptr;
	}
	Data*re = new Data();

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
		//display->append(str); // ��42����
		//! ��������ʾ��QText����
		//! ��ʾ�������ݻ��ǿ�ֻ��ʾѡ�����

		//! �ж�ѡ�
		if (str.at(0) == '*')
		{
			if (str == "*NODE" || str == "*ELEMENT_SOLID" || str == "*KEYWORD" || str == "*PARAMETER_DUPLICATION" || str == "*END")
				continue;
			display->append(str);
			//! ������ڵ�˳��
			re->rootOrder->append(str.mid(1));
			str = str.simplified();
			kItem = str.mid(1);
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
				QT_TRY
				{
					itemOrder->append(key[i + 1]);
					if (key[i + 1].mid(0, 6) == "unused")
					{
						itemMap->insert(key[i + 1], "");
						// �׳��쳣
						throw "Exception occurred";
					}						
					else
					{
						itemMap->insert(key[i + 1], value[i]);
					}						
				}
				QT_CATCH(const char* ex)
				{
					// ���񲢴����쳣
					qDebug() << "Exception caught:" << ex;
				}
			}
			re->rootMap->insert(kItem, itemMap);
			re->order->insert(kItem, itemOrder);
		}
		
	}

	ready = true;
	this->data = re;

	file.close();
}