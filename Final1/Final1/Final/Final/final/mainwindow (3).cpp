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
#include <QMessageBox>
#include <QComboBox>
#include <QDebug>
#include <QPixmap>
#include <QPrinter>
#include <QDialog>
#include <QPrintDialog>
#include <QPainter>
#include <QPaintEvent>

#include <QStackedWidget>
#include "veterinaire.h"




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


           QPixmap pix2(":/main/img/equipement.png");
           int w2 = ui->label_40->width();
           int h2 = ui->label_40->height();
           ui->label_40->setPixmap(pix2.scaled(w2,h2,Qt::KeepAspectRatio));
           QPixmap pix3(":/main/img/panne.png");
           int w3 = ui->label_52->width();
           int h3 = ui->label_52->height();
           ui->label_52->setPixmap(pix3.scaled(w3,h3,Qt::KeepAspectRatio));
           ui->tabequipement_3->setModel(tmpequipement.afficher());
           ui->comboBox_13->setModel(tmpequipement.afficher());
           ui->comboBox_15->setModel(tmpequipement.afficherI());
           ui->comboBox_14->setModel(tmppanne.afficher());
           ui->tabpanne_3->setModel(tmppanne.afficher());
           ui->tabequipement_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
           ui->tabpanne_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
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
  if(a.ajouter())
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


void MainWindow::on_pushButton_supp_clicked()
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
  ui->table_animaux_2->setModel(a.afficher());

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


void MainWindow::on_pushButton_7_clicked()
{
     ui->table_animaux_2->setModel(tmp.triee(0));
}
void MainWindow::on_pushButton_4_clicked()
{
    ui->table_animaux_2->setModel(tmp.triee(1));
}

void MainWindow::on_pushButton_8_clicked()
{
    QString type=ui->lineEdit_3->text();
    ui->table_animaux_2->setModel(tmpanimaux.cherchere(type));

}

//**************************************************nourritures***********************************************************
void MainWindow::on_pushButton_55_clicked()
{

        ui->tabvaccin_2->setModel(tmpvaccin.afficher());
}
void MainWindow::on_ajout_nourr_clicked()
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



void MainWindow::on_supp_nourr_clicked()
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

void MainWindow::on_pushButton_3_clicked()
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
  ui->stackedWidget->setCurrentIndex(1);//accueil->animaux
}
void MainWindow::on_pushButton_consulter_vaccin_clicked()
{
 ui->stackedWidget->setCurrentIndex(2); //accueil->vaccin
}
void MainWindow::on_pushButton_consulter_veto_clicked()
{
 ui->stackedWidget->setCurrentIndex(3); //accueil->veto
}
void MainWindow::on_pushButton_consulter_nourriture_clicked()
{
 ui->stackedWidget->setCurrentIndex(4); //accueil->nourriture
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);//animaux->vaccin
}


void MainWindow::on_pushButton_vet_clicked()
{
  ui->stackedWidget->setCurrentIndex(3);//vaccin->veto
}





void MainWindow::on_pushButton_50_clicked()
{
  ui->stackedWidget->setCurrentIndex(0);   //vaccin->accueil
}

void MainWindow::on_pushButton_51_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);   //veto->accueil
}

void MainWindow::on_pushButton_52_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);   //animaux->accueil
}

void MainWindow::on_pushButton_53_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);   //nourriture->accueil
}





void MainWindow::on_pushButton_56_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);//vaccin->animaux
}

void MainWindow::on_pushButton_57_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);//veto->vaccin
}


/*****************************************************************************************************************************/


