#ifndef BABOUTDIALOG_H
#define BABOUTDIALOG_H

#include <QDialog>
#include "builib_global.h"

namespace Ui {
class BAboutDialog;
}

class BUILIBSHARED_EXPORT BAboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BAboutDialog(QWidget *parent = nullptr);
    ~BAboutDialog();

private:
    Ui::BAboutDialog *ui;
};

#endif // BABOUTDIALOG_H
