# qmlLive
[![Build Status](https://travis-ci.org/begoat/qmlLive.svg?branch=master)](https://travis-ci.org/begoat/qmlLive)

## Description:
    Refresh your apps automactically when there are changes on QML file.
    No need to rebuild the whole project in debug mode.

## How it works:
    use QML Loader Type to serve the previous main.cpp(which is renamed to MainWindow.qml in my project to be used as a component)
	Loader can load qrc:..filename which is compiled by rcc, but in debug mode we can let it directly read qml from localfile, which is also possible.

    From C++ aspect, monitor a directory's change by using the QT lib called QSystemFileWathcer. After file changed, a signal emitted and use a function in a class to receive it called reloadApp().

    In the function, just update the Loader's source and That's ok. If there is syntax error in the file, redirect it to a ErrorPage to prevent the app from exiting.

## To-do:
- [X] re-structure and delete all not related file content and especially dir
- [X] set the function only enabled in debug mode (no need because it will reduce the functionality)
- [X] search what's qDebug()(can display QString or something else), why it can be executed after engine.load,(all the code except cout can be executed immediately)
and will it automatically disappear in release mode (no)
- [X] the problem of path. currently we specify the aboulute path. Can it be substituted by cMakeLists.txt
- [X] keep the window at the same position
- [X] bugs: syntax error will lead to the program down.
- [X] questions: how about add some image file and use it in the component, you add it to the qrc but rcc didn't compile it until its been re-build (not a question in develop mode)

# QSanguosha
https://github.com/Mogara/GameHall

we will focus on develop this project later.
 Welcome to watch and follow us. 