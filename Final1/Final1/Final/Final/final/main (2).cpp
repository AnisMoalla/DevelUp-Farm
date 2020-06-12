
#include "mainwindow.h"

#include <QApplication>
#include "connexion.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    connexion c;
     bool test=c.ouvrircnx();
     QMessageBox msg;

    if(test)
    {    w.show();
    msg.setText("connexion etablie");
    msg.exec();
}
else
{
 msg.setText("connexxion echec");
 msg.exec();
    }



    return a.exec();
}
