#include "equipement.h"

Equipement::Equipement()
{
numserie=0;
type="";
marque="";
disponibilite="";
}
Equipement::Equipement(int numserie,QString type,QString marque,QString disponibilite)
{
this->numserie=numserie;
this->type=type;
this->marque=marque;
this->disponibilite=disponibilite;
}
int Equipement::get_numserie(){return  numserie;}
QString Equipement::get_type(){return  type;}
QString Equipement::get_marque(){return marque;}
QString Equipement::get_disponibilite(){return disponibilite;}
bool Equipement::ajouter()
{
QSqlQuery query;
QString res = QString::number(numserie);
query.prepare("INSERT INTO equipement (numserie, type, marque, disponibilite) "
                    "VALUES (:numserie, :type, :marque, :disponibilite)");
query.bindValue(":numserie", res);
query.bindValue(":type", type);
query.bindValue(":marque", marque);
query.bindValue(":disponibilite", disponibilite);

return    query.exec();
}

QSqlQueryModel * Equipement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from equipement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMSERIE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MARQUE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DISPONIBILITE"));
    return model;
}
QSqlQueryModel * Equipement::afficherI()
{QSqlQueryModel * model= new QSqlQueryModel();
    QString Non_Disponible="Non Disponible";
model->setQuery("select numserie from equipement where disponibilite='Non Disponible'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMSERIE"));

    return model;
}
bool Equipement::modifier(int numserie,QString type,QString marque,QString disponibilite)
{
    QSqlQuery query;
    QString res= QString::number(numserie);
    query.prepare("update equipement set TYPE=:type, MARQUE=:marque, DISPONIBILITE=:disponibilite where NUMSERIE='"+res+"'");
    query.bindValue(":numserie",res);
    query.bindValue(":marque",marque);
    query.bindValue(":type",type);
    query.bindValue(":disponibilite",disponibilite);
    return query.exec();
}
bool Equipement::supprimer(int numserie)
{
QSqlQuery query;
QString res= QString::number(numserie);
query.prepare("Delete from equipement where NUMSERIE = :numserie ");
query.bindValue(":numserie", res);

return    query.exec();
}
QSqlQueryModel * Equipement::cherchere(QString index)
{QSqlQueryModel * model=new QSqlQueryModel();
    QString research="select * FROM EQUIPEMENT where NUMSERIE like '"+index+"%' or TYPE like '"+index+"%' OR MARQUE LIKE '"+index+"%' OR DISPONIBILITE LIKE '"+index+"%'";
    model->setQuery(research);
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("NUMSERIE"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("MARQUE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("DISPONIBILITE"));
    return model;}
QSqlQueryModel* Equipement::triee(int index)
{ QSqlQueryModel* model = new QSqlQueryModel();
    if(index == 0)
    {model->setQuery("select *FROM EQUIPEMENT ORDER BY NUMSERIE ASC");}
    else
    {model->setQuery("select *FROM EQUIPEMENT ORDER BY NUMSERIE DESC ");}
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("NUMSERIE"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("MARQUE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("DISPONIBILITE"));
    return model;}
