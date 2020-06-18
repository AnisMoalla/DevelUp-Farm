#include "trash.h"
#include "ui_trash.h"

trash::trash(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::trash)
{
    ui->setupUi(this);
}

trash::~trash()
{
    delete ui;
}
