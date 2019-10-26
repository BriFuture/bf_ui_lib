#ifndef QTMATERIALRADIOBUTTON_H
#define QTMATERIALRADIOBUTTON_H

#include "lib/qtmaterialcheckable.h"

class QtMaterialRadioButtonPrivate;

#include "builib_components_global.h"
class BUILIB_COMP_EXPORT  QtMaterialRadioButton : public QtMaterialCheckable
{
    Q_OBJECT

public:
    explicit QtMaterialRadioButton(QWidget *parent = nullptr);
    ~QtMaterialRadioButton();

protected:
    void setupProperties();

private:
    Q_DISABLE_COPY(QtMaterialRadioButton)
    Q_DECLARE_PRIVATE(QtMaterialRadioButton)
};

#endif // QTMATERIALRADIOBUTTON_H
