/********************************************************************************
** Form generated from reading UI file 'profilewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEWINDOW_H
#define UI_PROFILEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_profileWindow
{
public:
    QWidget *centralwidget;
    QPushButton *backButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *profileWindow)
    {
        if (profileWindow->objectName().isEmpty())
            profileWindow->setObjectName(QStringLiteral("profileWindow"));
        profileWindow->resize(800, 600);
        centralwidget = new QWidget(profileWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        backButton = new QPushButton(centralwidget);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(60, 340, 131, 71));
        profileWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(profileWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        profileWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(profileWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        profileWindow->setStatusBar(statusbar);

        retranslateUi(profileWindow);

        QMetaObject::connectSlotsByName(profileWindow);
    } // setupUi

    void retranslateUi(QMainWindow *profileWindow)
    {
        profileWindow->setWindowTitle(QApplication::translate("profileWindow", "MainWindow", nullptr));
        backButton->setText(QApplication::translate("profileWindow", "\320\235\320\260 \320\263\320\273\320\260\320\262\320\275\321\203\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class profileWindow: public Ui_profileWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEWINDOW_H
