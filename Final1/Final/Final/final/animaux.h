#ifndef ANIMAUX_H
#define ANIMAUX_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>

#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItemIterator>
#include <QComboBox>


class  animaux
{
    int id_animaux,prix;
    QString type,sexe;
    QDate datea;

public:

    animaux();
    animaux(int, QString, QString, QDate, int);
    int Getid_animaux();
    void Setid_animaux(int);
    bool ajouter();
   QSqlQueryModel*  afficher();
   bool supprimer(int id);
    bool modifier(int id);
    QSqlQueryModel* triee(int index);
    QSqlQueryModel *cherchere(QString type);

};


#endif // ANIMAUX_H
