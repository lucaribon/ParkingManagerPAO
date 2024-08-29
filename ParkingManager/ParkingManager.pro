QT += core gui
QT += svg svgwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller/controller.cpp \
    Model/airQualitySensor.cpp \
    Model/airSensor.cpp \
    Model/sensor.cpp \
    View/applogo.cpp \
    View/dashboardwindow.cpp \
    View/graphwindow.cpp \
    View/main.cpp \
    View/mainwindow.cpp \
    View/parkinglots.cpp \
    View/parkingpage.cpp \
    View/parkingslot.cpp \
    View/reportwindow.cpp \
    View/sensorbar.cpp \
    View/sensoreditor.cpp \
    View/sensoreditordialog.cpp \
    View/sensorinfo.cpp \
    View/sidemenu.cpp \
    View/welcomepage.cpp \

HEADERS += \
    Controller/controller.h \
    Model/airQualitySensor.h \
    Model/airSensor.h \
    Model/sensor.h \
    View/applogo.h \
    View/dashboardwindow.h \
    View/graphwindow.h \
    View/mainwindow.h \
    View/parkinglots.h \
    View/parkingpage.h \
    View/parkingslot.h \
    View/reportwindow.h \
    View/sensorbar.h \
    View/sensoreditor.h \
    View/sensoreditordialog.h \
    View/sensorinfo.h \
    View/sidemenu.h \
    View/welcomepage.h \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
