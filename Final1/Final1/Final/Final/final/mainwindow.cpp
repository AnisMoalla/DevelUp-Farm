#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "animaux.h"
#include "nourritures.h"
#include <QMessageBox>
#include <QCheckBox>
#include <QSpinBox>
#include <QSqlQuery>
#include <QDebug>
#include "vaccin.h"
#include "ui_mainwindow.h"
#include "equipement.h"
#include "panne.h"
#include <QCoreApplication>
#include"smtpp.h"
#include "mailing/SmtpMime"
#include <QMessageBox>
#include <QComboBox>
#include <QDebug>
#include <QPixmap>
#include <QPrinter>
#include <QDialog>
#include <QPrintDialog>
#include <QPainter>
#include <QPaintEvent>
#include "clients.h"
#include "command.h"
#include <QDate>
#include <QTextDocument>
#include <QWidget>
#include <QSystemTrayIcon>
#include <QTextStream>

int n=0,nb=0;
QString ch="";
QString chaine="";
#include <QStackedWidget>
#include "veterinaire.h"
#include "compte.h"
#include "personnel.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->table_animaux_2->setModel(tmp.afficher());
    ui->table_nourritures_4->setModel(tmpn.afficher());
    mysystem=new QSystemTrayIcon(this);
        mysystem->setIcon(QIcon(":/anim.ico"));
        mysystem->setVisible(true);


        mysystem=new QSystemTrayIcon(this);
          // mysystem->setIcon(QIcon(":/farmer.ico"));
           mysystem->setVisible(true);
           ui->tabvaccin_2->setModel(tmpvaccin.afficher());
           ui->tabvet_2->setModel(tmpvet.affichervet());
           ui->linee_2->setPlaceholderText("Type");
           ui->lineEdit_idd_2->setPlaceholderText(("Id "));

           /*****************************************************************/

           QString windowTitle("DevelUp Farm");

               setWindowIcon(QIcon(":/main/zvenden.png"));
               this->setWindowTitle(windowTitle);
           QPixmap pix2(":/main/equipement.png");
           int w2 = ui->label_40->width();
           int h2 = ui->label_40->height();
           ui->label_40->setPixmap(pix2.scaled(w2,h2,Qt::KeepAspectRatio));
           QPixmap pix3(":/main/panne.png");
           int w3 = ui->label_52->width();
           int h3 = ui->label_52->height();
           ui->label_52->setPixmap(pix3.scaled(w3,h3,Qt::KeepAspectRatio));
           ui->tabequipement_3->setModel(tmpequipement.afficher());

           ui->comboBox_15->setModel(tmpequipement.afficherI());
           QDate dt_cur = QDate::currentDate();
           ui->dateTimeEdit_pa1->setDate(dt_cur);
           ui->dateTimeEdit_pa2->setDate(dt_cur);
           ui->tabpanne_3->setModel(tmppanne.afficher());
           ui->tabequipement_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
           ui->tabpanne_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
           ui->tablepersonnel->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
           ui->tablecompte->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
           ui->tabclients->setModel(tmpclients.afficher());
           ui->tabcommand->setModel(tmpcommand.afficher());
           ui->tablepersonnel->setModel(tmppers.afficherperso());
           ui->tablecompte->setModel(tmpcompte.affichercompte());
           QPixmap pix4(":/main/personnel.jpg");
           int w4 = ui->label_o4_2->width();
           int h4 = ui->label_o4_2->height();
           ui->label_o4_2->setPixmap(pix4.scaled(w4,h4,Qt::KeepAspectRatio));
           ui->lineEdit_o9->setEchoMode(QLineEdit::Password);
           QPixmap pix5(":/main/compte.jpg");
           int w5 = ui->label_o4_7->width();
           int h5 = ui->label_o4_7->height();
           ui->label_o4_7->setPixmap(pix5.scaled(w5,h5,Qt::KeepAspectRatio));
           QPixmap pix6(":/main/client.jpg");
           int w6 = ui->label_n444->width();
           int h6 = ui->label_n444->height();
           ui->label_n444->setPixmap(pix6.scaled(w6,h6,Qt::KeepAspectRatio));
           ui->tabclients->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
           ui->tabcommand->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
           MainWindow::afficherlescin();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
  int id_animaux=ui->le_id_2->text().toInt();
  QString type=ui->le_type_2->currentText();
  QString sexe=ui->le_sexe_2->currentText();
  QDate datea=ui->la_date_2->date();
  //QString vaccin=ui->le_vaccin->currentText();
  int prix=ui->le_prix_2->text().toInt();
  animaux a(id_animaux, type, sexe, datea , prix);
  QMessageBox msg;
   bool test1=a.ajouter();
  if(test1)
  {

          if(test1)
        {

              ui->table_animaux_2->setModel(tmp.afficher());//refresh
               mysystem->showMessage(tr("notification"),tr("animal ajouté avec succes"));
              msg.setText("ajout avec succès");
              msg.exec();

        }
          else
          {
              msg.setText("echec d'ajout");
                    msg.exec();
      }



}

    }


void MainWindow::on_pushButton_supp_3_clicked()
{
animaux a;
       QItemSelectionModel *select = ui->table_animaux_2->selectionModel();
       QModelIndexList list;
       if(select->hasSelection())
       list=select->selectedRows();
       for(int i=0; i< list.count(); i++)
       {
           a.supprimer(list[i].data().toInt());
       }
  ui->table_animaux_2->setModel(tmp.afficher());

   mysystem->showMessage(tr("notification"),tr("animal supprimé avec succes"));

}

