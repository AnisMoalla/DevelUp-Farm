#ifndef CLIENTS_H
#define CLIENTS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class clients
{public:
    clients();
    clients(int,QString,int);
    QString get_nom();
    int get_CIN();
    int get_tel();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     bool modifier (int);
      QSqlQueryModel * afficher_tri_ID();
      QSqlQueryModel * recherche(int);
private:
    QString nom;
    int cin,tel;
};

#endif // CLIENTS_H
