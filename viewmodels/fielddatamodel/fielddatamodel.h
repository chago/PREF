#ifndef FIELDDATAMODEL_H
#define FIELDDATAMODEL_H

#include <QtCore>
#include "prefsdk/datatype.h"
#include "prefsdk/format/elements/formatobject.h"

using namespace PrefSDK;

class FieldDataModel : public QAbstractItemModel
{
    Q_OBJECT

    public:
        explicit FieldDataModel(QObject *parent = 0);

    protected:
        static bool validateValue(QVariant value, DataType::Type type, int base, QSysInfo::Endian endian, QByteArray& ba);
};

#endif // FIELDDATAMODEL_H