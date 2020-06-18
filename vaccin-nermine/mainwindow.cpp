#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vaccin.h"
#include "veterinaire.h"
#include <QMessageBox>
#include <QComboBox>
#include <QDebug>
#include <QSqlQuery>
#include <QDate>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
    mysystem=new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/farmer.ico"));
    mysystem->setVisible(true);
    ui->tabvaccin->setModel(tmpvaccin.afficher());
    ui->tabvet->setModel(tmpvet.affichervet());
    ui->linee->setPlaceholderText("Type");
    //ui->lineEdit_idd->setPlaceholderText(("Id "));
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select NOM from veterinaire");
    ui->comboBox->setModel(model);
    QSqlQuery q;
    QDate n;
    int i=0;
    q.exec("select datev from vaccin");
    while (q.next()) {
        n=q.value("datev").toDate();
        if(n.operator==(n.currentDate())){
            i++;

        }

    }
    qDebug()<<i;
    QString f=QString::number(i);
    mysystem->showMessage(tr("notification"),tr("vacc a faire: %1").arg(i));

}

MainWindow::~MainWindow()
{
    delete ui;
}
//vaccin
//**************************************************************************************
//Ajout vaccin
void MainWindow::on_pb_ajouter_clicked()
{

    QString type= ui->comboBoxtype->currentText();
    QDate datev= ui->dateEdit->date();
    int nb= ui->box_nb->text().toInt();
    QString  CIN= ui->comboBox->currentText();


  Vaccin v(type,nb,datev,CIN);
  bool test=v.ajouter();

  if(test)
{

      ui->tabvaccin->setModel(tmpvaccin.afficher());//refresh
      ui->comboBox->setModel(tmpvet.affichervet());
      QSqlQueryModel *model = new QSqlQueryModel;
      model->setQuery("select NOM from veterinaire");
      ui->comboBox->setModel(model);
QMessageBox::information(nullptr, QObject::tr("Ajouter un vaccin"),
                  QObject::tr("Vaccin ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un vaccin"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
//modif vaccin
void MainWindow::on_pb_modifier_clicked()
{
        int id= ui->lineEdit->text().toInt();
        QString type= ui->comboBoxtype->currentText();
        QDate datev= ui->dateEdit->date();
        int nb= ui->box_nb->text().toInt();
        QString  CIN= ui->comboBox->currentText();

      nb--;
      Vaccin v(type,nb,datev,CIN);

      bool test=v.modifier(id);

      if(test)
    {

          ui->tabvaccin->setModel(tmpvaccin.afficher());//refresh
          ui->comboBox->setModel(tmpvet.affichervet());
          QSqlQueryModel *model = new QSqlQueryModel;
          model->setQuery("select NOM from veterinaire");
          ui->comboBox->setModel(model);
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
void MainWindow::on_pb_supprimer_clicked()
{
Vaccin v;
       QItemSelectionModel *select = ui->tabvaccin->selectionModel();
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
           ui->tabvaccin->setModel(v.afficher());
           QSqlQueryModel *model = new QSqlQueryModel;
           model->setQuery("select NOM from veterinaire");
           ui->comboBox->setModel(model);
           QMessageBox::information(nullptr, QObject::tr("Supprimer un Vaccin"),
           QObject::tr("Vaccin supprimée.\n"
           "Click Cancel to exit."), QMessageBox::Cancel);}}}

//veterinaire
//****************************************************************
//Ajout vet
void MainWindow::on_pb_ajoutervet_clicked()
{

    QString nom= ui->lineEdit_nom->text();
    QString CIN= ui->lineEdit_CIN->toPlainText();
    int prix= ui->SpinBox_prix->text().toInt();
    QString numtele= ui->lineEdit_numtele->toPlainText();
    QString adresse= ui->lineEdit_adresse->text();
    QString email= ui->lineEdit_email->text();
    QString dispo=ui->comboBox_dispo->currentText();
    int testt=0;
    for(int i=0;i<email.length();i++)
    {
        if(email[i]=='@'){
            testt=1;
        }
    }


    Veterinaire vet(nom,CIN,prix,numtele,adresse,email,dispo);

   if(( numtele.length()==8)&&(testt==1))
      {
      if(vet.ajoutervet())
          {
                      ui->tabvet->setModel(tmpvet.affichervet());//refresh

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
   if(testt==0)
   {
       QMessageBox::critical(nullptr, QObject::tr("Email"),
                   QObject::tr("Erreur !.\n"
                               "Email doit contenir @"), QMessageBox::Cancel);
   }

}




//supp vet
void MainWindow::on_pushButton_supp_clicked()
{
Veterinaire vet;
       QItemSelectionModel *select = ui->tabvet->selectionModel();
       QModelIndexList list;
       if(select->hasSelection())
       list=select->selectedRows();
       for(int i=0; i< list.count(); i++)
       {
           vet.supprimervet(list[i].data().toInt());
       }
  ui->tabvet->setModel(vet.affichervet());

}

//modif vet
void MainWindow::on_pushButton_2_clicked()
{
    QString nom= ui->lineEdit_nom->text();
    QString CIN= ui->lineEdit_CIN->toPlainText();
    int prix= ui->SpinBox_prix->text().toInt();
    QString numtele= ui->lineEdit_numtele->toPlainText();
    QString adresse= ui->lineEdit_adresse->text();
    QString email= ui->lineEdit_email->text();
    QString dispo=ui->comboBox_dispo->currentText();
    int id=ui->findvet->text().toInt();

bool test;

  Veterinaire vet(nom,CIN,prix,numtele,adresse,email,dispo);


                test=vet.modifiervet(id);



  if(test)
{

      ui->tabvet->setModel(tmpvet.affichervet());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un vétérinaire"),
                  QObject::tr("Vétérinaire modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un vétérinaire"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}




/*
void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpvaccin.supprimer(id);
if(test)
{ui->tabvaccin->setModel(tmpvaccin.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un vaccin"),
                QObject::tr("Vaccin supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un vaccin"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}*/



/*void MainWindow::on_pb_modifier_clicked()
{

    QString type= ui->comboBoxtype->currentText();
    QDate datev= ui->dateEdit->date();
    int nb= ui->box_nb->text().toInt();
    QDate datevv= ui->dateEdit2->date();
bool test;

  Vaccin v(type,nb,datev,datevv);

           QItemSelectionModel *select = ui->tabvaccin->selectionModel();
           QModelIndexList list;
           if(select->hasSelection())
           list=select->selectedRows();
           for(int i=0; i< list.count(); i++)
           {
                test=v.modifier(list[i].data().toInt());
           }

  if(test)
{

      ui->tabvaccin->setModel(tmpvaccin.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un vaccin"),
                  QObject::tr("Vaccin modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un vaccin"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}*/



//tris
void MainWindow::on_pb_ask_clicked()
{
     ui->tabvaccin->setModel(tmpvaccin.triee(0));
}

void MainWindow::on_pb_decr_clicked()
{
     ui->tabvaccin->setModel(tmpvaccin.triee(1));
}


//recherche
void MainWindow::on_rechercher_clicked()
{
    Vaccin v;
    QString arg2=ui->linee->text();
        this->ui->tabvaccin->setModel(v.rechercher(arg2));

}
void MainWindow::on_recherchervet_clicked()
{
    Veterinaire vet;
    QString arg1=ui->findvet->text();
    this->ui->tabvet->setModel(vet.recherchervet(arg1));

}
//load
void MainWindow::on_pushButton_clicked()
{
    ui->tabvaccin->setModel(tmpvaccin.afficher());

     ui->comboBox->clear();
       QSqlQuery query;

       query.prepare("select CIN from VETERINAIRE");
       if(query.exec()){
           while(query.next()){
              ui->comboBox->addItem(query.value(0).toString());

           }
       }


}

//champs
void MainWindow::on_tabvaccin_activated(const QModelIndex &index)
{

        QString val= ui->tabvaccin->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select * from vaccin where IDV= '"+val+"' ");
        if(query.exec())
        {
            while(query.next())
            {
                ui->comboBoxtype->setCurrentText(query.value(0).toString());
                ui->box_nb->setValue(query.value(1).toString().toInt());
                ui->dateEdit->setDate(query.value(2).toDate());
                ui->dateEdit->setDate(query.value(4).toDate());
                ui->lineEdit->setText(query.value(3).toString());
                //ui->lineEdit_id_2->setText(query.value(0).toString());
                //ui->comboBox->setModel(tmpvet.affichervet());
            }
        }
        else
            QMessageBox::information(nullptr, QObject::tr("Modifier un vaccin"),
                              QObject::tr("erreur.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
  }


void MainWindow::on_tabvet_activated(const QModelIndex &index)
{
    QString val= ui->tabvet->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from veterinaire where id= '"+val+"' ");
    if(query.exec())
    {
        while(query.next())
        {
            ui->findvet->setText(query.value(0).toString());
            ui->lineEdit_nom->setText(query.value(1).toString());
            ui->lineEdit_CIN->setText(query.value(2).toString());
            ui->SpinBox_prix->setValue(query.value(3).toString().toInt());
             ui->lineEdit_numtele->setText(query.value(4).toString());
            ui->lineEdit_adresse->setText(query.value(5).toString());
             ui->lineEdit_email->setText(query.value(6).toString());
            ui->comboBox_dispo->setCurrentText(query.value(7).toString());
        }
    }
    else
        QMessageBox::information(nullptr, QObject::tr("Modifier un veterinaire"),
                          QObject::tr("erreur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

}
