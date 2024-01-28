QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CSVReader.cpp \
    CSVWriter.cpp \
    CustomTextBrowser.cpp \
    JSONReader.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AbstractReader.h \
    C:/Users/Роман/Downloads/json (1).hpp \
    C:/Users/Роман/Downloads/json-develop/json-develop/include/nlohmann/json_fwd.hpp \
    C:/Users/Роман/Downloads/json-develop/json-develop/single_include/nlohmann/json.hpp \
    C:/Users/Роман/Downloads/json.h \
    C:/Users/Роман/Downloads/json.h \
    C:/Users/Роман/Downloads/json.hpp \
    C:/Users/Роман/Downloads/json.hpp \
    C:/Users/Роман/Downloads/json.hpp \
    C:/Users/Роман/Downloads/json.hpp \
    C:/Users/Роман/Downloads/json.hpp \
    C:/Users/Роман/Downloads/json.hpp \
    C:/Users/Роман/Downloads/json.hpp \
    C:/Users/Роман/Downloads/json.hpp \
    CSVReader.h \
    CSVWriter.h \
    CustomTextBrowser.h \
    JSONReader.h \
    Serial.h \
    json.hpp \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
