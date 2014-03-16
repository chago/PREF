#ifndef DISASSEMBLERVIEWPAGE_H
#define DISASSEMBLERVIEWPAGE_H

#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QtConcurrent/QtConcurrent>
#include "prefsdk/format/formatdefinition.h"
#include "prefsdk/disassembler/disassembler.h"
#include "crossreferencedialog/crossreferencedialog.h"
#include "viewmodels/functionoffsetmodel/functionoffsetmodel.h"
#include "viewmodels/stringoffsetmodel/stringoffsetmodel.h"
#include "disassemblerhelper.h"

using namespace PrefSDK;

namespace Ui {
class DisassemblerViewPage;
}

class DisassemblerViewPage : public QWidget
{
    Q_OBJECT
    
    public:
        explicit DisassemblerViewPage(ByteBuffer *bytebuffer, QWidget *parent = 0);
        void setData(FormatModel* formatmodel, FormatDefinition::Ptr formatdefinition);
        ~DisassemblerViewPage();

    private:
        void createFunctionsMenu();

    private slots:
        void onActStopTriggered();
        void onActDisassembleTriggered();
        void onFunctionsMenuXRefsTriggered();
        void selectVA();
        void on_tvFunctions_customContextMenuRequested(const QPoint &pos);
        void displayDisassembly();
        void resizeColumns();
        void on_tvFunctions_doubleClicked(const QModelIndex &index);

    private:
        Ui::DisassemblerViewPage *ui;
        FormatModel* _formatmodel;
        StringOffsetModel* _stringrefs;
        FunctionOffsetModel* _functionrefs;
        DisassemblerHelper* _disasmhelper;
        FormatDefinition::Ptr _formatdefinition;
        ByteBuffer* _bytebuffer;
        QToolBar* _toolbar;
        QAction* _actstop;
        QAction* _actdisassemble;
        QAction* _actgoto;
        QMenu* _functionsmenu;

};

#endif // DISASSEMBLERVIEWPAGE_H