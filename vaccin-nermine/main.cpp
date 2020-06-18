#include "mainwindow.h"
#include <QApplication>
#include "connexion.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    bool test=c.ouvrircnx();
    QMessageBox msg;
    MainWindow w;
    if (test)
    {
    w.show();
    msg.setText("connexion etablie");
    msg.exec();
    }
    else
    {
        msg.setText("connexion echec");
        msg.exec();
    }
    return a.exec();
}
