#ifndef VACCIN_H
#define VACCIN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QComboBox>

class Vaccin
{
public:
    Vaccin();
    Vaccin(QString,int,QDate,QString);
    QString get_type();
    QDate get_datev();
    QString get_CIN();
    int get_nb();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * triee(int index);
    QSqlQueryModel * rechercher(QString ch);
    //QSqlQueryModel * rechercher2(QString ch);
private:
    QString type,CIN;
    int nb;
    QDate datev;
};

#endif // VACCIN_H
