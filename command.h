#ifndef COMMAND_H
#define COMMAND_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
//#include <QDate>
class command
{public:
    command();
    command(int,QString,int,int,int);
    int get_ID_CMD();
    QString get_CIN();
    int get_ID_ANIMAUX();
    int get_QUANTITE();
    int get_PRIX_TOTAL();
    //QDate get_DATE_CMD();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     bool modifier (QString);
     QSqlQueryModel * afficher_tri_c();
     QSqlQueryModel * afficher_tri_ID_DESC();

private:
    int CMD,IANIMAUX,QUANTITE,PRIX_TOTAL;
QString CIN;
};



#endif // COMMAND_H
