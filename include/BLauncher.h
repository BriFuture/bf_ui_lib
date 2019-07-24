#ifndef BLAUNCHER_H
#define BLAUNCHER_H

#include <QWidget>

namespace Ui {
class BLauncher;
}

class BLauncher : public QWidget
{
    Q_OBJECT

public:
    explicit BLauncher(QWidget *parent = 0);
    ~BLauncher();

private:
    Ui::BLauncher *ui;
};

#endif // BLAUNCHER_H
