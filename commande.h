#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class commande
{
   int NUM,PRIX,QUANTITE,PRIX_TOTALE;
   QString ARTICLE;
   QDate datee;
   public:
    commande();
    commande(int,QString,int,int,int);

    commande(int,QString,int,int,int,QDate);
    int get_NUM();
    QString get_ARTICLE();
    int get_PRIX();
    int get_QUANTITE();
    int get_PRIX_TOTAL();
    //QDate get_DATE_CMD();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * Rechercher(QString);

    bool supprimer(int);
     bool modifier (int);
     QSqlQueryModel * afficher_tri_c();
     QSqlQueryModel * afficher_tri_ID_DESC();


};



#endif // COMMANDE_H




