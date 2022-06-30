#ifndef CBUTTONDELEGATE_H
#define CBUTTONDELEGATE_H

#include <QItemDelegate>
#include <QStringList>


/*管理table里的自定义控件*/
class GenderButtonDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    GenderButtonDelegate(QObject * parent=0);
    ~GenderButtonDelegate();

    //返回一个编辑控件, 用来编辑指定项的数据
    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    //界面选中, 将Model中数据赋值到控件上
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    //设置model的值
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    //虚拟值
    QStringList m_list;
};

#endif // CBUTTONDELEGATE_H
