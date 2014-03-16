#ifndef COMPAREVIEW_H
#define COMPAREVIEW_H

#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include "qhexedit/qhexeditdata.h"
#include "views/abstractview.h"
#include "actionwidget/actiontoolbar.h"
#include "prefsdk/sdkmanager.h"

using namespace PrefSDK;

namespace Ui {
class CompareView;
}

class CompareView : public AbstractView
{
    Q_OBJECT

    public:
        explicit CompareView(QString leftfile, QString rightfile, QWidget *parent = 0);
        ~CompareView();

    private slots:
        void compare();
        void updateLeftInfo(qint64 pos);
        void updateRightInfo(qint64 pos);

    private:
        void createToolbar(QHexEdit *hexedit, QWidget* tbcontainer, ActionWidget *actionwidget);

    public: /* Overriden Methods */
        virtual bool canSave() const;

    private:
        Ui::CompareView *ui;
        QHexEditData* _lefthexeditdata;
        QHexEditData* _righthexeditdata;
        QColor _diffcolor;
        QColor _samecolor;
};

#endif // COMPAREVIEW_H