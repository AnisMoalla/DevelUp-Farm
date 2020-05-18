#ifndef COMPTE_H
#define COMPTE_H
#include<QString>
#include<QSqlQueryModel>

class compte
{int id;
    QString role,pass;
public:
    compte();
     compte(int,QString,QString);
     QSqlQueryModel *affichercompte();
     bool ajoutercompte();
     bool supprimercompte(int);
     bool modifiercompte();
};

#endif // COMPTE_H
