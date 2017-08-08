#include <iostream>
#include <QQuickView>
#include "WatchReload.h"
using namespace std;

WatchReload::WatchReload(QQmlApplicationEngine *engine)
{
    this->engine = engine;
    // this->realPath = realPath+"main.qml";
}

void WatchReload::reloadApp()
{
//        QObject *pRootObject = engine->rootObjects().first();
//        Q_ASSERT( pRootObject != NULL );
//        Q_ASSERT( pRootObject->objectName() == "mainWindow" );
//        cout << "The some file been changed---------->"<<endl;
//        cout << pRootObject->objectName().toUtf8().constData() << " is the object name of ..." << endl;
//        QQuickView * pMainWindow = qobject_cast<QQuickView*>(pRootObject);
//        Q_ASSERT(pMainWindow);
//        pMainWindow->close();
//        pMainWindow->engine()->clearComponentCache();
//        pMainWindow->setSource(QUrl(QLatin1String("qrc:/main.qml")));
    // cout << this->realPath.toUtf8().constData() <<endl;
    this->engine->clearComponentCache();
    this->engine->load(QUrl::fromLocalFile(QLatin1String("/Users/william/QT-project/qmlLive/main.qml")));
}
