#include "animaux.h"
#include <QSqlQuery>
#include <QVariant>
#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItemIterator>

animaux::animaux()
{
    id_animaux=0;
    type="";
    sexe="";


    prix=0;

}
animaux::animaux(int id_animaux, QString type, QString sexe, QDate datea, int prix)
{
    this->id_animaux=id_animaux;
    this->type=type;
    this->sexe=sexe;
    this->datea=datea;
    //this->vaccin=vaccin;
    this->prix=prix;
}
int animaux::Getid_animaux()
{return id_animaux;
}
void animaux::Setid_animaux(int id_animaux)
{
    this->id_animaux=id_animaux;
}
bool animaux::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id_animaux);
         query.prepare("INSERT INTO animaux ( type, sexe, datea, prix) "
                       "VALUES ( :type, :sexe, :datea, :prix)");
        // query.bindValue(":id_animaux", res);

         query.bindValue(":type", type);
         query.bindValue(":sexe", sexe);
         query.bindValue(":datea", datea);

         query.bindValue(":prix", prix);
       return  query.exec();
}
QSqlQueryModel*  animaux::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * from animaux");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("sexe"));

        model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
        return model;
}
 bool animaux::supprimer(int id)
 {
     QSqlQuery query;
     QString res= QString::number(id);
     query.prepare("delete from animaux where id_animaux = :id ");
     query.bindValue(":id", res);
     return query.exec();

 }
 bool animaux::modifier(int id)
 {

 QSqlQuery query;
 QString res= QString::number(id);
 query.prepare("Update animaux set id_animaux = :id , type = :type , sexe = :sexe, prix = :prix where id_animaux = :id ");
 query.bindValue(":id", res);
 query.bindValue(":type", type);
 query.bindValue(":sexe", sexe);
 query.bindValue(":datea", datea);

 query.bindValue(":prix", prix);
 return query.exec();
 }
 QSqlQueryModel* animaux::triee(int index)
 {
     QSqlQueryModel* model = new QSqlQueryModel();
     if(index == 0)
     {
          model->setQuery("select *FROM animaux ORDER BY prix ASC");
     }
     else
     {
          model->setQuery("select *FROM animaux ORDER BY prix DESC ");

     }
     return model;
 }
 QSqlQueryModel * animaux::cherchere(QString type)
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     QSqlQuery query;
     query.prepare("SELECT * from animaux where type like :type order by type ");
     query.bindValue(":type",type);
     query.exec();
     model->setQuery(query);
     return model;
 }
