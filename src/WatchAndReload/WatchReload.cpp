#include <QDebug>
#include "WatchReload.h"
#include "WatchDirPath.h"
#include <iostream>
using namespace std;

WatchReload::WatchReload(QQmlApplicationEngine *engine)
{
    this->engine = engine;
    this->firstrootobj = this->engine->rootObjects().first();
}

void WatchReload::reloadApp()
{
    qDebug() << "file changes detected";
    if (this->firstrootobj){
        qDebug() << "start reloading";
        QString path = Watch_Dir_Path;
        path = path.prepend("file:").append("/MainWindow.qml");

        this->firstrootobj->setProperty("active",false);
        this->engine->clearComponentCache();
        this->firstrootobj->setProperty("source",path);
        this->firstrootobj->setProperty("active",true);

        if (this->firstrootobj->property("status").toString() == "3"){
            // another way is to use QScript to check the single script using QQmlComponent::loadUrl function which wastes time
            qDebug() << "Goes there";
            this->firstrootobj->setProperty("source","qrc:/ErrorPage.qml");
        }

    }else {
        qDebug() << "not find the first root obj";
    }
}
