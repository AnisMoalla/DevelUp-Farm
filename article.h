#ifndef ARTICLE_H
#define ARTICLE_H

#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class article
{
    QString NOM,IMAGE,FOURNISSEUR,ADRESSE,TELEPHONE,EMAIL;
    int PRIX;

public:
    article();
    article(QString,QString,int,QString,QString,QString,QString);
    QString getNOM(){return NOM;}
    void setNOM(QString NOM){this->NOM=NOM;}

    QString getIMAGE(){return IMAGE;}
    void setIMAGE(QString IMAGE){this->IMAGE=IMAGE;}

    int getPRIX(){return PRIX;}
    void set_PRIX(int PRIX){this->PRIX=PRIX;}

    QString getFOURNISSEUR(){return FOURNISSEUR;}
    void setFOURNISSEUR(QString FOURNISSEUR){this->FOURNISSEUR=FOURNISSEUR;}

    QString getADRESSE(){return ADRESSE;}
    void setADRESSE(QString ADRESSE){this->ADRESSE=ADRESSE;}

    QString getTELEPHONE(){return TELEPHONE;}
    void setTELEPHONE(QString TELEPHONE){this->TELEPHONE=TELEPHONE;}

    QString getEMAIL(){return EMAIL;}
    void setEMAIL(QString EMAIL){this->EMAIL=EMAIL;}

  bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * nomall();

    bool modifier (QString);
    bool supprimer(QString);

        bool modifier(int,long,QString,QString,QString,QString);
        QSqlQueryModel * afficherfournisseurschercher(int);
        QSqlQueryModel * afficher_fournisseurs_ch(int);

        QSqlQueryModel * trier_PRIX();
        QSqlQueryModel * fournisseurs_equipements();
        QSqlQueryModel * Rechercher(QString);





};
#endif // ARTICLE_H
