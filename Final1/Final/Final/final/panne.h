#ifndef PANNE_H
#define PANNE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QComboBox>
class Panne
{
public:
    Panne();
    Panne(int,int,int,int);
    int get_id();
    int get_numserie();

    int get_prix();
    int get_duree();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier(int,int,int,int);
    bool supprimer(int);
    QSqlQueryModel* chercherp(QString index);
    QSqlQueryModel* triepn(int index);
    QSqlQueryModel* triepp(int index);
    QSqlQueryModel* triepd(int index);
private:
    int id;
    int numserie;

    int prix;
    int duree;

};

#endif // PANNE_H
