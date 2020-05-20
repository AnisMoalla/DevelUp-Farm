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
    QString res=QString::number(id_nourriture);
         query.prepare("INSERT INTO nourritures (id_nourriture, nom, quantite_nour, prix_unitaire) "
                       "VALUES (:id_nourriture, :nom,  :quantite_nour, :prix_unitaire)");
         //query.bindValue(":id_nourriture", res);
        //query.bindValue(":id_commande", res);
         query.bindValue(":nom", nom);
         query.bindValue(":quantite_nour", quantite_nour);
         query.bindValue(":prix_unitaire", prix_unitaire);
       return  query.exec();
}
 QSqlQueryModel*  nourritures::afficher()
 {
     QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT* from nourritures");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_nourriture"));
         //model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_commande"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite_nour"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix_unitaire"));
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
  query.prepare("Update animaux set id_nourriture = :id , nom = :nom , quantite_nour = :qt, prix_unitaire = :prix, ");
  query.bindValue(":id", res);
  query.bindValue(":nom", nom);
  query.bindValue(":qt", quantite_nour);
  query.bindValue(":prix", prix_unitaire);

  return query.exec();
  }
