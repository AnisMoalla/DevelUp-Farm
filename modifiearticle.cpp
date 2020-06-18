#include "modifiearticle.h"
#include "ui_modifiearticle.h"

modifiearticle::modifiearticle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifiearticle)
{
    ui->setupUi(this);
}

modifiearticle::~modifiearticle()
{
    delete ui;
}
