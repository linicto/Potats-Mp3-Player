#include "backend.h"

BackEnd::BackEnd(QObject *parent) :
    QObject(parent)
{
    m_userName = "test-default-user";
}

QString BackEnd::userName()
{
    return m_userName;
}

void BackEnd::setUserName(const QString &userName)
{
    if (userName == m_userName)
        return;

    m_userName = userName;
    emit userNameChanged();
}
