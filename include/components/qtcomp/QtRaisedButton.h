#ifndef QTRAISEDBUTTON_H
#define QTRAISEDBUTTON_H

#include "QPushButton"

class QtRaisedButton : public QPushButton {
public:
    void setForegroundColor(const QColor &color);
    QColor foregroundColor() const;

    void setBackgroundColor(const QColor &color);
    QColor backgroundColor() const;
};

#endif // QTRAISEDBUTTON_H
