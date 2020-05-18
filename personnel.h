#ifndef PERSONNEL_H
#define PERSONNEL_H
#include<QString>
#include<QSqlQueryModel>
class personnel
{int id;

  QString nom,mail,domaine,adresse,salaire,role;

public:

    personnel();
    personnel(int,QString,QString,QString,QString,QString,QString);
    QSqlQueryModel *afficherperso();
    bool ajouterperso();
    bool supprimerperso(int);
    bool modifierperso();
};

#endif // PERSONNEL_H
