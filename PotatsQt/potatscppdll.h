#ifndef POTATSCPPDLL_H
#define POTATSCPPDLL_H

#include <QObject>
#include <qqml.h>

class PotatsCppDll : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit PotatsCppDll(QObject *parent = nullptr);

signals:

};

#endif // POTATSCPPDLL_H
