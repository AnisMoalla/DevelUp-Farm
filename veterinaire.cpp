#include "veterinaire.h"
#include <QDebug>
#include "connexion.h"
Veterinaire::Veterinaire()
{
nom="";
CIN="";
prix=0;
numtele="";
adresse="";
email="";
dispo="";
}
Veterinaire::Veterinaire(QString nom,QString CIN,int prix,QString numtele,QString adresse,QString email,QString dispo)
{

  this->nom=nom;
  this->CIN=CIN;
  this->prix=prix;
  this->numtele=numtele;
  this->adresse=adresse;
  this->email=email;
  this->dispo=dispo;
}
QString Veterinaire::get_nom(){return  nom;}
QString Veterinaire::get_CIN(){return CIN;}
int Veterinaire::get_prix(){return  prix;}
QString Veterinaire::get_numtele(){return  numtele;}
QString Veterinaire::get_adresse(){return adresse;}
QString Veterinaire::get_email(){return email;}
QString Veterinaire::get_dispo(){return dispo;}


bool Veterinaire::ajoutervet()
{
QSqlQuery query;

query.prepare("INSERT INTO VETERINAIRE (ID, NOM, CIN, PRIX, NUMTELE, ADRESSE, EMAIL, DISPO) "
                    "VALUES (null, :nom, :CIN, :prix, :numtele, :adresse, :email, :dispo)");

query.bindValue(":nom", nom);
query.bindValue(":CIN", CIN);
query.bindValue(":prix", prix);
query.bindValue(":numtele", numtele);
query.bindValue(":adresse", adresse);
query.bindValue(":email", email);
query.bindValue(":dispo", dispo);

     return    query.exec();

}

QSqlQueryModel * Veterinaire::affichervet()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select ID, NOM, CIN, NUMTELE, PRIX , ADRESSE, EMAIL, DISPO from veterinaire");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom et prénom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Numéro de téléphone "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix "));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse "));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Email "));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("Disponibilité "));

    return model;
}

bool Veterinaire::supprimervet(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from veterinaire where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Veterinaire::modifiervet(int idd)
{
    QSqlQuery query;
    query.prepare("update veterinaire set NOM=:nom, CIN=:CIN, PRIX=:prix, NUMTELE=:numtele, ADRESSE=:adresse, EMAIL=:email, DISPO=:dispo where ID=:idd");

    query.bindValue(":idd", idd);
    query.bindValue(":nom", nom);
    query.bindValue(":CIN", CIN);
    query.bindValue(":prix", prix);
    query.bindValue(":numtele", numtele);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);
    query.bindValue(":dispo", dispo);

    return query.exec();

}
//rechercher
QSqlQueryModel * Veterinaire :: recherchervet(QString ch)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    QString str="select ID, NOM, CIN, NUMTELE, PRIX , ADRESSE, EMAIL, DISPO from veterinaire where ID like '"+ch+"%'";
    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Numéro de téléphone "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse "));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Email "));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Disponibilité "));
    return model;
}
