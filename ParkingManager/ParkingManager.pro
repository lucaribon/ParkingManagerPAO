QT += core gui
QT += svg svgwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    View/dashboardwindow.cpp \
    View/graphwindow.cpp \
    View/main.cpp \
    View/mainwindow.cpp \
    View/parkingspace.cpp \
    View/reportwindow.cpp \
    View/sensorbar.cpp \
    View/sensorinfo.cpp \
    View/sidemenu.cpp

HEADERS += \
    View/dashboardwindow.h \
    View/graphwindow.h \
    View/mainwindow.h \
    View/parkingspace.h \
    View/reportwindow.h \
    View/sensorbar.h \
    View/sensorinfo.h \
    View/sidemenu.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
