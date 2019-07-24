#ifndef BUILIB_GLOBAL_H
#define BUILIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BUILIB_LIBRARY)
#  define BUILIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define BUILIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // BUILIB_GLOBAL_H
