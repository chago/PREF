#ifndef DISASSEMBLERVIEWPAGE_H
#define DISASSEMBLERVIEWPAGE_H

#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QtConcurrent/QtConcurrent>
#include "prefsdk/format/formattree.h"
#include "prefsdk/format/formatlist.h"
#include "prefsdk/disassembler/disassembler.h"
#include "crossreferencedialog/crossreferencedialog.h"
#include "viewmodels/functionoffsetmodel/functionoffsetmodel.h"
#include "viewmodels/stringoffsetmodel/stringoffsetmodel.h"
#include "disassemblerhelper.h"
#include "elaboratetoolbar.h"

using namespace PrefSDK;

namespace Ui {
class DisassemblerViewPage;
}

class DisassemblerViewPage : public QWidget
{
    Q_OBJECT
    
    public:
        explicit DisassemblerViewPage(QHexEditData *hexeditdata, FormatTree* formattree, QWidget *parent = 0);
        ~DisassemblerViewPage();

    private:
        void createFunctionsMenu();

    private slots:
        void onActStopTriggered();
        void onActDisassembleTriggered();
        void onFunctionsMenuXRefsTriggered();
        void selectVA();
        void on_tvFunctions_customContextMenuRequested(const QPoint &pos);
        void displayDisassembly(quint64 instructionscount);
        void on_tvFunctions_doubleClicked(const QModelIndex &index);

    private:
        Ui::DisassemblerViewPage *ui;
        FormatTree* _formattree;
        StringOffsetModel* _stringrefs;
        FunctionOffsetModel* _functionrefs;
        DisassemblerHelper* _disasmhelper;
        QHexEditData* _hexeditdata;
        ElaborateToolBar* _toolbar;
        QAction* _actgoto;
        QMenu* _functionsmenu;

};

#endif // DISASSEMBLERVIEWPAGE_H