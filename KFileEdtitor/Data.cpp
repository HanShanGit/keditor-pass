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
	rootOrder = new QList<QString>;
	order = new QMap<QString, QList<QString >*>();
	filename = "";
}

Data::~Data()
{
	//delete rootMap;
	//delete order;
}