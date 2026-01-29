QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_CXXFLAGS += -Wall -Wextra -Wreturn-type
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Core/CommandFactory.cpp \
    Core/CommandParser.cpp \
    Core/Commands/AddTaskCommand.cpp \
    Core/Commands/CompleteTaskCommand.cpp \
    Core/Commands/ExecuteFileCommand.cpp \
    Core/Commands/ListTasksCommand.cpp \
    Core/Commands/RemoveTaskCommand.cpp \
    Core/Task.cpp \
    Core/TaskManager.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Core/Command.h \
    Core/CommandFactory.h \
    Core/CommandParser.h \
    Core/Commands/AddTaskCommand.h \
    Core/Commands/CompleteTaskCommand.h \
    Core/Commands/ExecuteFileCommand.h \
    Core/Commands/ListTasksCommand.h \
    Core/Commands/RemoveTaskCommand.h \
    Core/Task.h \
    Core/TaskManager.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore \
    README.md
