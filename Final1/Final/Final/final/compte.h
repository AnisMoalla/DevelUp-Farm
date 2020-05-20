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
     bool modifiercompte(int,QString,QString);
     QSqlQueryModel* cherchercompte(QString index);
     QSqlQueryModel* triecompte(int index);
};

#endif // COMPTE_H
