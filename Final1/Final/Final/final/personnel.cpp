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
personnel::personnel(int id,QString nom,QString mail,QString domaine,QString adresse,QString salaire,QString role){
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
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("DOMAINE"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("SALAIRE"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("ROLE"));


         return  model;
}

bool personnel::supprimerperso(int id)
{
QSqlQuery query;


query.prepare("Delete from personnel where id = :id ");
query.bindValue(":id", id);
return    query.exec();
}


bool personnel::modifierperso(int id,QString nom,QString mail,QString domaine,QString adresse,QString salaire,QString role){
    QSqlQuery query;

QString res= QString::number(id);
    query.prepare("update personnel set nom=:nom,mail=:mail,domaine=:domaine,adresse=:adresse,salaire=:salaire,role=:role where ID= '"+res+"'");
    query.bindValue(":id", res);
    query.bindValue(":nom", nom);
    query.bindValue(":mail",mail);
    query.bindValue(":domaine",domaine);
    query.bindValue(":adresse",adresse);
    query.bindValue(":salaire",salaire);
    query.bindValue(":role",role);

   return query.exec();
}

QSqlQueryModel * personnel::chercherperso(QString index)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString research1="select * FROM PERSONNEL where ID like '"+index+"%' or NOM like '"+index+"%' OR MAIL LIKE '"+index+"%' OR DOMAINE LIKE '"+index+"%' OR ADRESSE LIKE '"+index+"%' OR SALAIRE LIKE '"+index+"%' OR ROLE LIKE '"+index+"%'";
     model->setQuery(research1);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("DOMAINE"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("SALAIRE"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("ROLE"));
    return model;
}

QSqlQueryModel* personnel::triepe(int index)
{ QSqlQueryModel* model = new QSqlQueryModel();
    if(index == 0)
    {model->setQuery("select *FROM PERSONNEL ORDER BY ID ASC");}
    else
    {model->setQuery("select *FROM PERSONNEL ORDER BY ID DESC ");}
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DOMAINE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("SALAIRE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ROLE"));
    return model;}
