#include "ajoutarticle.h"
#include "ui_ajoutarticle.h"
#include "article.h"
#include <QMessageBox>
#include <QCheckBox>
#include <QSpinBox>
#include <QSqlQuery>
#include <QDebug>
#include <QCoreApplication>
#include <QComboBox>
#include <QPixmap>
//#include <QPrinter>
#include <QDialog>
//#include <QPrintDialog>
#include <QPainter>
#include <QPaintEvent>
#include <QDate>
#include <QTextDocument>
#include <QWidget>
#include <QSystemTrayIcon>
#include <QTextStream>
ajoutarticle::ajoutarticle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutarticle)
{
    ui->setupUi(this);
}

ajoutarticle::~ajoutarticle()
{
    delete ui;
}

void ajoutarticle::on_groupBox_clicked()
{




}

void ajoutarticle::on_pushButton_clicked()
{
    int PRIX;
    QString NOM,IMAGE,FOURNISSEUR,ADRESSE,TELEPHONE,EMAIL;
    NOM= ui->txte_nom->text();
    PRIX=ui->txte_prix->text().toInt();
    IMAGE= ui->txte_image->text();
    FOURNISSEUR= ui->txte_fournisseur->text();
    ADRESSE= ui->txte_adresse->text();
    TELEPHONE= ui->txte_telephone->text();
    EMAIL= ui->txte_email->text();
    article A(NOM,IMAGE,PRIX,FOURNISSEUR,ADRESSE,TELEPHONE,EMAIL);
     bool test=A.ajouter();
     if(test)
     {
       //ui->tabcommande->setModel(tmpcommande.afficher());//refresh
       QMessageBox::information(nullptr, QObject::tr("Ajouter un Article"),
       QObject::tr("article ajoutée.\nClick Cancel to exit."), QMessageBox::Cancel);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Ajouter un ARTICLE"),
           QObject::tr("Erreur !.\nClick Cancel to exit."), QMessageBox::Cancel);
}
