#include "panne.h"
#include <QSqlQuery>

Panne::Panne()
{
id=1;
numserie=0;

prix=0;

}
Panne::Panne(int numserie,int id,int prix,QDate datedebut,QDate datefin)
{
this->id=id;
this->numserie=numserie;

this->prix=prix;
this->datedebut=datedebut;
    this->datefin=datefin;
}
int Panne::get_id(){return id;}
int Panne::get_numserie(){return numserie;}

int Panne::get_prix(){return prix;}
QDate Panne::get_datedebut(){return datedebut;}
QDate Panne::get_datefin(){return datefin;}

bool Panne::ajouter()
{
QSqlQuery query;
query.prepare("INSERT INTO panne (numserie, prix, datedebut,datefin)"
              "VALUES(:numserie, :prix, :datedebut, :datefin)");
QString str1 = QString::number(id);
QString str2 = QString::number(numserie);
QString str3 = QString::number(prix);

//query.bindValue(":id",str1);
query.bindValue(":numserie",str2);

query.bindValue(":prix",str3);
query.bindValue(":datedebut",datedebut);
query.bindValue(":datefin",datefin);
return query.exec();
}
QSqlQueryModel * Panne::afficher()
{
QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from panne");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMSERIE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));

model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE DEBUT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE FIN"));
return model;
}
bool Panne::modifier(int numserie,int prix,QDate datedebut,QDate datefin)
{
    QSqlQuery query;

    QString res= QString::number(numserie);

    query.prepare("update panne set ID=:id, PRIX=:prix, DATEDEBUT=:datedebut , DATEFIN=:datefin where NUMSERIE='"+res+"'");
    query.bindValue(":numserie",res);
    //query.bindValue(":id",id);

    query.bindValue(":prix",prix);
    query.bindValue(":datedebut",datedebut);
    query.bindValue(":datefin",datefin);
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
    QString research="select * FROM PANNE where NUMSERIE like '"+index+"%' or ID like '"+index+"%' OR PRIX LIKE '"+index+"%' OR DATEDEBUT LIKE '"+index+"%' OR DATEFIN LIKE '"+index+"%' ";
     model->setQuery(research);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMSERIE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE DEBUT"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE FIN"));
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
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE DEBUT"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE FIN"));
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
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE DEBUT"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE FIN"));
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
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE DEBUT"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE FIN"));
    return model;
}

