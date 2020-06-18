#ifndef NOURRITURES_H
#define NOURRITURES_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>

#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItemIterator>

class  nourritures
{
    int id_nourriture,quantite_nour, prix_unitaire;
    QString nom;


public:

    nourritures();
    nourritures(int,  QString,int, int);
    int Getid_nourriture();
    void Setid_nourriture(int);
    bool ajouter();
   QSqlQueryModel*  afficher();
   bool supprimer(int id);
    bool modifier(int id);
    QSqlQueryModel* triee(int index);
    QSqlQueryModel *cherchere(QString index);

};


#endif
