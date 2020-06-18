#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "article.h"
#include "commande.h"
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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_table_etudiant_2_activated(const QModelIndex &index);

    void on_tabWidget_3_tabBarClicked(int index);

    void on_tabafficherarticles_tabBarClicked(int index);

    void on_tabWiget3_tabBarClicked(int index);

    void on_radioButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_rech_button_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_comboBox_activated(const QString &arg1);

    void on_ajoutcmdbutton_clicked();

    void on_ajoutcmdButton_clicked();

    void on_ajoutcmd_clicked();

    void on_modifarticle_clicked();

    void on_supparticle_clicked();

    void on_tabarticles_activated(const QModelIndex &index);
    void afficherLesArticles();

    void on_suppcmdbutton_clicked();

    void on_suppppppcmd_clicked();

    void on_tricmdradioButton_3_clicked();

    void on_rech_cmd_clicked();

    void on_supprimercommande_clicked();

    void on_modifcmdbutton_clicked();

    void on_ajoutarticle_clicked();

private:
    Ui::MainWindow *ui;
    article A;
    commande C;
};

#endif // MAINWINDOW_H
