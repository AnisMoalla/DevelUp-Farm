#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include "modifiearticle.h"
#include "article.h"
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
/*#include "animaux.h"
#include "nourritures.h"
#include "vaccin.h"
#include "panne.h"
#include"smtpp.h"
#include "mailing/SmtpMime"
#include "equipement.h"
#include "clients.h"
#include "command.h"
*/
#include "ajoutarticle.h"
#include <QPdfWriter>
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







MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
      ui->tabcommandes ->setModel(C.afficher());
      ui->tabarticles->setModel(A.afficher());
      ui->combo_article->addItem("rim");
       ui->combo_article->addItem("hou");
         // ui->combo_article->setModel(A.nomall());

      ui->combo_article->addItem("testb");
      ui->combo_article->addItem("testc");

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked()
{        ui->tabarticles->setModel(C.afficher());//refresh


   int NUMm, PRIX,QUANTITE,PRIX_TOTALE;
   QString ARTICLE;
   NUMm=ui->txt_num->text().toInt();
   ARTICLE= ui->combo_article->currentText();
   ARTICLE="hou";
   PRIX=ui->txt_prix->text().toInt();
   QUANTITE=ui->txt_quantite->text().toInt();
   QDate dat= QDate::currentDate();
   //QDateTime d= QDateTime::currentDateTime();
   commande C(NUMm,ARTICLE,PRIX,QUANTITE,PRIX_TOTALE,dat);
    bool test=C.ajouter();
    if(test)
  {
    ui->tabcommandes->setModel(C.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter une COMMANDE"),
    QObject::tr("COMMANDE ajoutée.\nClick Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une COMMANDE"),
        QObject::tr("Erreur !.\nClick Cancel to exit."), QMessageBox::Cancel);

  }




void MainWindow::on_rech_button_clicked()
{ QString NOM= ui->rech->text();

    ui->tabarticles->setModel(A.Rechercher(NOM));
}


/*
void MainWindow::on_table_etudiant_2_activated(const QModelIndex &index)
{
    int id=ui->tableproduit->model()->data(index).toString().toInt();
       QString id_prod=QString::number(id);

       QSqlQuery query;
               query.prepare("SELECT * FROM produit where id_produit=:id");
           query.bindValue(":id",id_prod);

   if(query.exec()){
       while(query.next()){
           ui->id_of_product->setText(query.value(0).toString());
           ui->nom->setText(query.value(1).toString());
           ui->marque->setText(query.value(2).toString());
           ui->qt_reap->setText(query.value(3).toString());
           ui->qt_alerte->setText(query.value(4).toString());
       }
   }else {QMessageBox::critical(nullptr, QObject::tr("show error"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);


   }
}*/




/*void MainWindow::on_tabWiget3_tabBarClicked()
{

    ui->setupUi(this);
    ui->tabarticles->setModel(a.afficher());

*/


   /* QString NOM=ui->tabWidget_3->currentWidget()->data(index).toString().toInt();
       QString NOMarticle=QString::QString(NOM);

       QSqlQuery query;
               query.prepare("SELECT * FROM entree where NOMarticle=:NOM");
           query.bindValue(":NOM",NOMarticle);

   if(query.exec()){
       while(query.next()){
           ui->txte_nom->setText(query.value(0).toString());
           ui->txte_image->setText(query.value(1).toString());
           ui->txte_prix->setText(query.value(2).toString());
          ui->txte_fournisseur->setText(query.value(3).toString());
           ui->txte_adresse->setText(query.value(4).toString());
          ui->txte_telephone->setText(query.value(5).toString());
         ui->txte_email->setText(query.value(6).toString());

       }
   }else QMessageBox::critical(nullptr, QObject::tr("show error"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);*/





void MainWindow::on_radioButton_2_clicked()
{
    ui->tabarticles->setModel(A.trier_PRIX());
}

void MainWindow::on_pushButton_4_clicked()
{
    QPdfWriter pdf("C:/Users/USER/Desktop/projet rim/Atelier_Connexion/Atelier_Connexion/pdf/pdf.pdf");
                  QPainter painter(&pdf);
                 int i = 4000;
                      painter.setPen(Qt::blue);
                      painter.setFont(QFont("Arial", 40));
                      painter.drawText(3000,2000,"Liste Des articles");
                      painter.setPen(Qt::black);
                      painter.setFont(QFont("Arial", 30));
                     //painter.drawText(1100,2000,afficheDC);
                      painter.drawRect(100,100,9300,2800);



                      painter.drawRect(0,3000,9600,500);
                      painter.setFont(QFont("Arial", 9));
                      painter.drawText(200,3300,"NOM");
                      painter.drawText(1300,3300,"IMAGE");
                      painter.drawText(2500,3300,"PRIX");
                      painter.drawText(3100,3300,"FOURNISSEUR ");
                      painter.drawText(5100,3300,"ADRESSE ");
                       painter.drawText(6100,3300,"TELEPHONE ");
                        painter.drawText(7100,3300,"EMAIL ");




                      QSqlQuery query;
                      query.prepare("select * from article");

                      query.exec();
                      while (query.next())
                      {
                          painter.drawText(200,i,query.value(0).toString());
                          painter.drawText(1300,i,query.value(1).toString());
                          painter.drawText(2200,i,query.value(2).toString());
                            painter.drawText(2900,i,query.value(3).toString());
                            painter.drawText(3700,i,query.value(4).toString());
                            painter.drawText(6100,i,query.value(5).toString());
                            painter.drawText(8100,i,query.value(6).toString());




                         i = i + 500;
                      }
                      QMessageBox::information(nullptr, QObject::tr("PDF "),
                                        QObject::tr(" PDF ajouté a pfd.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_5_clicked()
{
    QString strStream ;
         QTextStream out (&strStream);

                                const int rowCount = ui->tabarticles->model()->rowCount();
                                const int columnCount = ui->tabarticles->model()->columnCount();
                                QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                                out <<"<html>\n"
                                      "<head>\n"
                                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                    << "<title>ERP - COMmANDE LIST<title>\n "
                                    << "</head>\n"
                                    "<body bgcolor=#ffffff link=#5000A0>\n"
                                    "<h1 style=\"text-align: center;\"><strong> *** Promotions *** "+TT+"</strong></h1>"
                                    "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                                      "</br> </br>";
                                // headers
                                out << "<thead><tr bgcolor=#d6e5ff>";
                                for (int column = 0; column < columnCount; column++)
                                    if (!ui->tabarticles->isColumnHidden(column))
                                        out << QString("<th>%1</th>").arg(ui->tabarticles->model()->headerData(column, Qt::Horizontal).toString());
                                out << "</tr></thead>\n";

                                // data table
                                for (int row = 0; row < rowCount; row++) {
                                    out << "<tr>";
                                    for (int column = 0; column < columnCount; column++) {
                                        if (!ui->tabarticles->isColumnHidden(column)) {
                                            QString data =ui->tabarticles->model()->data(ui->tabarticles->model()->index(row, column)).toString().simplified();
                                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                        }
                                    }
                                    out << "</tr>\n";
                                }
                                out <<  "</table>\n"
                                    "</body>\n"
                                    "</html>\n";

                                QTextDocument *document = new QTextDocument();
                                document->setHtml(strStream);

                                QPrinter printer;

                                QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                                if (dialog->exec() == QDialog::Accepted) {
                                    document->print(&printer);
                                }

                                delete document;
}













void MainWindow::on_supparticle_clicked()
{
    article P;
                   QItemSelectionModel *select = ui->tabarticles->selectionModel();
                   QModelIndexList list;
                   if(select->hasSelection())
                   list=select->selectedRows();



                           for(int i=0; i< list.count(); i++)
                           {
                               int reponse = QMessageBox::question(this, "supprimer ", "Voulez-vous vraiment supprimer cette liste ?", QMessageBox::Yes |  QMessageBox::No);
                                   if (reponse == QMessageBox::Yes)
                                   {
                               P.supprimer(list[i].data().toString());
                           }
                      ui->tabarticles->setModel(P.afficher());
                       }

}



/*

void MainWindow::on_tricmdradioButton_3_clicked()
{
    ui->tabarticles->setModel(C.afficher_tri_ID_DESC());
}*/

void MainWindow::on_rech_cmd_clicked()
{
    QString NOM= ui->rech_2->text();

        ui->tabcommandes->setModel(C.Rechercher(NOM));
}
/*
void MainWindow::on_ajoutcmdbutton_clicked()
{
    int NUMm, PRIX,QUANTITE,PRIX_TOTALE;
    QString ARTICLE;
    NUMm=ui->txt_num->text().toInt();
    ARTICLE= ui->combo_article->currentText();
    ARTICLE="hou";
    PRIX=ui->txt_prix->text().toInt();
    QUANTITE=ui->txt_quantite->text().toInt();
    QDate dat= QDate::currentDate();
   // PRIX_TOTALE=PRIX*QUANTITE;
    //QDateTime d= QDateTime::currentDateTime();
    commande C(NUMm,ARTICLE,PRIX,QUANTITE,PRIX_TOTALE,dat);
     bool test=C.ajouter();
     if(test)
   {
     ui->tabcommandes->setModel(C.afficher());//refresh
     QMessageBox::information(nullptr, QObject::tr("Ajouter une COMMANDE"),
     QObject::tr("COMMANDE ajoutée.\nClick Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(nullptr, QObject::tr("Ajouter une COMMANDE"),
         QObject::tr("Erreur !.\nClick Cancel to exit."), QMessageBox::Cancel);
}*/



void MainWindow::on_supprimercommande_clicked()
{
    commande P;
                   QItemSelectionModel *select = ui->tabcommandes->selectionModel();
                   QModelIndexList list;
                   if(select->hasSelection())
                   list=select->selectedRows();



                           for(int i=0; i< list.count(); i++)
                           {
                               int reponse = QMessageBox::question(this, "supprimer ", "Voulez-vous vraiment supprimer cette liste ?", QMessageBox::Yes |  QMessageBox::No);
                                   if (reponse == QMessageBox::Yes)
                                   {
                               P.supprimer(list[i].data().toString().toInt());
                           }
                      ui->tabcommandes->setModel(P.afficher());
                       }
}

void MainWindow::on_modifcmdbutton_clicked()
{
    QString test="",COMMANDE;
    int NUMm, PRIX,QUANTITE,PRIX_TOTALE;

    if(ui->txt_num->text()!=test){
        NUMm=ui->txt_num->text().toInt();
        COMMANDE= ui->combo_article->currentText();
        //ARTICLE="hou";
        PRIX=ui->txt_prix->text().toInt();
        QUANTITE=ui->txt_quantite->text().toInt();
        QDate dat= QDate::currentDate();
        PRIX_TOTALE=PRIX*QUANTITE;
        commande C(NUMm,ARTICLE,PRIX,QUANTITE,PRIX_TOTALE);


           ui->tabcommandes->setModel(C.afficher());
       QMessageBox msg;
       if(C.modifier(NUMm))
       {msg.setText("commande modifier");
       msg.exec();
       ui->tabcommandes->setModel(C.afficher());
          ui->txt_prix->setText("");
          ui->txt_num->setText("");
          ui->txte_nom->setText("");
          ui->txte_email->setText("");
          ui->txte_image->setText("");
       }else{
           msg.setText("failed to edit");
           msg.exec();  }


    }else{
        QMessageBox::critical(nullptr, QObject::tr("show error"),
                                     QObject::tr("Erreur !.\n"
                                                 "you have to choose from the list."), QMessageBox::Cancel);
    }
}

void MainWindow::on_modifarticle_clicked()
{
    QString test="",ARTICLE;
    int NUMm, PRIX,QUANTITE,PRIX_TOTALE;

    if(ui->txt_num->text()!=test){
        NUMm=ui->txt_num->text().toInt();
        ARTICLE= ui->combo_article->currentText();
        //ARTICLE="hou";
        PRIX=ui->txt_prix->text().toInt();
        QUANTITE=ui->txt_quantite->text().toInt();
        QDate dat= QDate::currentDate();
        PRIX_TOTALE=PRIX*QUANTITE;
        commande C(NUMm,ARTICLE,PRIX,QUANTITE,PRIX_TOTALE);


           ui->tabcommandes->setModel(C.afficher());
       QMessageBox msg;
       if(C.modifier(NUMm))
       {msg.setText("commande modifier");
       msg.exec();
       ui->tabcommandes->setModel(C.afficher());
          ui->txt_prix->setText("");
          ui->txt_num->setText("");
          ui->txte_nom->setText("");
          ui->txte_email->setText("");
          ui->txte_image->setText("");
       }else{
           msg.setText("failed to edit");
           msg.exec();  }


    }else{
        QMessageBox::critical(nullptr, QObject::tr("show error"),
                                     QObject::tr("Erreur !.\n"
                                                 "you have to choose from the list."), QMessageBox::Cancel);
    }
   /* QString test="",NOM;
    int prix;
    QString nomm,image,fournisseur,adresse,telephone,email;

    if(ui->txte_nom->text()!=test){
        //nomm=ui->txte_nom->text().toInt();
        image= ui->txte_image->text();
        prix=ui->txte_prix->text().toInt();
        fournisseur= ui->txte_fournisseur->text();
        adresse=ui->txte_adresse->text();
        telephone=ui->txte_telephone->text();
        email=ui->txte_email->text();



       article A(nomm,image,prix,fournisseur,adresse,telephone,email);


           ui->tabcommandes->setModel(C.afficher());
       QMessageBox msg;
       if(A.modifier(nomm))
       {msg.setText("commande modifiée");
       msg.exec();
       ui->tabcommandes->setModel(C.afficher());
          ui->txt_prix->setText("");
          ui->txt_num->setText("");
          ui->txte_nom->setText("");
          ui->txte_email->setText("");
          ui->txte_image->setText("");
       }else{
           msg.setText("failed to edit");
           msg.exec();  }


    }else{
        QMessageBox::critical(nullptr, QObject::tr("show error"),
                                     QObject::tr("Erreur !.\n"
                                                 "you have to choose from the list."), QMessageBox::Cancel);
    }*/
}



void MainWindow::on_ajoutarticle_clicked()
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
       ui->tabarticles->setModel(A.afficher());//refresh
       QMessageBox::information(nullptr, QObject::tr("Ajouter un Article"),
       QObject::tr("article ajoutée.\nClick Cancel to exit."), QMessageBox::Cancel);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Ajouter un ARTICLE"),
           QObject::tr("Erreur !.\nClick Cancel to exit."), QMessageBox::Cancel);

}
