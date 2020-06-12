#include "compte.h"
#include<QSqlQuery>
#include<QVariant>
compte::compte()
{ id=0;
    role="";
    pass="";

}
//
compte::compte(int id,QString role,QString pass){
    this->id=id;
    this->role=role;
    this->pass=pass;
}


bool compte::ajoutercompte(){
   QSqlQuery query;
       query.prepare("INSERT INTO compte (id,role,pass) "
                     "VALUES (:id,:role,:pass)");

       query.bindValue(":id", id);
       query.bindValue(":role", role);
       query.bindValue(":pass",pass);



      return query.exec();

}


QSqlQueryModel* compte::affichercompte(){
    QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT * FROM compte");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("ROLE"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("PASS"));


         return  model;
}

bool compte::supprimercompte(int id)
{
QSqlQuery query;


query.prepare("Delete from compte where id = :id ");
query.bindValue(":id", id);
return    query.exec();
}


bool compte::modifiercompte(int id,QString role,QString pass){
    QSqlQuery query;

QString res= QString::number(id);
    query.prepare("update compte set id=:id,role=:role,pass=:pass  where ID= '"+res+"'");
    query.bindValue(":id", res);
    query.bindValue(":role",role);
    query.bindValue(":pass",pass);

   return query.exec();
}

QSqlQueryModel* compte::triecompte(int index)
{ QSqlQueryModel* model = new QSqlQueryModel();
    if(index == 0)
    {model->setQuery("select * FROM compte ORDER BY id ASC");}
    else
    {model->setQuery("select * FROM compte ORDER BY id DESC ");}

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ROLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PASS"));
    return model;}

QSqlQueryModel * compte::cherchercompte(QString index)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString research1="select * FROM compte where ID like '"+index+"%' or ROLE like '"+index+"%' OR PASS LIKE '"+index+"%'";
     model->setQuery(research1);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("ROLE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("PASS"));
    return model;
}
