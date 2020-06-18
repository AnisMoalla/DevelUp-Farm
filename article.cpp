#include "article.h"
#include <QDebug>
#include<QSqlQuery>
#include<QString>
#include<QDate>
#include<QVariant>

article::article()
{
    NOM="";
    IMAGE="";
    PRIX=0;
    FOURNISSEUR="";
    ADRESSE="";
    TELEPHONE="";
    EMAIL="";
 }
 article::article(QString NOM,QString IMAGE,int PRIX,QString FOURNISSEUR,QString ADRESSE,QString TELEPHONE,QString EMAIL)
    {
      this->NOM=NOM;
      this->IMAGE=IMAGE;
      this->PRIX=PRIX;
      this->FOURNISSEUR=FOURNISSEUR;
      this->ADRESSE=ADRESSE;
      this->TELEPHONE=TELEPHONE;
      this->EMAIL=EMAIL;

}

 bool article::ajouter(){
     QSqlQuery query;


     query.prepare("INSERT INTO article (nom,fournisseur,prix,adresse,telephone,email,image) "
                      "VALUES (:nom,:fournisseur,:prix,:adresse,:telephone,:email,:image)");

     query.bindValue(":nom", NOM);
       query.bindValue(":image", IMAGE);

       query.bindValue(":prix", PRIX);
     query.bindValue(":fournisseur", FOURNISSEUR);
        query.bindValue(":adresse", ADRESSE);
        query.bindValue(":telephone", TELEPHONE);
        query.bindValue(":email", EMAIL);



       return query.exec();

 }
 QSqlQueryModel * article::afficher()
 {QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("select NOM,IMAGE,PRIX,FOURNISSEUR,ADRESSE,TELEPHONE,EMAIL  from article ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("IMAGE "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("FOURNISSEUR"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("TELEPHONE"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("EMAIL"));


         return model;
 }
 QSqlQueryModel * article::nomall()
 {QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select NOM from article ");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));

     return model;
 }

 bool article::modifier(QString nom)
 {
 QSqlQuery query;
 query.prepare("Update article set image=:image,prix =:prix, fournisseur=:fournisseur ,adresse=:adresse ,telephone=:telephone , email:=email where nom = :nom ");
 query.bindValue(":nom", nom);
 query.bindValue(":image", IMAGE);
 query.bindValue(":PRIX",  PRIX);
 query.bindValue(":fournisseur",  FOURNISSEUR);
 query.bindValue(":adresse",  ADRESSE);
 query.bindValue(":telephone",  TELEPHONE);

 query.bindValue(":email",  EMAIL);



 return    query.exec();
 }
 bool article::supprimer(QString nom)
 {
 QSqlQuery query;


 query.prepare("Delete from article where nom = :nom ");
 query.bindValue(":nom", nom);
 return    query.exec();
 }

 /*
QString article::getNOM(){return  NOM;}
QString article::getImage(){return IMAGE;}
int article::getPRIX(){return  PRIX;}

QString article::getEMAIL(){return EMAIL;}
QString article::get_FOURNISSEUR(){return FOURNISSEUR;}
QString Employe::get_image(){return image;}
void Employe::set_image(QString(image)){this->image=image;}

QSqlQueryModel * Employe::afficher_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select nom_poste from Poste");
    return model;
}


bool Employe::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO Employe (ID, NOM, PRENOM, AGE, EMAIL, DATEC, DATEE , NOM_POSTE , IMAGE) "
                    "VALUES (:id, :nom, :prenom, :age, :email, :datec ,:datee, :nom_poste, :image)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":age", age);
query.bindValue(":email", email);
query.bindValue(":datec", datec);
query.bindValue(":datee", datee);
query.bindValue(":nom_poste", nom_poste);
query.bindValue(":image", image);

return    query.exec();
}





bool Employe::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Employe where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Employe::modifier(int idd,QString nom,QString prenom,int age,QString email,QDate datec,QDate datee, QString nom_poste,QString image)
{ QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE Employe SET NOM=:nom,PRENOM=:prenom, AGE=:age, EMAIL=:email, DATEC=:datec, DATEE=:datee, NOM_POSTE=:nom_poste ,IMAGE=:image  where ID=:id");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
     query.bindValue(":age",age);
     query.bindValue(":email",email);
     query.bindValue(":datec", datec);
     query.bindValue(":datee", datee);
     query.bindValue(":nom_poste", nom_poste);
      query.bindValue(":image", image);


    return query.exec();

}*/
QSqlQueryModel *  article::Rechercher(QString  NOM)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString(NOM);
    model->setQuery("select * from article where (NOM LIKE '"+res+"%' ) or (FOURNISSEUR LIKE '"+res+"%' ) or (ADRESSE LIKE '"+res+"%' )or (EMAIL LIKE '"+res+"%' ) ");


            return  model;


}

QSqlQueryModel * article::trier_PRIX()
{


    QSqlQuery * q = new  QSqlQuery ();
       QSqlQueryModel * model = new  QSqlQueryModel ();
       q->prepare("SELECT * FROM article order by  PRIX desc");
       q->exec();
       model->setQuery(*q);
       return model;
}
