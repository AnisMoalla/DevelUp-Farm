#include "command.h"
#include <QDebug>
#include "connexion.h"
#include <QDate>
command::command()
{CMD=0;

           CIN="";
             IANIMAUX=0;
             QUANTITE=0;
             PRIX_TOTAL=0;

}
command::command(int CMD,QString CIN,int IANIMAUX,int QUANTITE,int PRIX_TOTAL)
{this->CMD=CMD;
  this->CIN=CIN;
  this->IANIMAUX=IANIMAUX;
  this->QUANTITE=QUANTITE;
    this->PRIX_TOTAL=PRIX_TOTAL;

}

int command::get_ID_CMD(){return CMD;}
QString command::get_CIN(){return  CIN;}
int command::get_ID_ANIMAUX(){return  IANIMAUX;}
int command::get_QUANTITE(){return  QUANTITE;}
int command::get_PRIX_TOTAL(){return  PRIX_TOTAL;}

bool command::ajouter()
{
QSqlQuery query;
int res= CMD;
query.prepare("INSERT INTO COMMANDE ( ID_CMD, CIN, ID_ANIMAUX, QUANTITE, PRIX_TOTAL,DATE_CMD)VALUES( :ID_CMD, :CIN, :ID_ANIMAUX, :QUANTITE, :PRIX_TOTAL,SYSDATE)");
query.bindValue(":ID_CMD", res);
query.bindValue(":CIN", CIN);
query.bindValue(":ID_ANIMAUX",  IANIMAUX);
query.bindValue(":QUANTITE",  QUANTITE);
query.bindValue(":PRIX_TOTAL",  PRIX_TOTAL);
//query.bindValue(": DATE_CMD",  DATE_CMD);

return    query.exec();
}

QSqlQueryModel * command::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from COMMANDE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CMD"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_ANIMAUX"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX_TOTAL"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_CMD"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN"));

    return model;
}

bool command::supprimer(int ID_CMD)
{
QSqlQuery query;
int res= ID_CMD;
query.prepare("Delete from COMMANDE where ID_CMD = :ID_CMD ");
query.bindValue(":ID_CMD", res);
return    query.exec();
}

bool command::modifier(QString CIN)
{
QSqlQuery query;
QString res=CIN;
query.prepare("Update COMMANDE set ID_ANIMAUX=:ID_ANIMAUX,QUANTITE =:QUANTITE, PRIX_TOTAL=:PRIX_TOTAL where CIN = :ID_CMD ");
query.bindValue(":ID_CMD", res);
query.bindValue(":CIN", CIN);
query.bindValue(":ID_ANIMAUX",  IANIMAUX);
query.bindValue(":QUANTITE",  QUANTITE);
query.bindValue(":PRIX_TOTAL",  PRIX_TOTAL);


return    query.exec();
}

QSqlQueryModel * command:: afficher_tri_ID_DESC()
{
    QSqlQuery * q = new  QSqlQuery ();
       QSqlQueryModel * model = new  QSqlQueryModel ();
       q->prepare("SELECT * FROM COMMANDE order by PRIX_TOTAL desc");
       q->exec();
       model->setQuery(*q);
       return model;
}
QSqlQueryModel * command:: afficher_tri_c()
{
    QSqlQuery * q = new  QSqlQuery ();
       QSqlQueryModel * model = new  QSqlQueryModel ();
       q->prepare("SELECT * FROM COMMANDE order by PRIX_TOTAL ASC");
       q->exec();
       model->setQuery(*q);
       return model;
}




