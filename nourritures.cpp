#include "nourritures.h"
#include <QSqlQuery>
#include <QVariant>
#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItemIterator>

nourritures::nourritures()
{
    id_nourriture=0;
    nom="";
    quantite_nour=0;
    prix_unitaire=0;

}
nourritures::nourritures(int id_nourriture, QString nom, int quantite_nour, int prix_unitaire)
{
    this->id_nourriture=id_nourriture;
    this->nom=nom;
    this->quantite_nour=quantite_nour;
    this->prix_unitaire=prix_unitaire;
}
int nourritures::Getid_nourriture()
{return id_nourriture;
}
void nourritures::Setid_nourriture(int id_nourriture)
{
    this->id_nourriture=id_nourriture;
}
bool nourritures::ajouter()
{
    QSqlQuery query;

         query.prepare("INSERT INTO nourritures ( NOM, QUANTITE_NOUR, PRIX_UNITAIRE) VALUES (:nom,:quantite,:prix_unitaire)");

         query.bindValue(":nom", nom);
         query.bindValue(":quantite", quantite_nour);
         query.bindValue(":prix_unitaire",prix_unitaire);
       return  query.exec();
}
 QSqlQueryModel*  nourritures::afficher()
 {
     QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT* from nourritures");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix unitaire"));
         return model;
 }
  bool nourritures::supprimer(int id)
  {
      QSqlQuery query;
      QString res= QString::number(id);
      query.prepare("delete from nourritures where id_nourriture =:id");
      query.bindValue(":id", res);
      return query.exec();

  }
  bool nourritures::modifier(int id)
  {

  QSqlQuery query;
  QString res= QString::number(id);
  query.prepare("Update nourritures set nom = :nom , quantite_nour = :qt, prix_unitaire = :prix where id_nourriture = :id ");
  query.bindValue(":id", id);
  query.bindValue(":nom", nom);
  query.bindValue(":qt", quantite_nour);
  query.bindValue(":prix", prix_unitaire);

  return query.exec();
  }
  QSqlQueryModel* nourritures::triee(int index)
  {
      QSqlQueryModel* model = new QSqlQueryModel();
      if(index == 0)
      {
           model->setQuery("select *FROM nourritures ORDER BY prix_unitaire ASC");
      }
      else
      {
           model->setQuery("select *FROM nourritures ORDER BY prix_unitaire DESC ");

      }
      return model;
  }
  QSqlQueryModel * nourritures::cherchere(QString index)
  {
      QSqlQueryModel * model=new QSqlQueryModel();
      QString research="select * FROM nourritures where nom like '"+index+"%' or prix_unitaire like '"+index+"%' ";
      model->setQuery(research);
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix unitaire"));

      return model;
  }
