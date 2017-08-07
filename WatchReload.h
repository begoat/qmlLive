#ifndef WatchReload_H
#define WatchReload_H
#include <QObject>

class WatchReload: public QObject
{
    Q_OBJECT
public:
  WatchReload();
public slots:
  void reloadApp(const QString &path);

};

#endif
