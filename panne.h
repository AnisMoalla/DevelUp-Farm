#ifndef PANNE_H
#define PANNE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QComboBox>
#include <QDate>
class Panne
{
public:
    Panne();
    Panne(int,int,int,QDate,QDate);
    int get_id();
    int get_numserie();

    int get_prix();
    QDate get_datedebut();
    QDate get_datefin();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier(int,int,QDate,QDate);
    bool supprimer(int);
    QSqlQueryModel* chercherp(QString index);
    QSqlQueryModel* triepn(int index);
    QSqlQueryModel* triepp(int index);
    QSqlQueryModel* triepd(int index);
private:
    int id;
    int numserie;

    int prix;
    QDate datedebut;
    QDate datefin;

};

#endif // PANNE_H
