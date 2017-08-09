# qmlLive
## Description:
    Refresh your apps automactically when there are changes on QML file.
    No need to rebuild the whole project in debug mode.

## How it works:
    use QML Loader Type to serve the previous main.cpp(which is renamed to MainWindow.qml in my project to be used as a component)
	Loader can load qrc:..filename which is compiled by rcc, but in debug mode we can let it directly read qml from localfile, which is also possible.

    From C++ aspect, monitor a directory's change by using the QT lib called QSystemFileWathcer. After file changed, a signal emitted and use a function in a class to receive it called reloadApp().

    In the function, just update the source and That's ok.

## To-do:
- [X] re-structure and delete all not related file content and especially dir
- [ ] set the function only enabled in debug mode
- [ ] search what's qDebug(), why it can be executed after engine.load...
and will it automatically disappear in release mode
- [ ] the problem of path. currently we specify the aboulute path. Can it be substituted by cMakeLists.txt
