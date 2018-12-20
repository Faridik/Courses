#include "sqldb.h"

sqldb::sqldb()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setPort(5433);
    db.setDatabaseName("KursBD");
    query = new QSqlQuery(db);
}

bool sqldb::connect()
{
   db.setUserName("guest");
   db.setPassword("guest111");
   return db.open();
}

bool sqldb::connectFromUser()
{
	db.setUserName("user_def");
	db.setPassword("user111");
	return db.open();
}

void sqldb::disconnect()
{
	db.close();
}

bool sqldb::exec(QString q)
{
	return query->exec(q);
}

sqldb::~sqldb()
{
    db.close();
}
