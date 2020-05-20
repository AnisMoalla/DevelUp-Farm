#include "panne.h"
#include <QSqlQuery>

Panne::Panne()
{
id=1;
numserie=0;

prix=0;
duree=0;
}
Panne::Panne(int numserie,int id,int prix,int duree)
{
this->id=id;
this->numserie=numserie;

this->prix=prix;
this->duree=duree;
}
int Panne::get_id(){return id;}
int Panne::get_numserie(){return numserie;}

int Panne::get_prix(){return prix;}
int Panne::get_duree(){return duree;}
bool Panne::ajouter()
{
QSqlQuery query;
query.prepare("INSERT INTO panne (id, numserie, prix, duree)"
              "VALUES(:id, :numserie, :prix, :duree)");
QString str1 = QString::number(id);
QString str2 = QString::number(numserie);
QString str3 = QString::number(prix);
QString str4 = QString::number(duree);
query.bindValue(":id",str1);
query.bindValue(":numserie",str2);

query.bindValue(":prix",str3);
query.bindValue(":duree",str4);
return query.exec();
}
QSqlQueryModel * Panne::afficher()
{
QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from panne");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMSERIE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));

model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DUREE"));
return model;
}
bool Panne::modifier(int id,int numserie,int prix,int duree)
{
    QSqlQuery query;

    QString res= QString::number(numserie);

    query.prepare("update panne set ID=:id, PRIX=:prix, DUREE=:duree where NUMSERIE='"+res+"'");
    query.bindValue(":numserie",res);
    query.bindValue(":id",id);

    query.bindValue(":prix",prix);
    query.bindValue(":duree",duree);
    return query.exec();
}
bool Panne::supprimer(int numserie)
{
    QSqlQuery query;
    QString res= QString::number(numserie);

query.prepare("Delete from panne where NUMSERIE = :numserie ");
    query.bindValue(":numserie",res);


    return    query.exec();
    }
QSqlQueryModel * Panne::chercherp(QString index)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString research="select * FROM PANNE where NUMSERIE like '"+index+"%' or ID like '"+index+"%' OR PRIX LIKE '"+index+"%' OR DUREE LIKE '"+index+"%'";
     model->setQuery(research);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMSERIE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DUREE"));
    return model;
}

QSqlQueryModel* Panne::triepn(int index)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    if(index == 0)
    {
        model->setQuery("select *FROM PANNE ORDER BY NUMSERIE ASC");
    }
    else
    {
        model->setQuery("select *FROM PANNE ORDER BY NUMSERIE DESC ");
    }


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMSERIE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DUREE"));
    return model;
}
QSqlQueryModel* Panne::triepp(int index)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    if(index == 0)
    {
        model->setQuery("select *FROM PANNE ORDER BY PRIX ASC");
    }
    else
    {
        model->setQuery("select *FROM PANNE ORDER BY PRIX DESC ");
    }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMSERIE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DUREE"));
    return model;
}
QSqlQueryModel* Panne::triepd(int index)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    if(index == 0)
    {
        model->setQuery("select *FROM PANNE ORDER BY DUREE ASC");
    }
    else
    {
        model->setQuery("select *FROM PANNE ORDER BY DUREE DESC ");
    }
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMSERIE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DUREE"));
    return model;
}

