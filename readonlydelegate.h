#ifndef READONLYDELEGATE_H
#define READONLYDELEGATE_H

#endif // READONLYDELEGATE_H
#include <QWidget>
#include <QItemDelegate>
#include <QStyleOptionViewItem>
#include <QModelIndex>
class ReadOnlyDelegate: public QItemDelegate
{
public:
    ReadOnlyDelegate(QWidget *parent = NULL):QItemDelegate(parent)
    {}

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,const QModelIndex &index) const override;
};
