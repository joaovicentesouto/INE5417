/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *Stack;
    QWidget *Login;
    QVBoxLayout *verticalLayout_2;
    QWidget *NorthWidget;
    QWidget *CenterWidget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *LoginErrorMessage;
    QLineEdit *LoginName;
    QLineEdit *LoginPassword;
    QWidget *LoginButtons;
    QHBoxLayout *horizontalLayout;
    QPushButton *CleanButton;
    QPushButton *ConfirmButton;
    QPushButton *LoginPasswordForgot;
    QPushButton *LoginNameForgot;
    QPushButton *LoginNewUser;
    QWidget *SouthWidget;
    QWidget *Home;
    QVBoxLayout *verticalLayout;
    QWidget *HomeContent;
    QVBoxLayout *verticalLayout_4;
    QWidget *HomeAccounts;
    QWidget *HomeGraphic;
    QWidget *NewTypeRelease;
    QLabel *label;
    QWidget *NewRelease;
    QLabel *label_2;
    QWidget *Report;
    QLabel *label_3;
    QWidget *NewBankAccount;
    QLabel *label_4;
    QWidget *NewWallet;
    QLabel *label_5;
    QWidget *UserData;
    QLabel *label_6;
    QWidget *AppAbout;
    QLabel *label_7;
    QWidget *Menu;
    QPushButton *MenuButton;
    QLabel *MenuUser;
    QLabel *MenuTotal;
    QWidget *MenuWidget;
    QVBoxLayout *verticalLayout_5;
    QLabel *MenuTitle;
    QPushButton *MenuReleases;
    QPushButton *MenuNewReleaseType;
    QPushButton *MenuNewRelease;
    QPushButton *MenuReport;
    QPushButton *MenuBankAccounts;
    QPushButton *MenuWallets;
    QPushButton *MenuUserDatas;
    QPushButton *MenuAbout;
    QPushButton *MenuOut;
    QLabel *MenuComplement;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(500, 720);
        MainWindow->setMinimumSize(QSize(500, 720));
        MainWindow->setMaximumSize(QSize(500, 720));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        Stack = new QStackedWidget(centralWidget);
        Stack->setObjectName(QStringLiteral("Stack"));
        Stack->setEnabled(true);
        Stack->setGeometry(QRect(0, 50, 500, 670));
        Stack->setMinimumSize(QSize(500, 670));
        Stack->setMaximumSize(QSize(500, 670));
        Login = new QWidget();
        Login->setObjectName(QStringLiteral("Login"));
        verticalLayout_2 = new QVBoxLayout(Login);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        NorthWidget = new QWidget(Login);
        NorthWidget->setObjectName(QStringLiteral("NorthWidget"));

        verticalLayout_2->addWidget(NorthWidget);

        CenterWidget = new QWidget(Login);
        CenterWidget->setObjectName(QStringLiteral("CenterWidget"));
        verticalLayout_3 = new QVBoxLayout(CenterWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        LoginErrorMessage = new QPushButton(CenterWidget);
        LoginErrorMessage->setObjectName(QStringLiteral("LoginErrorMessage"));
        LoginErrorMessage->setStyleSheet(QLatin1String("#LoginErrorMessage\n"
"{\n"
"	color:  rgb(250, 0, 0);\n"
"	background-color: transparent;\n"
"	border: none;\n"
"}"));

        verticalLayout_3->addWidget(LoginErrorMessage);

        LoginName = new QLineEdit(CenterWidget);
        LoginName->setObjectName(QStringLiteral("LoginName"));
        LoginName->setStyleSheet(QLatin1String("#LoginName\n"
"{\n"
"	border: none;\n"
"    color: #565656;\n"
"    font-size: 12px;\n"
"}"));

        verticalLayout_3->addWidget(LoginName);

        LoginPassword = new QLineEdit(CenterWidget);
        LoginPassword->setObjectName(QStringLiteral("LoginPassword"));
        LoginPassword->setStyleSheet(QLatin1String("#LoginPassword\n"
"{\n"
"	border: none;\n"
"    color: #565656;\n"
"    font-size: 12px;\n"
"}"));

        verticalLayout_3->addWidget(LoginPassword);

        LoginButtons = new QWidget(CenterWidget);
        LoginButtons->setObjectName(QStringLiteral("LoginButtons"));
        LoginButtons->setMaximumSize(QSize(16777215, 50));
        horizontalLayout = new QHBoxLayout(LoginButtons);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        CleanButton = new QPushButton(LoginButtons);
        CleanButton->setObjectName(QStringLiteral("CleanButton"));
        CleanButton->setMaximumSize(QSize(16777215, 40));
        CleanButton->setStyleSheet(QLatin1String("#CleanButton\n"
"{\n"
"    background-color: #a3f48a;\n"
"    color: black;\n"
"    font-size: 12px;\n"
"}"));

        horizontalLayout->addWidget(CleanButton);

        ConfirmButton = new QPushButton(LoginButtons);
        ConfirmButton->setObjectName(QStringLiteral("ConfirmButton"));
        ConfirmButton->setMaximumSize(QSize(16777215, 40));
        ConfirmButton->setStyleSheet(QLatin1String("#ConfirmButton\n"
"{\n"
"    background-color: #a3f48a;\n"
"    color: black;\n"
"    font-size: 12px;\n"
"}"));

        horizontalLayout->addWidget(ConfirmButton);


        verticalLayout_3->addWidget(LoginButtons);

        LoginPasswordForgot = new QPushButton(CenterWidget);
        LoginPasswordForgot->setObjectName(QStringLiteral("LoginPasswordForgot"));
        LoginPasswordForgot->setStyleSheet(QLatin1String("#LoginPasswordForgot\n"
"{\n"
"	background-color: transparent;\n"
"	border: none;\n"
"	font-size: 12px;\n"
"}"));

        verticalLayout_3->addWidget(LoginPasswordForgot);

        LoginNameForgot = new QPushButton(CenterWidget);
        LoginNameForgot->setObjectName(QStringLiteral("LoginNameForgot"));
        LoginNameForgot->setStyleSheet(QLatin1String("#LoginNameForgot\n"
"{\n"
"	background-color: transparent;\n"
"	border: none;\n"
"	font-size: 12px;\n"
"}"));

        verticalLayout_3->addWidget(LoginNameForgot);

        LoginNewUser = new QPushButton(CenterWidget);
        LoginNewUser->setObjectName(QStringLiteral("LoginNewUser"));
        LoginNewUser->setStyleSheet(QLatin1String("#LoginNewUser\n"
"{\n"
"	background-color: transparent;\n"
"	border: none;\n"
"	font-size: 12px;\n"
"}"));

        verticalLayout_3->addWidget(LoginNewUser);


        verticalLayout_2->addWidget(CenterWidget);

        SouthWidget = new QWidget(Login);
        SouthWidget->setObjectName(QStringLiteral("SouthWidget"));

        verticalLayout_2->addWidget(SouthWidget);

        Stack->addWidget(Login);
        Home = new QWidget();
        Home->setObjectName(QStringLiteral("Home"));
        verticalLayout = new QVBoxLayout(Home);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        HomeContent = new QWidget(Home);
        HomeContent->setObjectName(QStringLiteral("HomeContent"));
        verticalLayout_4 = new QVBoxLayout(HomeContent);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        HomeAccounts = new QWidget(HomeContent);
        HomeAccounts->setObjectName(QStringLiteral("HomeAccounts"));

        verticalLayout_4->addWidget(HomeAccounts);

        HomeGraphic = new QWidget(HomeContent);
        HomeGraphic->setObjectName(QStringLiteral("HomeGraphic"));

        verticalLayout_4->addWidget(HomeGraphic);


        verticalLayout->addWidget(HomeContent);

        Stack->addWidget(Home);
        NewTypeRelease = new QWidget();
        NewTypeRelease->setObjectName(QStringLiteral("NewTypeRelease"));
        label = new QLabel(NewTypeRelease);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(330, 170, 131, 16));
        Stack->addWidget(NewTypeRelease);
        NewRelease = new QWidget();
        NewRelease->setObjectName(QStringLiteral("NewRelease"));
        label_2 = new QLabel(NewRelease);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(330, 220, 101, 21));
        Stack->addWidget(NewRelease);
        Report = new QWidget();
        Report->setObjectName(QStringLiteral("Report"));
        label_3 = new QLabel(Report);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(310, 240, 60, 16));
        Stack->addWidget(Report);
        NewBankAccount = new QWidget();
        NewBankAccount->setObjectName(QStringLiteral("NewBankAccount"));
        label_4 = new QLabel(NewBankAccount);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(320, 220, 121, 31));
        Stack->addWidget(NewBankAccount);
        NewWallet = new QWidget();
        NewWallet->setObjectName(QStringLiteral("NewWallet"));
        label_5 = new QLabel(NewWallet);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(330, 220, 101, 41));
        Stack->addWidget(NewWallet);
        UserData = new QWidget();
        UserData->setObjectName(QStringLiteral("UserData"));
        label_6 = new QLabel(UserData);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(330, 260, 101, 31));
        Stack->addWidget(UserData);
        AppAbout = new QWidget();
        AppAbout->setObjectName(QStringLiteral("AppAbout"));
        label_7 = new QLabel(AppAbout);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(330, 200, 111, 31));
        Stack->addWidget(AppAbout);
        Menu = new QWidget(centralWidget);
        Menu->setObjectName(QStringLiteral("Menu"));
        Menu->setGeometry(QRect(0, 0, 500, 50));
        Menu->setStyleSheet(QLatin1String("#Menu\n"
"{\n"
"    background-color: #a3f48a;\n"
"}"));
        MenuButton = new QPushButton(Menu);
        MenuButton->setObjectName(QStringLiteral("MenuButton"));
        MenuButton->setGeometry(QRect(0, 0, 50, 50));
        MenuButton->setStyleSheet(QLatin1String("#MenuButton\n"
"{\n"
"    color: black;\n"
"	border: none;\n"
"    font-size: 12px;\n"
"}"));
        MenuUser = new QLabel(Menu);
        MenuUser->setObjectName(QStringLiteral("MenuUser"));
        MenuUser->setGeometry(QRect(70, 15, 180, 20));
        MenuUser->setMinimumSize(QSize(180, 20));
        MenuUser->setMaximumSize(QSize(180, 20));
        MenuUser->setStyleSheet(QLatin1String("#MenuUser\n"
"{\n"
"	font-size: 12px;\n"
"	qproperty-alignment: AlignCenter;\n"
"}"));
        MenuTotal = new QLabel(Menu);
        MenuTotal->setObjectName(QStringLiteral("MenuTotal"));
        MenuTotal->setGeometry(QRect(250, 15, 250, 20));
        MenuTotal->setMinimumSize(QSize(250, 20));
        MenuTotal->setMaximumSize(QSize(250, 20));
        MenuTotal->setSizeIncrement(QSize(250, 20));
        MenuTotal->setStyleSheet(QLatin1String("#MenuTotal\n"
"{\n"
"	font-size: 12px;\n"
"	qproperty-alignment: AlignCenter;\n"
"}"));
        MenuWidget = new QWidget(centralWidget);
        MenuWidget->setObjectName(QStringLiteral("MenuWidget"));
        MenuWidget->setEnabled(true);
        MenuWidget->setGeometry(QRect(0, 50, 250, 670));
        MenuWidget->setMinimumSize(QSize(250, 670));
        MenuWidget->setMaximumSize(QSize(250, 670));
        MenuWidget->setStyleSheet(QLatin1String("#MenuWidget\n"
"{\n"
"    background-color: #a3f48a;\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(MenuWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        MenuTitle = new QLabel(MenuWidget);
        MenuTitle->setObjectName(QStringLiteral("MenuTitle"));
        MenuTitle->setMaximumSize(QSize(16777215, 50));

        verticalLayout_5->addWidget(MenuTitle);

        MenuReleases = new QPushButton(MenuWidget);
        MenuReleases->setObjectName(QStringLiteral("MenuReleases"));
        MenuReleases->setStyleSheet(QLatin1String("#MenuReleases\n"
"{\n"
"	text-align: left;\n"
"	border: none;\n"
"    color: black;\n"
"    font-size: 12px;\n"
"}"));

        verticalLayout_5->addWidget(MenuReleases);

        MenuNewReleaseType = new QPushButton(MenuWidget);
        MenuNewReleaseType->setObjectName(QStringLiteral("MenuNewReleaseType"));
        MenuNewReleaseType->setStyleSheet(QLatin1String("#MenuNewReleaseType\n"
"{\n"
"	text-align: left;\n"
"	border: none;\n"
"    color: black;\n"
"    font-size: 12px;\n"
"}"));

        verticalLayout_5->addWidget(MenuNewReleaseType);

        MenuNewRelease = new QPushButton(MenuWidget);
        MenuNewRelease->setObjectName(QStringLiteral("MenuNewRelease"));
        MenuNewRelease->setStyleSheet(QLatin1String("#MenuNewRelease\n"
"{\n"
"	text-align: left;\n"
"	border: none;\n"
"    color: black;\n"
"    font-size: 12px;\n"
"}"));

        verticalLayout_5->addWidget(MenuNewRelease);

        MenuReport = new QPushButton(MenuWidget);
        MenuReport->setObjectName(QStringLiteral("MenuReport"));
        MenuReport->setStyleSheet(QLatin1String("#MenuReport\n"
"{\n"
"	text-align: left;\n"
"	border: none;\n"
"    color: black;\n"
"    font-size: 12px;\n"
"}"));

        verticalLayout_5->addWidget(MenuReport);

        MenuBankAccounts = new QPushButton(MenuWidget);
        MenuBankAccounts->setObjectName(QStringLiteral("MenuBankAccounts"));
        MenuBankAccounts->setStyleSheet(QLatin1String("#MenuBankAccounts\n"
"{\n"
"	text-align: left;\n"
"	border: none;\n"
"    color: black;\n"
"    font-size: 12px;\n"
"}"));

        verticalLayout_5->addWidget(MenuBankAccounts);

        MenuWallets = new QPushButton(MenuWidget);
        MenuWallets->setObjectName(QStringLiteral("MenuWallets"));
        MenuWallets->setStyleSheet(QLatin1String("#MenuWallets\n"
"{\n"
"	text-align: left;\n"
"	border: none;\n"
"    color: black;\n"
"    font-size: 12px;\n"
"}"));

        verticalLayout_5->addWidget(MenuWallets);

        MenuUserDatas = new QPushButton(MenuWidget);
        MenuUserDatas->setObjectName(QStringLiteral("MenuUserDatas"));
        MenuUserDatas->setStyleSheet(QLatin1String("#MenuUserDatas\n"
"{\n"
"	text-align: left;\n"
"	border: none;\n"
"    color: black;\n"
"    font-size: 12px;\n"
"}"));

        verticalLayout_5->addWidget(MenuUserDatas);

        MenuAbout = new QPushButton(MenuWidget);
        MenuAbout->setObjectName(QStringLiteral("MenuAbout"));
        MenuAbout->setStyleSheet(QLatin1String("#MenuAbout\n"
"{\n"
"	text-align: left;\n"
"	border: none;\n"
"    color: black;\n"
"    font-size: 12px;\n"
"}"));

        verticalLayout_5->addWidget(MenuAbout);

        MenuOut = new QPushButton(MenuWidget);
        MenuOut->setObjectName(QStringLiteral("MenuOut"));
        MenuOut->setStyleSheet(QLatin1String("#MenuOut\n"
"{\n"
"	text-align: left;\n"
"	border: none;\n"
"    color: black;\n"
"    font-size: 12px;\n"
"}"));

        verticalLayout_5->addWidget(MenuOut);

        MenuComplement = new QLabel(MenuWidget);
        MenuComplement->setObjectName(QStringLiteral("MenuComplement"));

        verticalLayout_5->addWidget(MenuComplement);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        Stack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Virtual Wallet", Q_NULLPTR));
        LoginErrorMessage->setText(QString());
        LoginName->setText(QApplication::translate("MainWindow", "Nome", Q_NULLPTR));
        LoginPassword->setText(QApplication::translate("MainWindow", "Senha", Q_NULLPTR));
        CleanButton->setText(QApplication::translate("MainWindow", "Limpar", Q_NULLPTR));
        ConfirmButton->setText(QApplication::translate("MainWindow", "Confirmar", Q_NULLPTR));
        LoginPasswordForgot->setText(QApplication::translate("MainWindow", "Esqueci Minha Senha", Q_NULLPTR));
        LoginNameForgot->setText(QApplication::translate("MainWindow", "Esqueci Meu Usuario", Q_NULLPTR));
        LoginNewUser->setText(QApplication::translate("MainWindow", "Criar Usuario", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "NewTypeRelease", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "NewRelease", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Report", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "NewBankAccount", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "newWallet", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "UserData", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "AppAbout", Q_NULLPTR));
        MenuButton->setText(QString());
        MenuUser->setText(QString());
        MenuTotal->setText(QString());
        MenuTitle->setText(QApplication::translate("MainWindow", "Op\303\247oes:", Q_NULLPTR));
        MenuReleases->setText(QApplication::translate("MainWindow", "    \302\273 Lan\303\247amentos Financeiros:", Q_NULLPTR));
        MenuNewReleaseType->setText(QApplication::translate("MainWindow", "               Cadastrar Tipo de Lan\303\247amento", Q_NULLPTR));
        MenuNewRelease->setText(QApplication::translate("MainWindow", "               Novo Lan\303\247amento", Q_NULLPTR));
        MenuReport->setText(QApplication::translate("MainWindow", "               Relatorio", Q_NULLPTR));
        MenuBankAccounts->setText(QApplication::translate("MainWindow", "    \302\273 Bank Accounts", Q_NULLPTR));
        MenuWallets->setText(QApplication::translate("MainWindow", "    \302\273 Wallets", Q_NULLPTR));
        MenuUserDatas->setText(QApplication::translate("MainWindow", "    \302\273 Dados do Usuario", Q_NULLPTR));
        MenuAbout->setText(QApplication::translate("MainWindow", "    \302\273 Sobre o Aplicativo", Q_NULLPTR));
        MenuOut->setText(QApplication::translate("MainWindow", "    \302\273 Sair", Q_NULLPTR));
        MenuComplement->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
