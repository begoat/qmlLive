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
        this->firstrootobj->setProperty("source","");
        this->engine->clearComponentCache();

        QString path = Watch_Dir_Path;
        path = path.prepend("file:").append("/MainWindow.qml");

        this->firstrootobj->setProperty("source",path);
        //this->firstrootobj->setProperty("active",false);
        //this->firstrootobj->setProperty("active",true);
    }else {
        qDebug() << "not find the first root obj";
    }
}
