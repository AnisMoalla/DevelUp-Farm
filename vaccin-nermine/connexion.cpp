#include "connexion.h"

connexion::connexion()
{

}
bool connexion::ouvrircnx()
{
   QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
   db.setDatabaseName("test");
   db.setUserName("nermine");
   db.setPassword("esprit18");

    if(db.open())
       return true;

    return false;

}

void connexion::fermecnx()
{
    db.close();

}
