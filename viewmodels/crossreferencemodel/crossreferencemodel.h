#ifndef CROSSREFERENCEMODEL_H
#define CROSSREFERENCEMODEL_H

#include <QtCore>
#include <QtGui>
#include <QtWidgets>

class CrossReferenceModel : public QAbstractItemModel
{
    Q_OBJECT

    public:
        explicit CrossReferenceModel(QObject *parent = 0);
        void addCrossReference(quint64 va);
        quint64 xrefCount();
    
    public: /* Overriden Methods */
        virtual int columnCount(const QModelIndex& = QModelIndex()) const;
        virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;
        virtual QVariant data(const QModelIndex &index, int role) const;
        virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
        virtual QModelIndex parent(const QModelIndex&) const;
        virtual int rowCount(const QModelIndex& = QModelIndex()) const;
        virtual Qt::ItemFlags flags(const QModelIndex &index) const;

    private:
        QList<quint64> _xreflist;
};

#endif // CROSSREFERENCEMODEL_H