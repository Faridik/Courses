/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *coursesButton;
    QPushButton *loginButton;
    QPushButton *profileButton;
    QPushButton *signinButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *exitButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(651, 405);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        coursesButton = new QPushButton(centralWidget);
        coursesButton->setObjectName(QStringLiteral("coursesButton"));
        coursesButton->setEnabled(true);
        coursesButton->setGeometry(QRect(110, 220, 161, 91));
        QFont font1;
        font1.setPointSize(12);
        coursesButton->setFont(font1);
        loginButton = new QPushButton(centralWidget);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setEnabled(true);
        loginButton->setGeometry(QRect(60, 20, 101, 51));
        loginButton->setFont(font);
        profileButton = new QPushButton(centralWidget);
        profileButton->setObjectName(QStringLiteral("profileButton"));
        profileButton->setEnabled(false);
        profileButton->setGeometry(QRect(280, 20, 101, 51));
        signinButton = new QPushButton(centralWidget);
        signinButton->setObjectName(QStringLiteral("signinButton"));
        signinButton->setEnabled(true);
        signinButton->setGeometry(QRect(170, 20, 99, 51));
        signinButton->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 120, 391, 41));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 160, 321, 41));
        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setEnabled(false);
        exitButton->setGeometry(QRect(60, 20, 101, 51));
        exitButton->setFont(font);
        exitButton->setCheckable(false);
        exitButton->setAutoRepeat(false);
        exitButton->setAutoDefault(false);
        exitButton->setFlat(false);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 651, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        exitButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        coursesButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\277\321\203\320\273\321\217\321\200\320\275\321\213\320\265 \320\272\321\203\321\200\321\201\321\213", nullptr));
        loginButton->setText(QApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264 ", nullptr));
        profileButton->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\271 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        signinButton->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\320\265 \320\262\320\276\321\201\321\202\321\200\320\265\320\261\320\276\320\262\320\260\320\275\320\275\321\213\320\265 \320\267\320\275\320\260\320\275\320\270\321\217 \320\261\320\265\321\201\320\277\320\273\320\260\321\202\320\275\320\276", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\271\320\264\320\270\321\202\320\265 \320\272\321\203\321\200\321\201\321\213 \320\276\321\202 \320\262\320\265\320\264\321\203\321\211\320\270\321\205 \321\203\320\275\320\270\320\262\320\265\321\200\321\201\320\270\321\202\320\265\321\202\320\276\320\262 \321\201\321\202\321\200\320\260\320\275\321\213 ", nullptr));
        exitButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
