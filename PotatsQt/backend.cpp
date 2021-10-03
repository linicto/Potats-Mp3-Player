#include "backend.h"

BackEnd::BackEnd(QObject *parent) : QObject(parent)
{
    albumTitle_ = "N'importe quoi";
}

QString BackEnd::albumTitle()
{
    return albumTitle_;
}
