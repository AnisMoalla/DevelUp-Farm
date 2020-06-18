#ifndef AJOUTARTICLE_H
#define AJOUTARTICLE_H

#include <QDialog>

namespace Ui {
class ajoutarticle;
}

class ajoutarticle : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutarticle(QWidget *parent = nullptr);
    ~ajoutarticle();

private slots:
    void on_groupBox_clicked();

    void on_pushButton_clicked();

private:
    Ui::ajoutarticle *ui;
};

#endif // AJOUTARTICLE_H
