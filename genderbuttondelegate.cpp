#include "GenderButtonDelegate.h"
#include <QComboBox>
#include <QDebug>
#include <QTextCodec>



GenderButtonDelegate::GenderButtonDelegate(QObject * parent):QItemDelegate(parent)
{
    m_list << ("男")
           << ("女");
}

GenderButtonDelegate::~GenderButtonDelegate()
{
}


QWidget * GenderButtonDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
    QComboBox* combox = new QComboBox(parent);
    combox->addItems(m_list);
    return combox;
}

void GenderButtonDelegate::setEditorData(QWidget *editor, const QModelIndex &index)const
{
    QString sValue = index.model()->data(index, Qt::EditRole).toString();

    int i = 0;
    for(; i < m_list.count(); i++)
    {
        if(sValue.compare(m_list.at(i)) == 0)
        {
            break;
        }
    }

    QComboBox *combox = static_cast<QComboBox*>(editor);
    combox->setCurrentIndex(i);
}

void GenderButtonDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index)const
{
    QComboBox *combox = static_cast<QComboBox*>(editor);
    QString sValue = combox->currentText();
    model->setData(index, sValue, Qt::EditRole);
}

void GenderButtonDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
    editor->setGeometry(option.rect);
}


