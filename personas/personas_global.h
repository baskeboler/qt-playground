#ifndef PERSONAS_GLOBAL_H
#define PERSONAS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PERSONAS_LIBRARY)
#  define PERSONASSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PERSONASSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PERSONAS_GLOBAL_H
