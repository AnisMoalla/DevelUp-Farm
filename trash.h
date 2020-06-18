#ifndef TRASH_H
#define TRASH_H

#include <QMainWindow>

namespace Ui {
class trash;
}

class trash : public QMainWindow
{
    Q_OBJECT

public:
    explicit trash(QWidget *parent = nullptr);
    ~trash();

private:
    Ui::trash *ui;
};

#endif // TRASH_H
