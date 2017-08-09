#include <QDebug>
#include "WatchReload.h"

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
        // leave them here, later if maybe used to solve the problem of absolute path;
        //loader->setProperty("source","");
        //loader->setProperty("source","file:/Users/william/QT-project/qmlLive/MainWindow.qml");
        this->engine->clearComponentCache();
        this->firstrootobj->setProperty("active",false);
        this->firstrootobj->setProperty("active",true);
    }else {
        qDebug() << "not find the first root obj";
    }
}
