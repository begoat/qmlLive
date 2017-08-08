#include <iostream>
#include <QQuickView>
#include <QQuickWindow>
#include <QDebug>
#include "WatchReload.h"
using namespace std;

WatchReload::WatchReload(QQmlApplicationEngine *engine)
{
    this->engine = engine;
    // this->realPath = realPath+"main.qml"; /Users/william/QT-project/qmlLive/main.qml
}

void WatchReload::reloadApp(const QString &path)
{
//        QList<QObject*> listobjects = this->engine->rootObjects();
//        for (int i=0;i<listobjects.length();i++){
//            cout << i;
//            QObject *currectObject = listobjects[i];
//            qDebug() <<"before clean"<< currectObject->objectName();
//        }
//        QObject *pRootObject = listobjects.first();
//        Q_ASSERT( pRootObject != NULL );
//        Q_ASSERT( pRootObject->objectName() == "mainWindow" );
//        cout << path.toUtf8().constData()<<" file been changed."<<endl;
//        cout << pRootObject->objectName().toUtf8().constData() << " is the object name of ..." << endl;
//        QQuickWindow * pMainWindow = qobject_cast<QQuickWindow*>(pRootObject);
//        Q_ASSERT(pMainWindow);
//        pMainWindow->update();

        qDebug() << "file changes";

//        this->engine->load(QUrl(QLatin1String("/Users/william/QT-project/qmlLive/main.qml")));
        QObject *loader = this->engine->rootObjects().first()->findChild<QObject*>("loader");
        if (loader){
            qDebug() << "locate loader, start reloading";
            //loader->setProperty("source","");
            //loader->setProperty("source","file:/Users/william/QT-project/qmlLive/main.qml");
            this->engine->clearComponentCache();
            loader->setProperty("active",false);
            loader->setProperty("active",true);

        }else {
            qDebug() << "not find.";
        }

}
