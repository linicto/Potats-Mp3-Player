#ifndef POTATSCPPDLL_H
#define POTATSCPPDLL_H

#include <QList>
#include <QObject>
#include <QString>
#include <qqml.h>

class PotatsCppDll : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QString> albumTitles READ albumTitles)
    QML_ELEMENT
public:
    explicit PotatsCppDll(QObject *parent = nullptr);
    QList<QString> albumTitles();

signals:

private:
    QList<QString> albumTitles_;
};

#endif // POTATSCPPDLL_H
