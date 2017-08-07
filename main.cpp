#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFileSystemWatcher>
#include <QStringList>
#include <iostream>
#include "WatchReload.h"
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QFileSystemWatcher watchdog;
    QString str = "/Users/william/QT-project/qmlLive";
    if (!watchdog.addPath(str) ){
        cout << "Error: Cannot not watch" << endl;
    }
    QStringList list = watchdog.directories();
        cout << "Watching dir list:    ";
    for (int i=0;i<list.length();i++){
        cout << list[i].toUtf8().constData();
    }
        cout << endl;
    QQmlApplicationEngine engine;
    WatchReload Reload;
    // Reload.reloadApp("sad");
    QObject::connect(&watchdog,&QFileSystemWatcher::directoryChanged,&Reload,&WatchReload::reloadApp);

    engine.load(QUrl(QLatin1String("qrc:/Loader.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
