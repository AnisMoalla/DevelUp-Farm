#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "vaccin.h"
#include "veterinaire.h"
#include <QMainWindow>
#include <QSystemTrayIcon>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ajoutervet_clicked();

    void on_pushButton_supp_clicked();

   // void on_pb_load_clicked();


    //void on_pb_modifier_clicked();

   // void on_comboBoxupdate_currentIndexChanged(int);

    void on_pb_modifier_clicked();

    void on_pushButton_2_clicked();

    void on_pb_ask_clicked();

    void on_pb_decr_clicked();

    void on_pb_d2desc_clicked();

    void on_pb_d2asc_clicked();

    void on_rechercher_clicked();


    void on_pushButton_clicked();

    void on_tabvaccin_activated(const QModelIndex &index);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_recherchervet_clicked();

    void on_tabvet_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Vaccin tmpvaccin;
    Veterinaire tmpvet;
    QSystemTrayIcon *mysystem;
};

#endif // MAINWINDOW_H
