#ifndef QTMATERIALAUTOCOMPLETE_H
#define QTMATERIALAUTOCOMPLETE_H

#include "qtmaterialtextfield.h"

class QtMaterialAutoCompletePrivate;

#include "builib_components_global.h"
class BUILIB_COMP_EXPORT  QtMaterialAutoComplete : public QtMaterialTextField
{
    Q_OBJECT

public:
    explicit QtMaterialAutoComplete(QWidget *parent = 0);
    ~QtMaterialAutoComplete();

    void setDataSource(const QStringList &data);

signals:
    void itemSelected(QString);

protected slots:
    void updateResults(QString text);

protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE;
    bool eventFilter(QObject *watched, QEvent *event) Q_DECL_OVERRIDE;

private:
    Q_DISABLE_COPY(QtMaterialAutoComplete)
    Q_DECLARE_PRIVATE(QtMaterialAutoComplete)
};

#endif // QTMATERIALAUTOCOMPLETE_H
