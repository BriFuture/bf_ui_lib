#ifndef BCUSTOMTABWIDGET_H
#define BCUSTOMTABWIDGET_H

#include <QWidget>
#include <QMap>
#include <QIcon>
#include <QListWidgetItem>
#include <qtmaterialiconbutton.h>

#include "builib_global.h"

namespace Ui {
class BCustomTabWidget;
}

class BUILIBSHARED_EXPORT BCustomTabWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BCustomTabWidget(QWidget *parent = nullptr);
    ~BCustomTabWidget();

    void addTab(QWidget *w, const QString &title);
    void addTab(QWidget *w, const QIcon &icon, const QString &title);
    void removeTab(QWidget *w);
    void removeTab(int index);

    void setCurrentIndex(int index);
    inline void setCurrentWidget(QWidget *w) { setCurrentIndex(indexOf(w)); }
    int indexOf(QWidget *w);

private slots:
    void on_sidebar_itemClicked(QListWidgetItem *item);
    void onNavBtnClicked();
private:
    Ui::BCustomTabWidget *ui;
    QtMaterialIconButton *navBtn;
    bool sidebarExpaned;
};

#endif // BCUSTOMTABWIDGET_H
