#include "personnel.h"
#include<QSqlQuery>
#include<QVariant>
personnel::personnel()
{id=0;
nom="";
    mail="";
    domaine="";
    adresse="";
    salaire="";
    role="";
}
personnel::personnel(int id,QString nom,QString mail,QString,QString domaine,QString adresse,QString salaire,QString role){
    this->id=id;
    this->nom=nom;
    this->mail=mail;
    this->domaine=domaine;
    this->adresse=adresse;
    this->salaire=salaire;
    this->role=role;
}
bool personnel::ajouterperso(){
   QSqlQuery query;
       query.prepare("INSERT INTO personnel (id,nom,mail,domaine,adresse,salaire,role) "
                     "VALUES (:id,:nom,:mail,:domaine,:adresse,:salaire,:role)");

       query.bindValue(":id", id);
       query.bindValue(":nom", nom);
       query.bindValue(":mail",mail);
       query.bindValue(":domaine", domaine);
       query.bindValue(":adresse", adresse);
       query.bindValue(":salaire", salaire);
       query.bindValue(":role", role);


      return query.exec();

}


QSqlQueryModel* personnel::afficherperso(){
    QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT * FROM personnel");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("mail"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("domaine"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("role"));


         return  model;
}

bool personnel::supprimerperso(int id)
{
QSqlQuery query;


query.prepare("Delete from personnel where id = :id ");
query.bindValue(":id", id);
return    query.exec();
}


bool personnel::modifierperso(){
    QSqlQuery query;


    query.prepare("update personnel set nom=:nom,mail=:mail,domaine=:domaine,adresse=:adresse,salaire=:salaire,role=:role ");
    query.bindValue(":nom", nom);
    query.bindValue(":mail",mail);
    query.bindValue(":domaine",domaine);
    query.bindValue(":adresse",adresse);
    query.bindValue(":salaire",salaire);
    query.bindValue(":role",role);

   return query.exec();
}
