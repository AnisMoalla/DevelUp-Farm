#include "commande.h"
#include <QDebug>
#include "connection.h"
#include <QDate>
commande::commande()
{
    NUM=0;
    ARTICLE="";
    PRIX=0;
    QUANTITE=0;
    PRIX_TOTALE=0;

}
commande::commande(int NUM,QString ARTICLE,int PRIX,int QUANTITE,int PRIX_TOTALE,QDate datee)
{this->NUM=NUM;
  this->ARTICLE=ARTICLE;
  this->PRIX=PRIX;
  this->QUANTITE=QUANTITE;
    this->PRIX_TOTALE=PRIX_TOTALE;
    this->datee=datee;


}
commande::commande(int NUM,QString ARTICLE,int PRIX,int QUANTITE,int PRIX_TOTALE)
{this->NUM=NUM;
  this->ARTICLE=ARTICLE;
  this->PRIX=PRIX;
  this->QUANTITE=QUANTITE;
    this->PRIX_TOTALE=PRIX_TOTALE;


}

int commande::get_NUM(){return NUM;}
QString commande::get_ARTICLE(){return  ARTICLE;}
int commande::get_PRIX(){return  PRIX;}
int commande::get_QUANTITE(){return  QUANTITE;}
int commande::get_PRIX_TOTAL(){return  PRIX_TOTALE;}

bool commande::ajouter()
{
QSqlQuery query;
int res= NUM;
query.prepare("INSERT INTO COMMANDE ( NUM, ARTICLE, PRIX, QUANTITE, PRIX_TOTALE,DATE_COMMANDE)VALUES( :NUM, :ARTICLE, :PRIX, :QUANTITE, :PRIX_TOTAL,SYSDATE)");
query.bindValue(":NUM", res);
query.bindValue(":ARTICLE", "HOU");
query.bindValue(":PRIX",  PRIX);
query.bindValue(":QUANTITE",  QUANTITE);
query.bindValue(":PRIX_TOTAL",  PRIX_TOTALE);
//query.bindValue(": DATE",  datee);

return    query.exec();
}

QSqlQueryModel *  commande::Rechercher(QString  ok)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString(ok);
    model->setQuery("select * from commande where (ARTICLE LIKE '"+res+"%' )   ");


            return  model;


}
QSqlQueryModel * commande::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from COMMANDE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ARTICLE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX_TOTALE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_COMMANDE"));


    return model;
}




bool commande::supprimer(int OK)
{
QSqlQuery query;
query.prepare("Delete from COMMANDE where NUM = :NUM ");
query.bindValue(":NUM", OK);
return    query.exec();
}

bool commande::modifier(int id)
{
QSqlQuery query;
query.prepare("Update COMMANDE set PRIX=:PRIX,QUANTITE =:QUANTITE, PRIX_TOTALE=:PRIX_TOTALE where NUM = :NUM ");
query.bindValue(":NUM", id);
query.bindValue(":ARTICLE", ARTICLE);
query.bindValue(":PRIX",  PRIX);
query.bindValue(":QUANTITE",  QUANTITE);
query.bindValue(":PRIX_TOTALE",  PRIX_TOTALE);


return    query.exec();
}

QSqlQueryModel * commande:: afficher_tri_ID_DESC()
{
    QSqlQuery * q = new  QSqlQuery ();
       QSqlQueryModel * model = new  QSqlQueryModel ();
       q->prepare("SELECT * FROM COMMANDE order by PRIX_TOTALE desc");
       q->exec();
       model->setQuery(*q);
       return model;
}
QSqlQueryModel * commande:: afficher_tri_c()
{
    QSqlQuery * q = new  QSqlQuery ();
       QSqlQueryModel * model = new  QSqlQueryModel ();
       q->prepare("SELECT * FROM COMMANDE order by PRIX_TOTALE ASC");
       q->exec();
       model->setQuery(*q);
       return model;
}




