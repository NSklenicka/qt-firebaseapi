#ifndef ACTIONHANDLER_H
#define ACTIONHANDLER_H
#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
#include <QDebug>
#include <QString>
#include <datasnapshot.h>
#include <firebase.h>
class ActionHandler:public QObject
{
    Q_OBJECT
public:
    ActionHandler();
public slots:
    void onResponseReady(QString);
    void onDataChanged(DataSnapshot*);
private:
    Firebase *firebase;
};

#endif // ACTIONHANDLER_H
