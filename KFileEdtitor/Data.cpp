#include "Data.h"

/*public:
	Data();
	~Data();
public:
	//! ���ڵ�ļ�ֵ
	QMap<QString , QMap<QString , QString >*>* rootMap;

	//! ���ڵ����Ե�˳��
	QMap<QString , QList<QString >*>* order;
*/
Data::Data()
{
	rootMap = new QMap<QString, QMap<QString, QString >*>();
	order = new QMap<QString, QList<QString >*>();
}

Data::~Data()
{
	delete rootMap;
	delete order;
}