#ifndef EMPIDMODEL_H
#define EMPIDMODEL_H

#include <QStandardItemModel>
#include <QList>
class empidModel : public QStandardItemModel
{
    Q_OBJECT
private:
    int size;
    bool contains(QString name);
public:
    explicit empidModel(QObject *parent = 0);
    bool AddItem(QString name,int id);
    bool RemoveItem(QModelIndex index);
    QList<int> getCurrentIds();
    void getCurrentIds(QVector<int>& ids);
    void  fill();
    void clear();
signals:

public slots:

};

#endif // EMPIDMODEL_H