void MainWindow::on_pushButton_12_clicked()
{



    int id_animaux= ui->le_id_2->text().toInt();
          QString type= ui->le_type_2->currentText();
           QString sexe= ui->le_sexe_2->currentText();
          QDate datea= ui->la_date_2->date();
         int prix= ui->le_prix_2->text().toInt();


         animaux a(id_animaux, type, sexe, datea , prix);
        bool test=a.modifier(id_animaux);
  QMessageBox msg;
        if(test)
      {

            ui->table_animaux_2->setModel(tmp.afficher());//refresh

            msg.setText("animal modifié");
            msg.exec();

      }
        else
            QMessageBox::critical(nullptr, QObject::tr("modif dun animal"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);





}
/*void MainWindow::on_pushButton_9_clicked()
{
    nermineV nermineV;
    nermineV.setWindowTitle(true);
    nermineV.exec();
}*/

void MainWindow::on_table_animaux_activated(const QModelIndex &index)
{
    QString id= ui->table_animaux_2->model()->data(index).toString();
           QSqlQuery query;
           query.prepare("select * from animaux where id_animaux= '"+id+"' ");
           if(query.exec())
           {
               while(query.next())
               {
                   ui->le_id_2->setText(query.value(0).toString());
                   ui->le_type_2->setCurrentText(query.value(1).toString());
                   ui->le_sexe_2->setCurrentText(query.value(2).toString());

                   ui->la_date_2->setDate(query.value(3).toDate());
                   ui->le_prix_2->setText(query.value(4).toString());


               }
           }
           else
               QMessageBox::information(nullptr, QObject::tr("Modifier un animal"),
                                 QObject::tr("erreur.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_l17_clicked()
{
    QString strStream ;
     QTextStream out (&strStream);

                            const int rowCount = ui->table_animaux_2->model()->rowCount();
                            const int columnCount = ui->table_animaux_2->model()->columnCount();
                            QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                            out <<"<html>\n"
                                  "<head>\n"
                                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                << "<title>ERP - Liste des Animaux<title>\n "
                                << "</head>\n"
                                "<body bgcolor=#ffffff link=#5000A0>\n"
                                "<h1 style=\"text-align: center;\"><strong> *** Animaux *** "+TT+"</strong></h1>"
                                "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                                  "</br> </br>";
                            // headers
                            out << "<thead><tr bgcolor=#d6e5ff>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->table_animaux_2->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->table_animaux_2->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";

                            // data table
                            for (int row = 0; row < rowCount; row++) {
                                out << "<tr>";
                                for (int column = 0; column < columnCount; column++) {
                                    if (!ui->table_animaux_2->isColumnHidden(column)) {
                                        QString data =ui->table_animaux_2->model()->data(ui->table_animaux_2->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_13_clicked()
{
     ui->table_animaux_2->setModel(tmp.triee(0));
}
void MainWindow::on_pushButton_14_clicked()
{
    ui->table_animaux_2->setModel(tmp.triee(1));
}

void MainWindow::on_pushButton_15_clicked()
{
    QString type=ui->lineEdit_3->text();
    ui->table_animaux_2->setModel(tmp.cherchere(type));

}

//**************************************************nourritures***********************************************************
void MainWindow::on_pushButton_55_clicked()
{

        ui->tabvaccin_2->setModel(tmpvaccin.afficher());
}
void MainWindow::on_ajout_nourr_3_clicked()
{
    int id_nourriture=ui->le_id_nourr_3->text().toInt();
    //int id_commande=ui->le_id_comm->text().toInt();
    QString nom=ui->le_nom_3->currentText();

    int quantite_nour=ui->la_qt_3->text().toInt();
    int prix_unitaire=ui->le_prix_un_3->text().toInt();
    nourritures n(id_nourriture,  nom, quantite_nour, prix_unitaire);
    QMessageBox msg;
    if(n.ajouter())
    {
        ui->table_nourritures_4->setModel(tmpn.afficher());//refresh
      msg.setText("ajout avec succès");
      msg.exec();
    }
    else
    { msg.setText("echec d'ajout");
        msg.exec();
    }

}



void MainWindow::on_supp_nourr_3_clicked()
{
    nourritures n;
           QItemSelectionModel *select = ui->table_nourritures_4->selectionModel();
           QModelIndexList list;
           if(select->hasSelection())
           list=select->selectedRows();
           for(int i=0; i< list.count(); i++)
           {
               n.supprimer(list[i].data().toInt());
           }
      ui->table_nourritures_4->setModel(tmpn.afficher());


}

void MainWindow::on_pushButton_11_clicked()
{

    int id_nourriture= ui->le_id_nourr_3->text().toInt();
          QString nom= ui->le_nom_3->currentText();
          int quantite_nour= ui->la_qt_3->text().toInt();
          int prix_unitaire= ui->le_prix_un_3->text().toInt();


         nourritures n(id_nourriture, nom, quantite_nour , prix_unitaire);
        bool test=n.modifier(id_nourriture);
  QMessageBox msg;
        if(test)
      {

            ui->table_nourritures_4->setModel(tmpn.afficher());//refresh

            msg.setText("nourriture modifié");
            msg.exec();

      }
        else
            QMessageBox::critical(nullptr, QObject::tr("modification des données"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_table_nourritures_activated(const QModelIndex &index)
{
    QString id= ui->table_nourritures_4->model()->data(index).toString();
           QSqlQuery query;
           query.prepare("select * from nourritures where id_nourriture= '"+id+"' ");
           if(query.exec())
           {
               while(query.next())
               {
                   ui->le_id_nourr_3->setText(query.value(0).toString());
                   ui->le_nom_3->setCurrentText(query.value(2).toString());
                   ui->la_qt_3->setText(query.value(3).toString());
                   ui->le_prix_un_3->setText(query.value(4).toString());


               }
           }
           else
               QMessageBox::information(nullptr, QObject::tr("modifier un produit"),
                                 QObject::tr("erreur.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
}
//vaccin
//**************************************************************************************
//Ajout vaccin
void MainWindow::on_pb_ajouter_2_clicked()
{
    QString type= ui->comboBoxtype_2->currentText();
    QDate datev= ui->dateEdit_2->date();
    int nb= ui->box_nb_2->text().toInt();
    QDate datevv= ui->dateEdit2_2->date();


  Vaccin v(type,nb,datev,datevv);
  bool test=v.ajouter();

  if(test)
{

      ui->tabvaccin_2->setModel(tmpvaccin.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un vaccin"),
                  QObject::tr("Vaccin ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
      mysystem->showMessage(tr("notification"),tr("Ajout avec succes"));


}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un vaccin"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
//modif vaccin
void MainWindow::on_pb_modifier_2_clicked()
{
        int id= ui->lineEdit_4->text().toInt();
        QString type= ui->comboBoxtype_2->currentText();
        QDate datev= ui->dateEdit_2->date();
        int nb= ui->box_nb_2->text().toInt();
        QDate datevv= ui->dateEdit2_2->date();


      Vaccin v(type,nb,datev,datevv);
      bool test=v.modifier(id);

      if(test)
    {

          ui->tabvaccin_2->setModel(tmpvaccin.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Modifier un vaccin"),
                      QObject::tr("Vaccin Modifié.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier un vaccin"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);




}

//supp vaccin
void MainWindow::on_pb_supprimer_2_clicked()
{
Vaccin v;
       QItemSelectionModel *select = ui->tabvaccin_2->selectionModel();
       QModelIndexList list;
       if(select->hasSelection())
       list=select->selectedRows();
       for(int i=0; i< list.count(); i++)
       {
       QMessageBox::StandardButton reply;
       reply = QMessageBox::question(this, "Supprimer Vaccin", "Vous etes sure?",
                                     QMessageBox::Yes|QMessageBox::No);
       if (reply == QMessageBox::Yes) {
           v.supprimer(list[i].data().toInt());
           ui->tabvaccin_2->setModel(v.afficher());
           QMessageBox::information(nullptr, QObject::tr("Supprimer un Vaccin"),
           QObject::tr("Vaccin supprimée.\n"
           "Click Cancel to exit."), QMessageBox::Cancel);}}}
//veterinaire
//****************************************************************
//Ajout vet
void MainWindow::on_pb_ajoutervet_2_clicked()
{

    QString nom= ui->lineEdit_nom_2->text();
    QString prenom= ui->lineEdit_prenom_2->text();
    int prix= ui->SpinBox_prix_2->text().toInt();
    QString numtele= ui->lineEdit_numtele_2->text();
    QString adresse= ui->lineEdit_adresse_2->text();
    QString email= ui->lineEdit_email_2->text();
    QString dispo=ui->comboBox_dispo_2->currentText();


  Veterinaire vet(nom,prenom,prix,numtele,adresse,email,dispo);

   if( numtele.length()==8)
      {
      if(vet.ajoutervet())
          {
                      ui->tabvet_2->setModel(tmpvet.affichervet());//refresh
                QMessageBox::information(nullptr, QObject::tr("Ajouter un veterinaire"),
                      QObject::tr("veterinaire ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
        }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un veterinaire"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
  }
  else
  {
      QMessageBox::critical(nullptr, QObject::tr("Nume telephone "),
                  QObject::tr("Erreur !.\n"
                              "Numéro de téléphone doit égale à 8 chiffres."), QMessageBox::Cancel);
  }

}


//supp vet
void MainWindow::on_pushButton_supp_5_clicked()
{
Veterinaire vet;
       QItemSelectionModel *select = ui->tabvet_2->selectionModel();
       QModelIndexList list;
       if(select->hasSelection())
       list=select->selectedRows();
       for(int i=0; i< list.count(); i++)
       {
           vet.supprimervet(list[i].data().toInt());
       }
  ui->tabvet_2->setModel(vet.affichervet());

}

//modif vet
void MainWindow::on_pushButton_2_clicked()
{
    QString nom= ui->lineEdit_nom_2->text();
    QString prenom= ui->lineEdit_prenom_2->text();
    int prix= ui->SpinBox_prix_2->text().toInt();
    QString numtele= ui->lineEdit_numtele_2->text();
    QString adresse= ui->lineEdit_adresse_2->text();
    QString email= ui->lineEdit_email_2->text();
    QString dispo=ui->comboBox_dispo_2->currentText();
bool test;

  Veterinaire vet(nom,prenom,prix,numtele,adresse,email,dispo);

           QItemSelectionModel *select = ui->tabvet_2->selectionModel();
           QModelIndexList list;
           if(select->hasSelection())
           list=select->selectedRows();
           for(int i=0; i< list.count(); i++)
           {
                test=vet.modifiervet(list[i].data().toInt());
                qDebug() << list[i].data().toInt();
           }

  if(test)
{

      ui->tabvet_2->setModel(tmpvet.affichervet());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un vétérinaire"),
                  QObject::tr("Vétérinaire modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un vétérinaire"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}


//tris
void MainWindow::on_pb_ask_2_clicked()
{
     ui->tabvaccin_2->setModel(tmpvaccin.triee(0));
}

void MainWindow::on_pb_decr_2_clicked()
{
     ui->tabvaccin_2->setModel(tmpvaccin.triee(1));
}

void MainWindow::on_pb_d2desc_2_clicked()
{
    ui->tabvaccin_2->setModel(tmpvaccin.triee(3));

}

void MainWindow::on_pb_d2asc_2_clicked()
{
    ui->tabvaccin_2->setModel(tmpvaccin.triee(2));

}
//recherche
void MainWindow::on_rechercher_2_clicked()
{
    Vaccin v;
    QString arg1=ui->lineEdit_idd_2->text();
    QString arg2=ui->linee_2->text();

        if ((arg1=="")&&(arg2==""))
        ui->tabvaccin_2->setModel(v.afficher());
        else if((arg1=="")&&(arg2!=""))
        this->ui->tabvaccin_2->setModel(v.rechercher2(arg2));
        else
        this->ui->tabvaccin_2->setModel(v.rechercher(arg1));

}
//load
void MainWindow::on_pushButton_25_clicked()
{
    ui->tabvaccin_2->setModel(tmpvaccin.afficher());
}

//champs
void MainWindow::on_tabvaccin_2_activated(const QModelIndex &index)
{

    QString val= ui->tabvaccin_2->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select * from vaccin where IDV= '"+val+"' ");
        if(query.exec())
        {
            while(query.next())
            {
                ui->comboBoxtype_2->setCurrentText(query.value(0).toString());
                ui->box_nb_2->setValue(query.value(1).toString().toInt());
                ui->dateEdit_2->setDate(query.value(2).toDate());
                ui->dateEdit_2->setDate(query.value(4).toDate());
                ui->lineEdit_4->setText(query.value(3).toString());
                //ui->lineEdit_id_2->setText(query.value(0).toString());
            }
        }
        else
            QMessageBox::information(nullptr, QObject::tr("Modifier un compte"),
                              QObject::tr("erreur.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
  }


































/********************************************************************************/

void MainWindow::on_pushButton_consulter_animaux_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);//accueil->animaux
}
void MainWindow::on_pushButton_consulter_vaccin_clicked()
{
 ui->stackedWidget->setCurrentIndex(3); //accueil->vaccin
}
void MainWindow::on_pushButton_consulter_veto_clicked()
{
 ui->stackedWidget->setCurrentIndex(4); //accueil->veto
}
void MainWindow::on_pushButton_consulter_nourriture_clicked()
{
 ui->stackedWidget->setCurrentIndex(5); //accueil->nourriture
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);//animaux->vaccin
}


void MainWindow::on_pushButton_vet_clicked()
{
  ui->stackedWidget->setCurrentIndex(4);//vaccin->veto
}





void MainWindow::on_pushButton_50_clicked()
{
  ui->stackedWidget->setCurrentIndex(1);   //vaccin->accueil
}

void MainWindow::on_pushButton_51_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);   //veto->accueil
}

void MainWindow::on_pushButton_52_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);   //animaux->accueil
}

void MainWindow::on_pushButton_53_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);   //nourriture->accueil
}





void MainWindow::on_pushButton_56_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);//vaccin->animaux
}

void MainWindow::on_pushButton_57_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);//veto->vaccin
}


/*****************************************************************************************************************************/


void MainWindow::on_pushButton_consulter_equipement_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_consulter_panne_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pb_ajouter_equipement_3_clicked()
{
    int numserie= ui->lineEdit_numserie_3->text().toInt();
        QString type= ui->comboBox_12->currentText();
        QString marque= ui->lineEdit_marque_3->text();
        QString disponibilite= ui->comboBox_11->currentText();
      Equipement e(numserie,type,marque,disponibilite);

          if(marque!="")
    {


                  bool test=e.ajouter();
                  if(test){
    ui->tabequipement_3->setModel(tmpequipement.afficher());//refresh

     ui->comboBox_15->setModel(tmpequipement.afficherI());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un Equipement"),
                      QObject::tr("Equipement ajouté.\n"
                                  "Clicker sur Sortir pour quitter."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un equipement"),
                      QObject::tr("Erreur !.\n"
                                  "L'equipement existe deja."), QMessageBox::Cancel);
}
          else
              QMessageBox::critical(nullptr, QObject::tr("Ajouter un equipement"),
                          QObject::tr("Erreur !.\n"
                                      "La marque ne doit pas etre vide."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_equipement_3_clicked()
{
    Equipement e;
           QItemSelectionModel *select = ui->tabequipement_3->selectionModel();
           QModelIndexList list;
           if(select->hasSelection())
           list=select->selectedRows();
            for(int i=0; i< list.count(); i++){

                QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Supprimer Equipement", "Vous etes sure?",
                                          QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes) {
              e.supprimer(list[i].data().toInt());
              ui->tabequipement_3->setModel(tmpequipement.afficher());//refresh

              ui->comboBox_15->setModel(tmpequipement.afficherI());
              QMessageBox::information(nullptr, QObject::tr("Supprimer un Equipement"),
                                QObject::tr("Equipement supprimée.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);}}}


void MainWindow::on_pb_ajouter_panne_3_clicked()
{
    // int numserie = ui->comboBox_5->currentIndex();
    int id = 1;
       int numserie= ui->lineEdit_numseriep_3->text().toInt();

       int prix= ui->lineEdit_prix_3->text().toInt();
       QDate datedebut= ui->dateTimeEdit_pa1->date();
       QDate datefin=ui->dateTimeEdit_pa2->date();
     Panne p(numserie,id,prix,datedebut,datefin);

bool a= true;

     if(prix>0){

if(datefin >= datedebut){


p.ajouter();
   ui->tabpanne_3->setModel(tmppanne.afficher());//refresh

   QMessageBox::information(nullptr, QObject::tr("Ajouter une Panne"),
                     QObject::tr("Panne ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}
else{QMessageBox::critical(nullptr, QObject::tr("Ajouter une Panne"),
                           QObject::tr("Erreur !.\n"
                                       "La Date fin doit etre superieure du Date d'Aujourd'hui."), QMessageBox::Cancel);}



}
     else
         QMessageBox::critical(nullptr, QObject::tr("Ajouter une Panne"),
                     QObject::tr("Erreur !.\n"
                                 "Le Prix doit etre positif."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_panne_3_clicked()
{
    Panne pp;
           QItemSelectionModel *select = ui->tabpanne_3->selectionModel();
           QModelIndexList list;
           if(select->hasSelection())
           list=select->selectedRows();
           for( int i=0; i< list.count(); i++)
             {  QMessageBox::StandardButton replyy;
           replyy = QMessageBox::question(this, "Supprimer Panne", "Vous etes sure?",
                                         QMessageBox::Yes|QMessageBox::No);
           if (replyy == QMessageBox::Yes) {
             pp.supprimer(list[i].data().toInt());
             ui->tabpanne_3->setModel(tmppanne.afficher());//refresh


             QMessageBox::information(nullptr, QObject::tr("Supprimer un Panne"),
                               QObject::tr("Panne supprimée.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);}}}

void MainWindow::on_pb_modifier_equipement_3_clicked()
{
    int numserie= ui->lineEdit_numserie_3->text().toInt();
        QString type= ui->comboBox_12->currentText();
        QString marque= ui->lineEdit_marque_3->text();
        QString disponibilite= ui->comboBox_11->currentText();

    Equipement p;
    bool atout=p.modifier(numserie,type,marque,disponibilite);
    if(atout)
    {ui->tabequipement_3->setModel(tmpequipement.afficher());
         ui->comboBox_15->setModel(tmpequipement.afficherI());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier un Equipement"),
                                 QObject::tr("Equipement modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un Equipement"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_panne_3_clicked()
{

       double numserie= ui->lineEdit_numseriep_3->text().toInt();

       double prix= ui->lineEdit_prix_3->text().toInt();
       QDate datedebut= ui->dateTimeEdit_pa1->date();
       QDate datefin=ui->dateTimeEdit_pa2->date();

    Panne p;
    bool atout=p.modifier(numserie,prix,datedebut,datefin);
    if(atout)
    {ui->tabpanne_3->setModel(tmppanne.afficher());
        QMessageBox::information(nullptr, QObject::tr("Modifier une Panne"),
                                 QObject::tr("Panne modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier une Panne"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pb_charger_equipement_3_clicked()

    {
    ui->tabequipement_3->setModel(tmpequipement.afficher());

}



void MainWindow::on_pb_charger_panne_3_clicked()
{
    ui->tabpanne_3->setModel(tmppanne.afficher());

}


void MainWindow::on_comboBox_15_currentIndexChanged(int index)
{
    QSqlQuery query;
    int numserie=ui->comboBox_15->currentText().toInt();
   // ui->comboBox->currentText().toInt()
               query.prepare("select * from panne where numserie = :numserie");
                   query.bindValue(":numserie",numserie);

              // qDebug("yomkn here");
               if(query.exec()){
                   //qDebug("mech here");
                   while(query.next()){
           //qDebug("erreur");


                       ui->lineEdit_numseriep_3->setText(query.value(0).toString());

                        qDebug()<<query.value(0).toString();

                        ui->lineEdit_prix_3->setText(query.value(2).toString());

                        ui->dateTimeEdit_pa1->setDate(query.value(3).toDate());


                             ui->dateTimeEdit_pa2->setDate(query.value(4).toDate());


}}
               query.prepare("select * from equipement where numserie = :numserie");
                       query.bindValue(":numserie",numserie);

                  // qDebug("yomkn here");
                   if(query.exec()){
                       //qDebug("mech here");
                       while(query.next()){
               //qDebug("erreur");
                          //ui->comboBox->addItem(query.value(0).toString());

                           ui->lineEdit_numseriep_3->setText(query.value(0).toString());

               }}}

void MainWindow::on_printe_3_clicked()
{
    QString strStream ;
     QTextStream out (&strStream);

                            const int rowCount = ui->tabequipement_3->model()->rowCount();
                            const int columnCount = ui->tabequipement_3->model()->columnCount();
                            QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                            out <<"<html>\n"
                                  "<head>\n"
                                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                << "<title>ERP - Liste des Equipements<title>\n "
                                << "</head>\n"
                                "<body bgcolor=#ffffff link=#5000A0>\n"
                                "<h1 style=\"text-align: center;\"><strong> *** Promotions *** "+TT+"</strong></h1>"
                                "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                                  "</br> </br>";
                            // headers
                            out << "<thead><tr bgcolor=#d6e5ff>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->tabequipement_3->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tabequipement_3->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";

                            // data table
                            for (int row = 0; row < rowCount; row++) {
                                out << "<tr>";
                                for (int column = 0; column < columnCount; column++) {
                                    if (!ui->tabequipement_3->isColumnHidden(column)) {
                                        QString data =ui->tabequipement_3->model()->data(ui->tabequipement_3->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_printp_3_clicked()
{
    QString strStream ;
     QTextStream out (&strStream);

                            const int rowCount = ui->tabpanne_3->model()->rowCount();
                            const int columnCount = ui->tabpanne_3->model()->columnCount();
                            QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                            out <<"<html>\n"
                                  "<head>\n"
                                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                << "<title>ERP - Liste des Pannes<title>\n "
                                << "</head>\n"
                                "<body bgcolor=#ffffff link=#5000A0>\n"
                                "<h1 style=\"text-align: center;\"><strong> Pannes     "+TT+"</strong></h1>"
                                "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                                  "</br> </br>";
                            // headers
                            out << "<thead><tr bgcolor=#d6e5ff>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->tabpanne_3->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tabpanne_3->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";

                            // data table
                            for (int row = 0; row < rowCount; row++) {
                                out << "<tr>";
                                for (int column = 0; column < columnCount; column++) {
                                    if (!ui->tabpanne_3->isColumnHidden(column)) {
                                        QString data =ui->tabpanne_3->model()->data(ui->tabpanne_3->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_maile_3_clicked()
{

ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_mailp_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_pushButton_37_clicked()
{
     ui->stackedWidget->setCurrentIndex(12);
}


void MainWindow::on_pushButton_10_clicked()
{
 ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_pushButtonn_nnn5_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}


void MainWindow::on_pushButtonn_nnn5_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_radioButton_17_clicked()
{
    ui->tabequipement_3->setModel(tmpequipement.triee(0));
}

void MainWindow::on_radioButton_18_clicked()
{
    ui->tabequipement_3->setModel(tmpequipement.triee(1));
}

void MainWindow::on_radioButton_19_clicked()
{
    ui->tabpanne_3->setModel(tmppanne.triepn(0));
}

void MainWindow::on_radioButton_20_clicked()
{
    ui->tabpanne_3->setModel(tmppanne.triepn(1));
}

void MainWindow::on_radioButton_21_clicked()
{
    ui->tabpanne_3->setModel(tmppanne.triepp(0));
}

void MainWindow::on_radioButton_22_clicked()
{
    ui->tabpanne_3->setModel(tmppanne.triepp(1));
}

void MainWindow::on_radioButton_23_clicked()
{
    ui->tabpanne_3->setModel(tmppanne.triepd(0));
}

void MainWindow::on_radioButton_24_clicked()
{
    ui->tabpanne_3->setModel(tmppanne.triepd(1));
}

void MainWindow::on_lineEdit_7_textChanged(const QString &index)
{
    QString str=ui->lineEdit_7->text();

    ui->tabequipement_3->setModel(tmpequipement.cherchere(str));
}

void MainWindow::on_lineEdit_8_textChanged(const QString &index)
{

    QString str=ui->lineEdit_8->text();

    ui->tabpanne_3->setModel(tmppanne.chercherp(str));}



void MainWindow::on_pushButton_58_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_54_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_equipement_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_panne_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_59_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_consult_cmds_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void MainWindow::on_pushButton_60_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_consult_clients_clicked()
{
     ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_consulter_nourriture_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_consulter_nourriture_3_clicked()
{
     ui->stackedWidget->setCurrentIndex(9);
}


/**************************************************************************************/


void MainWindow::on_pb_ajoutern_clicked()
{

    int CIN= ui->lineEdit_CIN->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    int tel= ui->lineEdit_tel->text().toInt();

  clients c(CIN,nom,tel);
  bool test=c.ajouter();
  if(test)
{ui->tabclients->setModel(tmpclients.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un clients"),
                  QObject::tr("clients ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}void MainWindow::on_pb_supprimern_clicked()
{
clients C;
       QItemSelectionModel *select = ui->tabclients->selectionModel();
       QModelIndexList list;
       if(select->hasSelection())
       list=select->selectedRows();
       for(int i=0; i< list.count(); i++)
       {
           C.supprimer(list[i].data().toInt());
       }
  ui->tabclients->setModel(C.afficher());

}


//void MainWindow::on_pb_supprimern_clicked()
//{
//int CIN = ui->lineEdit_CIN->text().toInt();
//bool test=tmpclients.supprimer(CIN);
//if(test)
//{ui->tabclients->setModel(tmpclients.afficher());//refresh
   // QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
           //     QObject::tr("clients supprimé.\n"
                           // "Click Cancel to exit."), QMessageBox::Cancel);

//}
//else
  //  QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
               // QObject::tr("Erreur !.\n"
                           // "Click Cancel to exit."), QMessageBox::Cancel);


//}

void MainWindow::on_pushButtonn_clicked()
{
    ui->tabclients->setModel(tmpclients.afficher());
}









       void MainWindow::on_pb_modifiern_clicked()
       { if(ui->lineEdit_nom->text() == "" && ui->lineEdit_CIN->text() == "")
           {
              QMessageBox::about(this,"Empty values!","Please Enter Values to be Updated!");
           }
         int CIN = ui->lineEdit_CIN->text().toInt();
           QString nom= ui->lineEdit_nom->text();
           int tel= ui->lineEdit_tel->text().toInt();
        clients c(CIN,nom,tel);
        bool test=c.modifier(CIN);
         if(test)
       {

             ui->tabclients->setModel(tmpclients.afficher());//refresh
       QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                       QObject::tr("clients modifié.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
        else
             QMessageBox::critical(nullptr, QObject::tr("modifier un client"),
                       QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

       }

       void MainWindow::on_pb_charger_client_u4_clicked()
       {
           ui->tabclients->setModel(tmpclients.afficher());
       }

//void MainWindow::on_pb_modifiern_clicked()
//{
 //   int CIN = ui->lineEdit_CIN_2->text().toInt();
   // QString nom= ui->lineEdit_nom_3->text();
   // int tel= ui->lineEdit_tel_4->text().toInt();
 // clients c(CIN,nom,tel);
//  bool test=c.modifier(CIN);
//  if(test)
//{

    //  ui->tabclients->setModel(tmpclients.afficher());//refresh
//QMessageBox::information(nullptr, QObject::tr("modifier un client"),
               //   QObject::tr("clients modifié.\n"
           //                   "Click Cancel to exit."), QMessageBox::Cancel);
//
//}
//  else
    //  QMessageBox::critical(nullptr, QObject::tr("modifier un client"),
       //           QObject::tr("Erreur !.\n"
        //                      "Click Cancel to exit."), QMessageBox::Cancel);

//}

void MainWindow::on_pushButtonn_2_clicked()
{

}

 void MainWindow::on_pb_ajoutern_3_clicked()
{

    {
        int ID_COMMANDE = ui->lineEdit_cmd->text().toInt();
       QString  CIN= ui->comboBox->currentText();
           int ID_ANIMAUX= ui->lineEdit_TYPE->text().toInt();
           int QUANTITE= ui->lineEdit_QUANTITE->text().toInt();
int PRIX_TOTAL= ui->lineEdit_QUANTITE_2->text().toInt();
     command M (ID_COMMANDE,CIN,ID_ANIMAUX,QUANTITE,PRIX_TOTAL);
      bool test=M.ajouter();
      if(test)
    {ui->tabcommand->setModel(tmpcommand.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter une COMMANDE"),
                      QObject::tr("COMMANDE ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter une COMMANDE"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


    }
}
void MainWindow::on_pb_supprimern_3_clicked()
{
command M;
       QItemSelectionModel *select = ui->tabcommand->selectionModel();
       QModelIndexList list;
       if(select->hasSelection())
       list=select->selectedRows();
       for(int i=0; i< list.count(); i++)
       {
           M.supprimer(list[i].data().toInt());
       }
  ui->tabcommand->setModel(M.afficher());

}



void MainWindow::on_pb_modifiern_3_clicked()
{int CMD ;
            int PRIX_TOTAL;
   QString CIN = ui->lineEdit_CIN_6->text();
    int ID_ANIMAUX = ui->lineEdit_TYPE_2->text().toInt();
    int QUANTITE= ui->lineEdit_QUANTITE_2->text().toInt();
  command M ( CMD,CIN,ID_ANIMAUX,QUANTITE,PRIX_TOTAL );
  bool test=M.modifier(CIN);
  if(test)
{

     ui->tabcommand->setModel(tmpcommand.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                  QObject::tr("clients modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un client"),
                 QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pushButtonn_triC_clicked()
{
     ui->tabcommand->setModel(tmpcommand.afficher_tri_c());

}

void MainWindow::on_pushButtonn_triD_clicked()
{
    ui->tabcommand->setModel(tmpcommand.afficher_tri_ID_DESC());
}



void MainWindow::on_radioButtonn_clicked()
{
     ui->tabclients->setModel(tmpclients.afficher_tri_ID());
}

void MainWindow::on_pushButtonn_4_clicked()
{
    int id=ui->re->text().toInt();
    ui->tabclients->setModel(tmpclients.recherche(id));

}

void MainWindow::on_pdfn_clicked()
{
    QString strStream ;
     QTextStream out (&strStream);

                            const int rowCount = ui->tabcommand->model()->rowCount();
                            const int columnCount = ui->tabcommand->model()->columnCount();
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
                                if (!ui->tabcommand->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tabcommand->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";

                            // data table
                            for (int row = 0; row < rowCount; row++) {
                                out << "<tr>";
                                for (int column = 0; column < columnCount; column++) {
                                    if (!ui->tabcommand->isColumnHidden(column)) {
                                        QString data =ui->tabcommand->model()->data(ui->tabcommand->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pdfn_2_clicked()
{
    QString strStream ;
     QTextStream out (&strStream);

                            const int rowCount = ui->tabclients->model()->rowCount();
                            const int columnCount = ui->tabclients->model()->columnCount();
                            QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                            out <<"<html>\n"
                                  "<head>\n"
                                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                << "<title>ERP - Liste des Clients<title>\n "
                                << "</head>\n"
                                "<body bgcolor=#ffffff link=#5000A0>\n"
                                "<h1 style=\"text-align: center;\"><strong> *** Promotions *** "+TT+"</strong></h1>"
                                "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                                  "</br> </br>";
                            // headers
                            out << "<thead><tr bgcolor=#d6e5ff>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->tabclients->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tabclients->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";

                            // data table
                            for (int row = 0; row < rowCount; row++) {
                                out << "<tr>";
                                for (int column = 0; column < columnCount; column++) {
                                    if (!ui->tabclients->isColumnHidden(column)) {
                                        QString data =ui->tabclients->model()->data(ui->tabclients->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_tabequipement_3_clicked(const QModelIndex &index)
{
    QString numserie= ui->tabequipement_3->model()->data(index).toString();
               QSqlQuery query;
    query.prepare("select * from equipement where numserie = :numserie");
           query.bindValue(":numserie",numserie);
    if(query.exec()){
     while(query.next()){

               ui->lineEdit_numserie_3->setText(query.value(0).toString());
                qDebug()<<query.value(0).toString();
                 ui->comboBox_12->clear();

                ui->comboBox_12->addItem(query.value(1).toString());

                if((query.value(1).toString())=="Transport")
                {

                            ui->comboBox_12->addItem("Agriculture");}
                else
                {
                 ui->comboBox_12->addItem("Transport");}
    //qDebug ("here");
    ui->lineEdit_marque_3->setText(query.value(2).toString());
                 ui->comboBox_11->clear();
                 ui->comboBox_11->addItem(query.value(3).toString());
                 if((query.value(3).toString())=="Disponible")
                 {

                             ui->comboBox_11->addItem("Non Disponible"); }
                 else
                 {
                  ui->comboBox_11->addItem("Disponible");}}}
}

void MainWindow::on_tabpanne_3_clicked(const QModelIndex &index)
{
    QSqlQuery query;
       QString numserie= ui->tabpanne_3->model()->data(index).toString();

       //ui->comboBox->currentText().toInt()
           query.prepare("select * from panne where numserie = :numserie");
               query.bindValue(":numserie",numserie);

          // qDebug("yomkn here");
           if(query.exec()){
               //qDebug("mech here");
               while(query.next()){
       //qDebug("erreur");


                   ui->lineEdit_numseriep_3->setText(query.value(0).toString());

                    qDebug()<<query.value(0).toString();

                    ui->lineEdit_prix_3->setText(query.value(2).toString());

                         ui->dateTimeEdit_pa1->setDate(query.value(3).toDate());


                              ui->dateTimeEdit_pa2->setDate(query.value(4).toDate());


            }
        }
}

void MainWindow::on_tabclients_clicked(const QModelIndex &index)
{
    QSqlQuery query;
       QString CIN= ui->tabclients->model()->data(index).toString();

       //ui->comboBox->currentText().toInt()
           query.prepare("select * from CLIENTS where CIN = :CIN");
               query.bindValue(":CIN",CIN);

          // qDebug("yomkn here");
           if(query.exec()){
               //qDebug("mech here");
               while(query.next()){
       //qDebug("erreur");

                    ui->lineEdit_CIN->setText(query.value(0).toString());
                   ui->lineEdit_nom->setText(query.value(1).toString());

                    qDebug()<<query.value(0).toString();

                    ui->lineEdit_tel->setText(query.value(2).toString());
}}}

void MainWindow::on_tabcommand_clicked(const QModelIndex &index)
{
    QSqlQuery query;
       QString CIN= ui->tabcommand->model()->data(index).toString();

       //ui->comboBox->currentText().toInt()
           query.prepare("select * from COMMANDE where ID_CMD = :CIN");
               query.bindValue(":CIN",CIN);

          // qDebug("yomkn here");
           if(query.exec()){
               //qDebug("mech here");
               while(query.next()){
       //qDebug("erreur");

                    ui->lineEdit_CIN_6->setText(query.value(5).toString());
                   ui->lineEdit_TYPE_2->setText(query.value(1).toString());

                    qDebug()<<query.value(0).toString();

                    ui->lineEdit_QUANTITE_2->setText(query.value(2).toString());
}}
}

void MainWindow::afficherlescin(){
    ui->comboBox->clear();
    QSqlQuery query;
                query.prepare("SELECT CIN FROM CLIENTS");
                if(query.exec()){
                    while(query.next()){
                        ui->comboBox->addItem(query.value(0).toString());


                    }
}

}

void MainWindow::on_pushButton_o61_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_consulter_nourriture_4_clicked()
{
     ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_o2_clicked()
{
            int id= ui->lineEdit_o5->text().toInt();
            QString nom= ui->lineEdit_o10->text();
            QString mail= ui->lineEdit_o11->text();
            QString domaine= ui->comboBox_o2->currentText();
            QString adresse= ui->lineEdit_o12->text();
            QString salaire= ui->lineEdit_o13->text();
            QString role= ui->comboBox_o4->currentText();

          personnel pe(id,nom,mail,domaine,adresse,salaire,role);
          bool test=pe.ajouterperso();
          if(test)
        {

        ui->tablepersonnel->setModel(tmppers.afficherperso());//refresh

        QMessageBox::information(nullptr, QObject::tr("Ajouter un Personnel"),
                          QObject::tr("Personnel ajouté.\n"
                                      "Clicker sur Sortir pour quitter."), QMessageBox::Cancel);

        }
          else
              QMessageBox::critical(nullptr, QObject::tr("Ajouter un Peronnel"),
                          QObject::tr("Erreur !.\n"
                                      "Clicker sur Sortir pour quitter."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_o5_clicked()
{
    int id= ui->lineEdit_o5->text().toInt();
    QString nom= ui->lineEdit_o10->text();
    QString mail= ui->lineEdit_o11->text();
    QString domaine= ui->comboBox_o2->currentText();
    QString adresse= ui->lineEdit_o12->text();
    QString salaire= ui->lineEdit_o13->text();
    QString role= ui->comboBox_o4->currentText();

        personnel pe;
        bool atout=pe.modifierperso(id,nom,mail,domaine,adresse,salaire,role);
        if(atout)
        {ui->tablepersonnel->setModel(tmppers.afficherperso());

            QMessageBox::information(nullptr, QObject::tr("Modifier un Personnel"),
                                     QObject::tr("Personnel modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);}
        else
            QMessageBox::critical(nullptr, QObject::tr("Modifier un Personnel"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_o6_clicked()
{
    personnel pe;
               QItemSelectionModel *select = ui->tablepersonnel->selectionModel();
               QModelIndexList list;
               if(select->hasSelection())
               list=select->selectedRows();
                for(int i=0; i< list.count(); i++){

                    QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Supprimer Personnel", "Vous etes sure?",
                                              QMessageBox::Yes|QMessageBox::No);
                if (reply == QMessageBox::Yes) {
                  pe.supprimerperso(list[i].data().toInt());
                  ui->tablepersonnel->setModel(tmppers.afficherperso());//refresh

                  QMessageBox::information(nullptr, QObject::tr("Supprimer un Personnel"),
                                    QObject::tr("Personnel supprimée.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);}}}



void MainWindow::on_pushButton_o_clicked()
{
    ui->tablepersonnel->setModel(tmppers.afficherperso());
}

void MainWindow::on_tablepersonnel_clicked(const QModelIndex &index)
{
    QSqlQuery query;
       QString id= ui->tablepersonnel->model()->data(index).toString();

       //ui->comboBox->currentText().toInt()
           query.prepare("select * from personnel where id = :id");
               query.bindValue(":id",id);

          // qDebug("yomkn here");
           if(query.exec()){
               //qDebug("mech here");
               while(query.next()){
       //qDebug("erreur");

                   ui->lineEdit_o5->setText(query.value(0).toString());
                   qDebug()<<query.value(0).toString();
                    ui->lineEdit_o10->setText(query.value(1).toString());
                    ui->lineEdit_o11->setText(query.value(2).toString());
                    ui->comboBox_o2->clear();
                    ui->comboBox_o2->addItem(query.value(3).toString());
                    if((query.value(3).toString())=="Nourritures")//Nourrityres Equipements A nimaux lIVRAISON
                    {

                                ui->comboBox_o2->addItem("Equipements");
                     ui->comboBox_o2->addItem("Animaux");
                     ui->comboBox_o2->addItem("Livraison");}
                    else  if((query.value(3).toString())=="Equipements")
                    {
                     ui->comboBox_o2->addItem("Nourritures");
                     ui->comboBox_o2->addItem("Animaux");
                     ui->comboBox_o2->addItem("Livraison");
                    }
                    else  if((query.value(3).toString())=="Animaux")
                    {
                     ui->comboBox_o2->addItem("Nourritures");
                              ui->comboBox_o2->addItem("Equipements");
                      ui->comboBox_o2->addItem("Livraison");;}
                    else  if((query.value(3).toString())=="Livraison")
                    {
                     ui->comboBox_o2->addItem("Nourritures");
                     ui->comboBox_o2->addItem("Equipements");
                     ui->comboBox_o2->addItem("Animaux");}




                    ui->lineEdit_o12->setText(query.value(4).toString());
                    ui->lineEdit_o13->setText(query.value(5).toString());
                    ui->comboBox_o4->clear();
                   ui->comboBox_o4->addItem(query.value(6).toString());

                   if((query.value(6).toString())=="Proprietaire")//pROPRIETAIRE rESPONSABLE oUVRIER
                   {

                               ui->comboBox_o4->addItem("Responsable");
                   ui->comboBox_o4->addItem("Ouvrier");}
                   else if((query.value(6).toString())=="Responsable")
                   {
                       ui->comboBox_o4->addItem("Proprietaire");
                    ui->comboBox_o4->addItem("Ouvrier");}
                   else if((query.value(6).toString())=="Ouvrier")
                   {
                    ui->comboBox_o4->addItem("Proprietaire");
                   ui->comboBox_o4->addItem("Responsable");}





}}}

void MainWindow::on_pushButton_36_clicked()
{
    QString strStream ;
     QTextStream out (&strStream);

                            const int rowCount = ui->tablepersonnel->model()->rowCount();
                            const int columnCount = ui->tablepersonnel->model()->columnCount();
                            QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                            out <<"<html>\n"
                                  "<head>\n"
                                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                << "<title>ERP - Liste des Personnels<title>\n "
                                << "</head>\n"
                                "<body bgcolor=#ffffff link=#5000A0>\n"
                                "<h1 style=\"text-align: center;\"><strong> Personnels     "+TT+"</strong></h1>"
                                "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                                  "</br> </br>";
                            // headers
                            out << "<thead><tr bgcolor=#d6e5ff>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->tablepersonnel->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tablepersonnel->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";

                            // data table
                            for (int row = 0; row < rowCount; row++) {
                                out << "<tr>";
                                for (int column = 0; column < columnCount; column++) {
                                    if (!ui->tablepersonnel->isColumnHidden(column)) {
                                        QString data =ui->tablepersonnel->model()->data(ui->tablepersonnel->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_lineEdit_o_textChanged(const QString &arg1)
{
    QString str=ui->lineEdit_o->text();

    ui->tablepersonnel->setModel(tmppers.chercherperso(str));}



void MainWindow::on_radioButton_o_clicked()
{
     ui->tablepersonnel->setModel(tmppers.triepe(0));
}

void MainWindow::on_radioButton_o2_clicked()
{
     ui->tablepersonnel->setModel(tmppers.triepe(1));
}

void MainWindow::on_pushButton_consulter_nourriture_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_o61_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_35_clicked()
{
    QString strStream ;
     QTextStream out (&strStream);

                            const int rowCount = ui->tablecompte->model()->rowCount();
                            const int columnCount = ui->tablecompte->model()->columnCount();
                            QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                            out <<"<html>\n"
                                  "<head>\n"
                                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                << "<title>ERP - Liste des Personnels<title>\n "
                                << "</head>\n"
                                "<body bgcolor=#ffffff link=#5000A0>\n"
                                "<h1 style=\"text-align: center;\"><strong> Comptes     "+TT+"</strong></h1>"
                                "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                                  "</br> </br>";
                            // headers
                            out << "<thead><tr bgcolor=#d6e5ff>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->tablecompte->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tablecompte->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";

                            // data table
                            for (int row = 0; row < rowCount; row++) {
                                out << "<tr>";
                                for (int column = 0; column < columnCount; column++) {
                                    if (!ui->tablecompte->isColumnHidden(column)) {
                                        QString data =ui->tablecompte->model()->data(ui->tablecompte->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_o2_2_clicked()
{
    int id= ui->lineEdit_o5_4->text().toInt();
    QString role= ui->comboBox_o4_4->currentText();
    QString pass= ui->lineEdit_o222->text();




  compte compte1(id,role,pass);
  bool test=compte1.ajoutercompte();
  if(test)
{

ui->tablecompte->setModel(tmpcompte.affichercompte());//refresh

QMessageBox::information(nullptr, QObject::tr("Ajouter un Compte"),
                  QObject::tr("Compte ajouté.\n"
                              "Clicker sur Sortir pour quitter."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Compte"),
                  QObject::tr("Erreur !.\n"
                              "Clicker sur Sortir pour quitter."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_o5_4_clicked()
{

    int id= ui->lineEdit_o5_4->text().toInt();

        QString pass= ui->lineEdit_o222->text();
        QString role= ui->comboBox_o4_4->currentText();

   compte compte1;
    bool atout=compte1.modifiercompte(id,role,pass);
    if(atout)
    {ui->tablecompte->setModel(tmpcompte.affichercompte());

        QMessageBox::information(nullptr, QObject::tr("Modifier un Compte"),
                                 QObject::tr("Compte modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un Compte"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_o_4_clicked()
{
ui->tablecompte->setModel(tmpcompte.affichercompte());
}

void MainWindow::on_pushButton_o6_4_clicked()
{

    compte compte1;
               QItemSelectionModel *select = ui->tablecompte->selectionModel();
               QModelIndexList list;
               if(select->hasSelection())
               list=select->selectedRows();
                for(int i=0; i< list.count(); i++){

                    QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Supprimer Compte", "Vous etes sure?",
                                              QMessageBox::Yes|QMessageBox::No);
                if (reply == QMessageBox::Yes) {
                  compte1.supprimercompte(list[i].data().toInt());
                  ui->tablecompte->setModel(tmpcompte.affichercompte());//refresh

                  QMessageBox::information(nullptr, QObject::tr("Supprimer un Compte"),
                                    QObject::tr("Compte supprimée.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);}}
}

void MainWindow::on_tablecompte_activated(const QModelIndex &index)
{
    QSqlQuery query;
       QString id= ui->tablecompte->model()->data(index).toString();

       //ui->comboBox->currentText().toInt()
           query.prepare("select * from compte where id = :id");
               query.bindValue(":id",id);

          // qDebug("yomkn here");
           if(query.exec()){
               //qDebug("mech here");
               while(query.next()){
       //qDebug("erreur");

                   ui->lineEdit_o5_4->setText(query.value(0).toString());
                   qDebug()<<query.value(0).toString();
                    ui->lineEdit_o222->setText(query.value(2).toString());



                    ui->comboBox_o4_4->clear();
                   ui->comboBox_o4_4->addItem(query.value(1).toString());

                   if((query.value(1).toString())=="Proprietaire")//pROPRIETAIRE rESPONSABLE oUVRIER
                   {

                               ui->comboBox_o4_4->addItem("Responsable");
                   ui->comboBox_o4_4->addItem("Ouvrier");}
                   else if((query.value(1).toString())=="Responsable")
                   {
                       ui->comboBox_o4_4->addItem("Proprietaire");
                    ui->comboBox_o4_4->addItem("Ouvrier");}
                   else if((query.value(1).toString())=="Ouvrier")
                   {
                    ui->comboBox_o4_4->addItem("Proprietaire");
                   ui->comboBox_o4_4->addItem("Responsable");}





}}
}

void MainWindow::on_radioButton_o_4_clicked()
{
     ui->tablecompte->setModel(tmpcompte.triecompte(0));
}

void MainWindow::on_radioButton_o2_4_clicked()
{
     ui->tablecompte->setModel(tmpcompte.triecompte(1));
}

void MainWindow::on_lineEdit_oo_textChanged(const QString &arg1)
{
    QString str=ui->lineEdit_oo->text();

    ui->tablecompte->setModel(tmpcompte.cherchercompte(str));
}

void MainWindow::on_pushButton_o4_clicked()
{
    bool a = true;

//pushButton_consulter_nourriture_6.setEnabled(false);

    int goin;
    QString  id = ui->lineEdit_o6->text();
    QString roles = ui->comboBox_o->currentText();
    QString passtry = ui->lineEdit_o9->text();
    if(roles=="Proprietaire")
        goin=1;
    if(roles=="Responsable")
        goin=2;
    if(roles=="Ouvrier")
        goin=3;
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select pass from compte where disponibilite='id'");
    if( id!=""){
if(passtry!=""){
    if(id!="" || passtry!=""){
    if(passtry=="oussema"){
        switch (goin){
        case 1:
            ui->stackedWidget->setCurrentIndex(1);
            break;

        case 2:
            ui->pushButton_consulter_nourriture_6->setEnabled(false);
            ui->pushButton_panne_oo2->setEnabled(false);
            ui->stackedWidget->setCurrentIndex(1);
            break;

         case 3:
            ui->pushButton_consulter_animaux->setEnabled(false);
            ui->pushButton_consulter_vaccin->setEnabled(false);
            ui->pushButton_consulter_veto->setEnabled(false);
            ui->pushButton_consulter_nourriture_4->setEnabled(false);
            ui->pushButton_consulter_panne->setEnabled(false);
            ui->pushButton_consulter_nourriture_2->setEnabled(false);
            ui->pushButton_consulter_nourriture_3->setEnabled(false);
            ui->pushButton_consulter_nourriture_6->setEnabled(false);

            ui->pushButton_panne->setEnabled(false);
            ui->stackedWidget->setCurrentIndex(1);
            break;

    }}
                   else{
                       QMessageBox::critical(nullptr, QObject::tr("Connexion"),
                                   QObject::tr("Erreur !\n"
                                               "Vous n'avez pas de compte."), QMessageBox::Cancel);}}

    else{
        QMessageBox::critical(nullptr, QObject::tr("Connexion"),
                    QObject::tr("Erreur !\n"
                                "Veuillez saisir votre ID."), QMessageBox::Cancel);}}
else{
    QMessageBox::critical(nullptr, QObject::tr("Connexion"),
                QObject::tr("Erreur !\n"
                            "Veuillez saisir votre Mot de Passe."), QMessageBox::Cancel);}
}
    else{
        QMessageBox::critical(nullptr, QObject::tr("Connexion"),
                    QObject::tr("Erreur !\n"
                                "Veuillez saisir votre ID et Mot de Passe."), QMessageBox::Cancel);}
}
void MainWindow::on_pushButton_consulter_nourriture_19_clicked()
{ QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Déconnexion", "Vous etes sure?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
      ui->stackedWidget->setCurrentIndex(0);
      ui->lineEdit_o6->setText("");
      ui->lineEdit_o9->setText("");
      }

}



void MainWindow::on_tablecompte_clicked(const QModelIndex &index)
{
    QSqlQuery query;
       QString id= ui->tablecompte->model()->data(index).toString();

       //ui->comboBox->currentText().toInt()
           query.prepare("select * from compte where id = :id");
               query.bindValue(":id",id);

          // qDebug("yomkn here");
           if(query.exec()){
               //qDebug("mech here");
               while(query.next()){
       //qDebug("erreur");

                   ui->lineEdit_o5_4->setText(query.value(0).toString());
                   qDebug()<<query.value(0).toString();

                    ui->lineEdit_o222->setText(query.value(2).toString());
                    ui->comboBox_o4_4->clear();
                    ui->comboBox_o4_4->addItem(query.value(1).toString());


                   if((query.value(1).toString())=="Proprietaire")//pROPRIETAIRE rESPONSABLE oUVRIER
                   {

                               ui->comboBox_o4_4->addItem("Responsable");
                   ui->comboBox_o4_4->addItem("Ouvrier");}
                   else if((query.value(1).toString())=="Responsable")
                   {
                       ui->comboBox_o4_4->addItem("Proprietaire");
                    ui->comboBox_o4_4->addItem("Ouvrier");}
                   else if((query.value(1).toString())=="Ouvrier")
                   {
                    ui->comboBox_o4_4->addItem("Proprietaire");
                   ui->comboBox_o4_4->addItem("Responsable");}





}}
}



void MainWindow::on_pushButton_panne_oo2_clicked()
{
     ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_personnel_o2_clicked()
{
     ui->stackedWidget->setCurrentIndex(10);
}


/*********************************************mail***************************************/

void MainWindow::on_pushButton_mailing_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
        smtp.setUser("develupfarm2a17@gmail.com");
         smtp.setPassword("#metiermailing1");

         MimeMessage message;

         message.setSender(new EmailAddress("develupfarm2a17@gmail", "Admin"));
         message.addRecipient(new EmailAddress(ui->lineEdit_mail1->text(), "anis"));
         message.setSubject(ui->lineEdit_mail2->text());

         MimeText text;
         text.setText(ui->lineEdit_mail3->text());
         message.addPart(&text);

         if( smtp.connectToHost())
         {
          QMessageBox::information(this,"connecté","connecté");
         }
         if(smtp.login())
         {
         QMessageBox::information(this,"logged in","logged in");
         }
          else {
              QMessageBox::information(this," Erreur log in","Erreur log in");
          }
         if(smtp.sendMail(message))
         {
         QMessageBox::information(this,"OK","Enovyé");
         }
         else
         QMessageBox::information(this,"Non","Non enovyé");
         smtp.quit();
}

void MainWindow::on_pushButton_61_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_pushButton_662_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}







void MainWindow::on_printe_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}
