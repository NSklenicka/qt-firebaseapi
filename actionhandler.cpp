#include "actionhandler.h"
#include <QUrl>
#include <firebase.h>
ActionHandler::ActionHandler()
{
    firebase=new Firebase("https://testdb-57c5e-default-rtdb.firebaseio.com/");

    firebase->listenEvents();
    connect(firebase,SIGNAL(eventResponseReady(QString)),this,SLOT(onResponseReady(QString)));
    connect(firebase,SIGNAL(eventDataChanged(DataSnapshot*)),this,SLOT(onDataChanged(DataSnapshot*)));

    firebase->getValue();

}
void ActionHandler::onResponseReady(QString data)
{
    qDebug()<<"answer";
    qDebug()<<data;
}
void ActionHandler::onDataChanged(DataSnapshot *data)
{
    qDebug() << "data changed";
//    QVariantMap dataMap = data->getDataMap();
//    QStringList keys = dataMap.keys();
//    qDebug() << "keys: " << keys.join(", ");
//    qDebug() << "food: " << dataMap.value("Food");

    firebase->getValue();

    //try just getting the data again? like the function above this.

}
