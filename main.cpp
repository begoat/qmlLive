#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFileSystemWatcher>
#include <QStringList>
#include <iostream>
#include <QDebug>
#include "WatchReload.h"
using namespace std;

int main(int argc, char *argv[])
{
    qputenv("QML_DISABLE_DISK_CACHE", "1"); // disable QML cache to prevent the associated bugs from manifesting
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QFileSystemWatcher watchdog;
    QString str = "/Users/william/QT-project/qmlLive/";
    if (!watchdog.addPath(str) ){
        cout << "Error: Cannot not watch" << endl;
    }
    QStringList list = watchdog.directories();

    cout << "Watching dir list:    "<< list[0].toUtf8().constData() <<endl;
    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/Loader.qml")));

     WatchReload Reload(&engine);
     QObject::connect(&watchdog,&QFileSystemWatcher::directoryChanged,&Reload,&WatchReload::reloadApp);


    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
