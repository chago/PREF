#ifndef BINARYVIEWPAGE_H
#define BINARYVIEWPAGE_H

#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QtConcurrent/QtConcurrent>
#include "prefsdk/io/bytebuffer.h"
#include "displaymodewidget.h"

using namespace PrefSDK;

namespace Ui {
class BinaryViewPage;
}

class BinaryViewPage : public QWidget
{
    Q_OBJECT

    public:
        explicit BinaryViewPage(ByteBuffer *bytebuffer, QWidget *parent = 0);
        ~BinaryViewPage();

    private slots:
        void onCtrlModifier(bool pressed);
        void onShiftModifier(bool pressed);

    protected:
        virtual void keyPressEvent(QKeyEvent* event);
        virtual void keyReleaseEvent(QKeyEvent* event);

    signals:
        void gotoTriggered(qint64);

    private:
        Ui::BinaryViewPage *ui;
        ByteBuffer* _bytebuffer;
        bool _ctrlpressed;
        bool _shiftpressed;
};

#endif // BINARYVIEWPAGE_H