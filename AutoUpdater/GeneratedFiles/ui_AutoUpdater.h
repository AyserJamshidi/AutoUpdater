/********************************************************************************
** Form generated from reading UI file 'AutoUpdater.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOUPDATER_H
#define UI_AUTOUPDATER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AutoUpdaterClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QLineEdit *password_Field;
    QLabel *username_Label;
    QLineEdit *username_Field;
    QLabel *password_Label;
    QVBoxLayout *verticalLayout;
    QCheckBox *rememberMe_CheckBox;
    QPushButton *login_Button;
    QWidget *loading_Page;
    QLabel *loadingGif_Label;

    void setupUi(QMainWindow *AutoUpdaterClass)
    {
        if (AutoUpdaterClass->objectName().isEmpty())
            AutoUpdaterClass->setObjectName(QStringLiteral("AutoUpdaterClass"));
        AutoUpdaterClass->resize(253, 130);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AutoUpdaterClass->sizePolicy().hasHeightForWidth());
        AutoUpdaterClass->setSizePolicy(sizePolicy);
        AutoUpdaterClass->setMinimumSize(QSize(250, 130));
        AutoUpdaterClass->setMaximumSize(QSize(350, 259));
        AutoUpdaterClass->setStyleSheet(QLatin1String("background-color: rgb(38, 38, 38);\n"
"\n"
"\n"
"/*QCheckBox, QPushButton {\n"
"	color: rgb(176, 30, 58);\n"
"}*/"));
        centralWidget = new QWidget(AutoUpdaterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setStyleSheet(QLatin1String("/*QLineEdit {\n"
"	color: rgb(176, 30, 58);\n"
"}*/\n"
"\n"
"QCheckBox, QLineEdit {\n"
"	color: rgb(176, 30, 58);\n"
"}\n"
"\n"
"QPushButton {\n"
"	background-color: rgb(60, 60, 60);\n"
"	color: rgb(176, 30, 58);\n"
"}"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(7);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setEnabled(true);
        stackedWidget->setLayoutDirection(Qt::LeftToRight);
        stackedWidget->setFrameShape(QFrame::NoFrame);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        password_Field = new QLineEdit(page);
        password_Field->setObjectName(QStringLiteral("password_Field"));
        password_Field->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(password_Field->sizePolicy().hasHeightForWidth());
        password_Field->setSizePolicy(sizePolicy1);
        password_Field->setStyleSheet(QStringLiteral(""));
        password_Field->setEchoMode(QLineEdit::Password);
        password_Field->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(password_Field, 1, 1, 1, 1);

        username_Label = new QLabel(page);
        username_Label->setObjectName(QStringLiteral("username_Label"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(username_Label->sizePolicy().hasHeightForWidth());
        username_Label->setSizePolicy(sizePolicy2);
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI Semibold"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        username_Label->setFont(font);
        username_Label->setLayoutDirection(Qt::LeftToRight);
        username_Label->setAutoFillBackground(false);
        username_Label->setFrameShadow(QFrame::Plain);
        username_Label->setTextFormat(Qt::AutoText);
        username_Label->setScaledContents(false);
        username_Label->setAlignment(Qt::AlignCenter);
        username_Label->setWordWrap(false);
        username_Label->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(username_Label, 0, 0, 1, 1);

        username_Field = new QLineEdit(page);
        username_Field->setObjectName(QStringLiteral("username_Field"));
        username_Field->setEnabled(true);
        sizePolicy1.setHeightForWidth(username_Field->sizePolicy().hasHeightForWidth());
        username_Field->setSizePolicy(sizePolicy1);
        username_Field->setAlignment(Qt::AlignCenter);
        username_Field->setClearButtonEnabled(false);

        gridLayout_2->addWidget(username_Field, 0, 1, 1, 1);

        password_Label = new QLabel(page);
        password_Label->setObjectName(QStringLiteral("password_Label"));
        password_Label->setEnabled(false);
        sizePolicy2.setHeightForWidth(password_Label->sizePolicy().hasHeightForWidth());
        password_Label->setSizePolicy(sizePolicy2);
        password_Label->setFont(font);
        password_Label->setAlignment(Qt::AlignCenter);
        password_Label->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(password_Label, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        rememberMe_CheckBox = new QCheckBox(page);
        rememberMe_CheckBox->setObjectName(QStringLiteral("rememberMe_CheckBox"));
        rememberMe_CheckBox->setLayoutDirection(Qt::LeftToRight);
        rememberMe_CheckBox->setStyleSheet(QLatin1String("QCheckBox::indicator {\n"
"    width: 13px;\n"
"    height: 13px;\n"
"	color: white;\n"
"}"));
        rememberMe_CheckBox->setChecked(false);
        rememberMe_CheckBox->setTristate(false);

        verticalLayout->addWidget(rememberMe_CheckBox, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        login_Button = new QPushButton(page);
        login_Button->setObjectName(QStringLiteral("login_Button"));
        login_Button->setStyleSheet(QLatin1String("/*QPushButton {\n"
"	background-color: rgb(60, 60, 60)\n"
"}*/"));

        verticalLayout->addWidget(login_Button, 0, Qt::AlignVCenter);


        gridLayout_2->addLayout(verticalLayout, 2, 0, 1, 2);

        stackedWidget->addWidget(page);
        loading_Page = new QWidget();
        loading_Page->setObjectName(QStringLiteral("loading_Page"));
        loadingGif_Label = new QLabel(loading_Page);
        loadingGif_Label->setObjectName(QStringLiteral("loadingGif_Label"));
        loadingGif_Label->setGeometry(QRect(0, 0, 73, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI Semibold"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        loadingGif_Label->setFont(font1);
        stackedWidget->addWidget(loading_Page);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        AutoUpdaterClass->setCentralWidget(centralWidget);
        QWidget::setTabOrder(username_Field, password_Field);
        QWidget::setTabOrder(password_Field, rememberMe_CheckBox);
        QWidget::setTabOrder(rememberMe_CheckBox, login_Button);

        retranslateUi(AutoUpdaterClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AutoUpdaterClass);
    } // setupUi

    void retranslateUi(QMainWindow *AutoUpdaterClass)
    {
        AutoUpdaterClass->setWindowTitle(QApplication::translate("AutoUpdaterClass", "Lmfaoown's Aion Hack Login", nullptr));
        username_Label->setText(QApplication::translate("AutoUpdaterClass", "<html><head/><body><p><span style=\" font-size:10pt; color:#b01e3a;\">Username</span></p></body></html>", nullptr));
        username_Field->setText(QString());
        password_Label->setText(QApplication::translate("AutoUpdaterClass", "<html><head/><body><p><span style=\" font-size:10pt; color:#b01e3a;\">Password</span></p></body></html>", nullptr));
        rememberMe_CheckBox->setText(QApplication::translate("AutoUpdaterClass", "Remember Me", nullptr));
        login_Button->setText(QApplication::translate("AutoUpdaterClass", "Login", nullptr));
        loadingGif_Label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AutoUpdaterClass: public Ui_AutoUpdaterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOUPDATER_H
