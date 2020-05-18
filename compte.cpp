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
                     "VALUES (:id,:role,:pass");

       query.bindValue(":id", id);
       query.bindValue(":role", role);
       query.bindValue(":pass",pass);



      return query.exec();

}


QSqlQueryModel* compte::affichercompte(){
    QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT * FROM compte");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("role"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("pass"));


         return  model;
}

bool compte::supprimercompte(int id)
{
QSqlQuery query;


query.prepare("Delete from compte where id = :id ");
query.bindValue(":id", id);
return    query.exec();
}


bool compte::modifierpecompte(){
    QSqlQuery query;


    query.prepare("update compte set id=:id,role=:role,pass=:pass ");
    query.bindValue(":id", id);
    query.bindValue(":role",pass);
    query.bindValue(":pass",pass);

   return query.exec();
}
