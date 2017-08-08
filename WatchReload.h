#ifndef WatchReload_H
#define WatchReload_H
#include <QObject>
#include <QQmlApplicationEngine>

class WatchReload: public QObject
{
    Q_OBJECT
public:
  WatchReload(QQmlApplicationEngine *engine);
public slots:
  void reloadApp(const QString &path);
private:
  QQmlApplicationEngine *engine;
  //QString realPath;
};

#endif
