#ifndef BCARD_H
#define BCARD_H

#include <QFrame>
#include <QPushButton>
#include "builib_global.h"

namespace Ui {
class BCard;
}

class BUILIBSHARED_EXPORT BCard : public QFrame
{
    Q_OBJECT

public:
    explicit BCard(QWidget *parent = 0);
    ~BCard();

    void setCardTitle(const QString &title);
    void setCardDetial(const QString &detail);
    void setActionBtnText(const QString &text);
    void setImage(const QPixmap &img);
    void setImageMaxSize(const QSize &size);
    QPushButton *button() const;
private:
    Ui::BCard *ui = nullptr;
};

#endif // BCARD_H
