#ifndef MODIFIEARTICLE_H
#define MODIFIEARTICLE_H

#include <QDialog>

namespace Ui {
class modifiearticle;
}

class modifiearticle : public QDialog
{
    Q_OBJECT

public:
    explicit modifiearticle(QWidget *parent = nullptr);
    ~modifiearticle();

private:
    Ui::modifiearticle *ui;
};

#endif // MODIFIEARTICLE_H
