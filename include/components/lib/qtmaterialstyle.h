#ifndef QTMATERIALSTYLE_H
#define QTMATERIALSTYLE_H

#include <QtWidgets/QCommonStyle>
#include "lib/qtmaterialstyle_p.h"

#define MATERIAL_DISABLE_THEME_COLORS \
    if (d->useThemeColors == true) { d->useThemeColors = false; }

class QtMaterialTheme;

#include "builib_components_global.h"
class BUILIB_COMP_EXPORT  QtMaterialStyle : public QCommonStyle
{
    Q_OBJECT

public:
    inline static QtMaterialStyle &instance();

    void setTheme(QtMaterialTheme *theme);
    QColor themeColor(const QString &key) const;

protected:
    const QScopedPointer<QtMaterialStylePrivate> d_ptr;

private:
    Q_DECLARE_PRIVATE(QtMaterialStyle)

    QtMaterialStyle();

    QtMaterialStyle(QtMaterialStyle const &);
    void operator=(QtMaterialStyle const &);
};

inline QtMaterialStyle &QtMaterialStyle::instance()
{
    static QtMaterialStyle instance;
    return instance;
}

#define MaterialThemeColor(key) QtMaterialStyle::instance().themeColor(key)

#endif // QTMATERIALSTYLE_H
