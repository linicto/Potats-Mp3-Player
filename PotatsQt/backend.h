#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <qqml.h>

class BackEnd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString albumTitle READ albumTitle NOTIFY albumTitleChanged)
    QML_ELEMENT

public:
    explicit BackEnd(QObject *parent = nullptr);

    QString albumTitle();

signals:
    void albumTitleChanged();

private:
    QString albumTitle_;

};

#endif // BACKEND_H
