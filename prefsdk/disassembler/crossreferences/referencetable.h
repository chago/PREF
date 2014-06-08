#ifndef PREFSDK_REFERENCETABLE_H
#define PREFSDK_REFERENCETABLE_H

#include <QtCore>

namespace PrefSDK
{
    namespace ReferenceTypes
    {
        enum Type
        {
            Flow            = 0x00000000,
            Code            = 0x10000000,
            Data            = 0x20000000,

            Unconditional   = 0x01000000,
            Conditional     = 0x02000000,

            Call            = Code | Unconditional | 0x00000001,
            ConditionalCall = Code | Conditional   | 0x00000002,

            Jump            = Code | Unconditional | 0x00000004,
            ConditionalJump = Code | Conditional   | 0x00000008,

            Address         = Data | 0x00000001,
            Read            = Data | 0x00000002,
            Write           = Data | 0x00000004,
        };
    }

    class ReferenceTable : public QObject
    {
        Q_OBJECT

        public:
            typedef QSet<uint64_t> ReferenceList;
            typedef QHash<uint64_t, ReferenceList> ReferenceMap;

        public:
            explicit ReferenceTable(QObject *parent = 0);
            void addReference(uint64_t address, uint64_t referencedby);
            bool hasReferences(uint64_t address);
            QString displayReferences(uint64_t address);

        private:
            ReferenceMap _references;
    };
}

#endif // PREFSDK_REFERENCETABLE_H
