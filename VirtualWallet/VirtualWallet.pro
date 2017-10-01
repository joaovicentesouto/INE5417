#-------------------------------------------------
#
# Project created by QtCreator 2017-09-28T16:32:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VirtualWallet
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        ./src/model/Account.cpp \
        ./src/model/BankAccount.cpp \
        ./src/model/Release.cpp \
        ./src/model/Report.cpp \
        ./src/model/TypeManager.cpp \
        ./src/model/User.cpp \
        ./src/model/Wallet.cpp \
        ./src/control/BankAccountBuilder.cpp \
        ./src/control/Facade.cpp \
        ./src/control/ReleaseTypeBuilder.cpp \
        ./src/control/UserBuilder.cpp \
        ./src/control/WalletBuilder.cpp \
        ./src/vision/mainwindow.cpp \
    src/vision/wnewwallet.cpp

HEADERS += \
        ./src/model/Account.h \
        ./src/model/BankAccount.h \
        ./src/model/Release.h \
        ./src/model/Report.h \
        ./src/model/TypeManager.h \
        ./src/model/User.h \
        ./src/model/Wallet.h \
        ./src/control/BankAccountBuilder.h \
        ./src/control/Facade.h \
        ./src/control/ReleaseTypeBuilder.h \
        ./src/control/UserBuilder.h \
        ./src/control/WalletBuilder.h \
        ./src/vision/mainwindow.h \
    src/vision/wnewwallet.h

FORMS += \
        ./src/vision/mainwindow.ui \
    src/vision/wnewwallet.ui
