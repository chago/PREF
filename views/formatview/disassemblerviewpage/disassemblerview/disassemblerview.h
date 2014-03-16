#ifndef DISASSEMBLERVIEW_H
#define DISASSEMBLERVIEW_H

#include "disassemblerviewprivate.h"

class DisassemblerView : public QFrame
{
    Q_OBJECT

    public:
        explicit DisassemblerView(QWidget *parent = 0);
        void setLoader(DisassemblerLoader::Ptr dl);
        void setListing(DisassemblerListing::Ptr dl);
        void gotoVA(quint64 va);
        void gotoEP();

    private:
        DisassemblerViewPrivate* _disasmview_p;
        QScrollArea* _scrollarea;
        QScrollBar* _vscrollbar;
        QHBoxLayout* _hlayout;
};

#endif // DISASSEMBLERVIEW_H