#ifndef EMPLOYEEMODEL_H
#define EMPLOYEEMODEL_H
#include <QRegExp>
#include <QSortFilterProxyModel>

class EmployeeModel : public QSortFilterProxyModel
{
public:
    EmployeeModel(QString prefix);
    void setPrefix(QString prefix);
    QString getPrefix();

protected:
    virtual bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const;
    virtual bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
private:
    QString prefix;
    QRegExp validator;
};

#endif // EMPLOYEEMODEL_H
