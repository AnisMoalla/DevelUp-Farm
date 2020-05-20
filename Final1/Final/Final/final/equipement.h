#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QComboBox>

class Equipement
{
public:
    Equipement();
    Equipement(int,QString,QString,QString);
    int get_numserie();
    QString get_type();
    QString get_marque();
    QString get_disponibilite();
    bool ajouter();
    bool modifier();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficherI();
    bool modifier(int,QString,QString,QString);
    bool supprimer(int);
    QSqlQueryModel* cherchere(QString index);
    QSqlQueryModel* triee(int index);
private:
    int numserie;
    QString type;
    QString marque;
    QString disponibilite;
};

#endif // EQUIPEMENT_H