void MainWindow::on_pushButton_consulter_equipement_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_consulter_panne_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pb_ajouter_equipement_3_clicked()
{
    int numserie= ui->lineEdit_numserie_3->text().toInt();
        QString type= ui->comboBox_12->currentText();
        QString marque= ui->lineEdit_marque_3->text();
        QString disponibilite= ui->comboBox_11->currentText();
      Equipement e(numserie,type,marque,disponibilite);
      bool test=e.ajouter();
      if(test)
    {

    ui->tabequipement_3->setModel(tmpequipement.afficher());//refresh
    ui->comboBox_13->setModel(tmpequipement.afficher());//refresh
     ui->comboBox_15->setModel(tmpequipement.afficherI());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un Equipement"),
                      QObject::tr("Equipement ajouté.\n"
                                  "Clicker sur Sortir pour quitter."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un equipement"),
                      QObject::tr("Erreur !.\n"
                                  "Clicker sur Sortir pour quitter."), QMessageBox::Cancel);
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
              ui->comboBox_13->setModel(tmpequipement.afficher());
              ui->comboBox_15->setModel(tmpequipement.afficherI());
              QMessageBox::information(nullptr, QObject::tr("Supprimer un Equipement"),
                                QObject::tr("Equipement supprimée.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);}}}


void MainWindow::on_pb_ajouter_panne_3_clicked()
{
    // int numserie = ui->comboBox_5->currentIndex();
    int id = ui->lineEdit_ID_3->text().toInt();
       int numserie= ui->lineEdit_numseriep_3->text().toInt();

       int prix= ui->lineEdit_prix_3->text().toInt();
       int duree= ui->lineEdit_duree_3->text().toInt();
     Panne p(numserie,id,prix,duree);
     bool test=p.ajouter();
     if(test)
   {

   ui->tabpanne_3->setModel(tmppanne.afficher());//refresh
   ui->comboBox_14->setModel(tmppanne.afficher());
   QMessageBox::information(nullptr, QObject::tr("Ajouter une Panne"),
                     QObject::tr("Panne ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(nullptr, QObject::tr("Ajouter une Panne"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

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
             ui->comboBox_14->setModel(tmppanne.afficher());

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
    int id = ui->lineEdit_ID_3->text().toInt();
       double numserie= ui->lineEdit_numseriep_3->text().toInt();

       double prix= ui->lineEdit_prix_3->text().toInt();
       int duree= ui->lineEdit_duree_3->text().toInt();

    Panne p;
    bool atout=p.modifier(id,numserie,prix,duree);
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

void MainWindow::on_comboBox_13_currentIndexChanged(int index)
{
    QSqlQuery query;
    int numserie=ui->comboBox_13->currentText().toInt();
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

                          ui->comboBox_11->addItem("non"); }
              else
              {
               ui->comboBox_11->addItem("Disponible");}}}}

void MainWindow::on_comboBox_14_currentIndexChanged(int ind)
{
    QSqlQuery query;
       int numserie=ui->comboBox_14->currentText().toInt();

    //ui->comboBox->currentText().toInt()
        query.prepare("select * from panne where numserie = :numserie");
            query.bindValue(":numserie",numserie);

       // qDebug("yomkn here");
        if(query.exec()){
            //qDebug("mech here");
            while(query.next()){
    //qDebug("erreur");

                 ui->lineEdit_ID_3->setText(query.value(1).toString());
                ui->lineEdit_numseriep_3->setText(query.value(0).toString());

                 qDebug()<<query.value(0).toString();

                 ui->lineEdit_prix_3->setText(query.value(2).toString());
ui->lineEdit_duree_3->setText(query.value(3).toString());



            }
        }
}
void MainWindow::on_pb_charger_equipement_3_clicked()

    {
    ui->tabequipement_3->setModel(tmpequipement.afficher());
    ui->comboBox_13->setModel(tmpequipement.afficher());
}



void MainWindow::on_pb_charger_panne_3_clicked()
{
    ui->tabpanne_3->setModel(tmppanne.afficher());
    ui->comboBox_14->setModel(tmppanne.afficher());
}

void MainWindow::on_comboBox_15_currentIndexChanged(int index)
{
    QSqlQuery query;
    int numserie=ui->comboBox_15->currentText().toInt();
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
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog dlg(&printer, this);
    if (dlg.exec() == QDialog::Accepted)
    {
        // calculate the total width/height table would need without scaling
        const int rows = ui->tabequipement_3->model()->rowCount();
        const int cols = ui->tabequipement_3->model()->columnCount();
        double totalWidth = 0.0;
        for (int c = 0; c < cols; ++c)
        {
            totalWidth += ui->tabequipement_3->columnWidth(c);
        }
        double totalHeight = 0.0;
        for (int r = 0; r < rows; ++r)
        {
            totalHeight += ui->tabequipement_3->rowHeight(r);
        }


        // redirect table's painting on a pixmap
        QPixmap pixmap(totalWidth, totalHeight);
        QPainter::setRedirected(ui->tabequipement_3->viewport(), &pixmap);
        QPaintEvent event(QRect(0, 0, totalWidth, totalHeight));
        QApplication::sendEvent(ui->tabequipement_3->viewport(), &event);
        QPainter::restoreRedirected(ui->tabequipement_3->viewport());

        // print scaled pixmap
        QPainter painter(&printer);
        painter.drawPixmap(printer.pageRect(), pixmap, pixmap.rect());

}}

void MainWindow::on_printp_3_clicked()
{
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog dlg(&printer, this);
    if (dlg.exec() == QDialog::Accepted)
    {
        // calculate the total width/height table would need without scaling
        const int rows = ui->tabpanne_3->model()->rowCount();
        const int cols = ui->tabpanne_3->model()->columnCount();
        double totalWidth = 0.0;
        for (int c = 0; c < cols; ++c)
        {
            totalWidth += ui->tabpanne_3->columnWidth(c);
        }
        double totalHeight = 0.0;
        for (int r = 0; r < rows; ++r)
        {
            totalHeight += ui->tabpanne_3->rowHeight(r);
        }

        // redirect table's painting on a pixmap
        QPixmap pixmap(totalWidth, totalHeight);
        QPainter::setRedirected(ui->tabpanne_3->viewport(), &pixmap);
        QPaintEvent event(QRect(0, 0, totalWidth, totalHeight));
        QApplication::sendEvent(ui->tabpanne_3->viewport(), &event);
        QPainter::restoreRedirected(ui->tabpanne_3->viewport());

        // print scaled pixmap
        QPainter painter(&printer);
        painter.drawPixmap(printer.pageRect(), pixmap, pixmap.rect());


}
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
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_54_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_equipement_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_panne_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
