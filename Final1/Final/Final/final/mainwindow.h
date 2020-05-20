#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "animaux.h"
#include "nourritures.h"
#include <QSystemTrayIcon>
#include <vaccin.h>
#include <veterinaire.h>
#include "equipement.h"
#include "panne.h"
#include "clients.h"
#include "command.h"
#include "compte.h"
#include "personnel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_pushButton_clicked(); //ajout animaux
    // void on_pb_supprimer_clicked();

    // void on_pushButton_ajouter_clicked();
       //a/void on_pushButton_supp_clicked();  //supp animaux

       //void on_pushButton_2_clicked();



       //1/void on_pushButton_5_clicked(); //modif animaux

       //b/void on_ajout_nourr_clicked();

       //c/void on_supp_nourr_clicked();

       //2/void on_comboBox_currentIndexChanged(int index);

       void on_pushButton_2_clicked();

       //void on_comboBox_currentIndexChanged(const QString &arg1);

       //d/void on_pushButton_3_clicked();

       //3/void on_pushButton_6_clicked();

       //4/void on_comboBox_2_currentIndexChanged(int index);

       void on_pushButton_13_clicked();

       void on_pushButton_14_clicked();

       //e/void on_pushButton_8_clicked();

       //5/void on_pushButton_9_clicked();

       void on_table_animaux_activated(const QModelIndex &index);

       void on_table_nourritures_activated(const QModelIndex &index);

       void on_pushButton_16_clicked();

       void on_pb_ajouter_2_clicked();

       void on_pb_modifier_2_clicked();

       void on_pb_supprimer_2_clicked();

       void on_pb_ajoutervet_2_clicked();

       void on_pushButton_supp_5_clicked();

       void on_rechercher_2_clicked();

       void on_tabvaccin_2_activated(const QModelIndex &index);

       void on_pb_ask_2_clicked();

       void on_pb_decr_2_clicked();

       void on_pb_d2asc_2_clicked();

       void on_pb_d2desc_2_clicked();

       void on_pushButton_25_clicked();

       void on_pushButton_vet_clicked();

       //6/void on_pushButton_nour_clicked();

       void on_pushButton_consulter_animaux_clicked();

       void on_pushButton_consulter_vaccin_clicked();

       void on_pushButton_consulter_veto_clicked();

       void on_pushButton_consulter_nourriture_clicked();

       void on_pushButton_50_clicked();

       void on_pushButton_51_clicked();

       void on_pushButton_52_clicked();

       void on_pushButton_53_clicked();

       void on_pushButton_12_clicked();

       void on_pushButton_55_clicked();

       void on_pushButton_56_clicked();

       void on_pushButton_57_clicked();
       /**********************************************/

       void on_pb_ajouter_equipement_3_clicked();

       void on_pb_supprimer_equipement_3_clicked();

       void on_pb_ajouter_panne_3_clicked();

       void on_pb_supprimer_panne_3_clicked();

       void on_pb_modifier_equipement_3_clicked();

       void on_pb_modifier_panne_3_clicked();



       void on_pb_charger_equipement_3_clicked();

       void on_pb_charger_panne_3_clicked();



       void on_comboBox_15_currentIndexChanged(int index);

       void on_printe_3_clicked();

       void on_printp_3_clicked();

       void on_radioButton_24_clicked();

       void on_radioButton_18_clicked();

       void on_radioButton_19_clicked();

       void on_radioButton_20_clicked();

       void on_radioButton_21_clicked();

       void on_radioButton_22_clicked();

       void on_radioButton_23_clicked();

       void on_radioButton_17_clicked();

       void on_lineEdit_7_textChanged(const QString &arg1);

       void on_lineEdit_8_textChanged(const QString &arg1);

       void on_pushButton_consulter_equipement_clicked();

       void on_pushButton_consulter_panne_clicked();

       void on_pushButton_58_clicked();

       void on_pushButton_54_clicked();

       void on_pushButton_equipement_clicked();

       void on_pushButton_panne_clicked();

       void on_pushButton_supp_3_clicked();

       void on_pushButton_15_clicked();

       void on_ajout_nourr_3_clicked();

       void on_pushButton_11_clicked();

       void on_supp_nourr_3_clicked();

       void on_pushButton_59_clicked();

       void on_pushButton_consult_cmds_clicked();

       void on_pushButton_60_clicked();

       void on_pushButton_consult_clients_clicked();

       void on_pushButton_consulter_nourriture_2_clicked();

       void on_pushButton_consulter_nourriture_3_clicked();

       void on_pb_ajoutern_clicked();

           void on_pb_supprimern_clicked();

           void on_pushButtonn_clicked();
            void on_pb_modifiern_clicked();

            void on_pushButtonn_2_clicked();

            void on_pb_ajoutern_3_clicked();

            void on_pb_supprimern_3_clicked();

            void on_pb_modifiern_3_clicked();

            void on_pushButtonn_triC_clicked();

            void on_pushButtonn_triD_clicked();

            void on_pushButtonn_4_clicked();

            void on_radioButtonn_clicked();

            void on_pdfn_clicked();





            void on_pushButton_3_clicked();

            void on_tabequipement_3_clicked(const QModelIndex &index);

            void on_tabpanne_3_clicked(const QModelIndex &index);

            void on_tabclients_clicked(const QModelIndex &index);

            void on_tabcommand_clicked(const QModelIndex &index);
            void afficherlescin();

            void on_pushButton_o61_clicked();

            void on_pushButton_consulter_nourriture_4_clicked();

            void on_pushButton_o2_clicked();

            void on_pushButton_o5_clicked();

            void on_pushButton_o6_clicked();

            void on_pushButton_o_clicked();

            void on_tablepersonnel_clicked(const QModelIndex &index);

            void on_pushButton_36_clicked();

            void on_lineEdit_o_textChanged(const QString &arg1);

            void on_radioButton_o_clicked();

            void on_radioButton_o2_clicked();

            void on_pushButton_consulter_nourriture_6_clicked();

            void on_pushButton_o61_2_clicked();

            void on_pushButton_35_clicked();

            void on_pushButton_o2_2_clicked();

            void on_pushButton_o5_4_clicked();

            void on_pushButton_o_4_clicked();

            void on_pushButton_o6_4_clicked();

            void on_tablecompte_activated(const QModelIndex &index);

            void on_radioButton_o_4_clicked();

            void on_radioButton_o2_4_clicked();

            void on_lineEdit_oo_textChanged(const QString &arg1);

            void on_pushButton_o4_clicked();

            void on_pushButton_consulter_nourriture_19_clicked();

            void on_pushButton_l17_clicked();

            void on_tablecompte_clicked(const QModelIndex &index);

            void on_pdfn_2_clicked();

            void on_pushButton_panne_oo2_clicked();

            void on_pushButton_personnel_o2_clicked();

            void on_pb_charger_client_u4_clicked();

            void on_maile_3_clicked();

            void on_pushButton_mailing_clicked();

            void on_pushButton_61_clicked();



            void on_pushButton_662_clicked();

            void on_mailp_3_clicked();

            void on_pushButton_37_clicked();

            void on_pushButton_10_clicked();

            void on_pushButtonn_nnn5_clicked();

            void on_pushButtonn_nnn5_2_clicked();

            void on_printe_4_clicked();

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *mysystem;

    animaux tmp;
    nourritures tmpn;

    Vaccin tmpvaccin;
    Veterinaire tmpvet;

     Equipement tmpequipement;
     Panne tmppanne;

     clients tmpclients;
     command tmpcommand;

     personnel tmppers;
     compte tmpcompte;

};
#endif // MAINWINDOW_H
