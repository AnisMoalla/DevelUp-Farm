#include "connexion.h"


connexion::connexion()
{

}

bool connexion::ouvrircnx()
{
    db= QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("anis");//inserer nom de l'utilisateur
    db.setPassword("esprit18");//inserer mot de passe de cet utilisateur
    if(db.open())
        return true;

   return false;
}

void connexion::fermercnx()
{db.close();}
