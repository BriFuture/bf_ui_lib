#ifndef BLOADINGWIDGET_H
#define BLOADINGWIDGET_H

#include <QWidget>

namespace Ui {
class BLoadingWidget;
}

class BLoadingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BLoadingWidget(QWidget *parent = 0);
    ~BLoadingWidget();

private:
    Ui::BLoadingWidget *ui;
};

#endif // BLOADINGWIDGET_H
