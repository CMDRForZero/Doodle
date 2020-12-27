QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    button.cpp \
    doodle.cpp \
    game.cpp \
    greenplatform.cpp \
    main.cpp \
    mainwindow.cpp \
    platform.cpp \
    spawnplatform.cpp

HEADERS += \
    button.h \
    define.h \
    doodle.h \
    game.h \
    greenplatform.h \
    mainwindow.h \
    platform.h \
    spawnplatform.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    C:/Users/andre/OneDrive/Рабочий стол/resource/background.png \
    C:/Users/andre/OneDrive/Рабочий стол/resource/background.png \
    C:/Users/andre/OneDrive/Рабочий стол/resource/mainmenu.png \
    C:/Users/andre/OneDrive/Рабочий стол/resource/mainmenu.png \
    C:/Users/andre/OneDrive/Рабочий стол/resource/menu.png \
    C:/Users/andre/OneDrive/Рабочий стол/resource/menu.png \
    C:/Users/andre/OneDrive/Рабочий стол/resource/menuhover.png \
    C:/Users/andre/OneDrive/Рабочий стол/resource/menuhover.png \
    C:/Users/andre/OneDrive/Рабочий стол/resource/platform.png \
    C:/Users/andre/OneDrive/Рабочий стол/resource/platform.png \
    C:/Users/andre/OneDrive/Рабочий стол/resource/play.png \
    C:/Users/andre/OneDrive/Рабочий стол/resource/play.png \
    C:/Users/andre/OneDrive/Рабочий стол/resource/player_left.png \
    C:/Users/andre/OneDrive/Рабочий стол/resource/player_left.png \
    C:/Users/andre/OneDrive/Рабочий стол/resource/player_right.png \
    C:/Users/andre/OneDrive/Рабочий стол/resource/player_right.png \
    C:/Users/andre/OneDrive/Рабочий стол/resource/playhover.png \
    C:/Users/andre/OneDrive/Рабочий стол/resource/playhover.png \
    resource/background.png \
    resource/mainmenu.png \
    resource/menu.png \
    resource/menuhover.png \
    resource/platform.png \
    resource/play.png \
    resource/player_left.png \
    resource/player_right.png \
    resource/playhover.png

RESOURCES += \
    res.qrc
