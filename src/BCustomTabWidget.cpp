#include "BCustomTabWidget.h"
#include "ui_BCustomTabWidget.h"
#include <QDebug>
#include "lib/qtmaterialtheme.h"

/**
 * TODO add button Top left
*/

BCustomTabWidget::BCustomTabWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCustomTabWidget),
    navBtn(new QtMaterialIconButton(QtMaterialTheme::icon("navigation", "chevron_left"), this)),
    sidebarExpaned(true)
{
    ui->setupUi(this);
    ui->frame->setMaximumWidth(280);
    ui->sidebar->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    ui->sidebar->setFont(QFont())
    connect(navBtn, &QtMaterialIconButton::clicked, this, &BCustomTabWidget::onNavBtnClicked);
    ui->navLayout->addWidget(navBtn);
}

BCustomTabWidget::~BCustomTabWidget()
{
    delete ui;
    delete navBtn;
}

void BCustomTabWidget::addTab(QWidget *w, const QString &title)
{
    addTab(w, QtMaterialTheme::icon("action", "label"), title);
}

void BCustomTabWidget::addTab(QWidget *w, const QIcon &icon, const QString &title)
{
    if(ui->mainWidget->indexOf(w) > -1) {
        return;
    }
    int index = ui->mainWidget->addWidget(w);
    QString name = title;
    if(title.isEmpty()) {
        name = w->windowTitle();
    }
    if(name.isEmpty()) {
        qWarning() << "Empty Title For Widget" << w;
        name = "Not Set";
    }
    QListWidgetItem *item = new QListWidgetItem(icon, title, ui->sidebar);
    ui->sidebar->addItem(item);
}

void BCustomTabWidget::removeTab(QWidget *w)
{
    int index = ui->mainWidget->indexOf(w);
    removeTab(index);
}

/** to show widget as window, after removeTab, call `w.setParent(nullptr);` */
void BCustomTabWidget::removeTab(int index)
{
    if(index == -1) {
        qWarning() << "Remove Widget failed index: " << index;
        return;
    }
    ui->mainWidget->removeWidget(ui->mainWidget->widget(index));
    ui->mainWidget->setCurrentIndex(0);
    ui->sidebar->takeItem(index);
    ui->sidebar->setCurrentRow(0);
}

void BCustomTabWidget::setCurrentIndex(int index)
{
    ui->sidebar->setCurrentRow(index);
    ui->mainWidget->setCurrentIndex(index);
    tabWidgetChanged(ui->mainWidget->widget(index));
}


int BCustomTabWidget::indexOf(QWidget *w)
{
    return ui->mainWidget->indexOf(w);
}

void BCustomTabWidget::setSidebarMaxWidth(int w)
{
    ui->frame->setMaximumWidth(w);
}

void BCustomTabWidget::on_sidebar_itemClicked(QListWidgetItem *item)
{
    Q_UNUSED(item)
    int index = ui->sidebar->currentRow();
    ui->mainWidget->setCurrentIndex(index);
    tabWidgetChanged(ui->mainWidget->widget(index));
}

void BCustomTabWidget::onNavBtnClicked()
{
    sidebarExpaned = !sidebarExpaned;
    if(sidebarExpaned) {
        navBtn->setIcon(QtMaterialTheme::icon("navigation", "chevron_left"));
        ui->frame->setMaximumWidth(280);
    } else {
        navBtn->setIcon(QtMaterialTheme::icon("navigation", "chevron_right"));
        ui->frame->setMaximumWidth(35); // no better approach
    }
}
