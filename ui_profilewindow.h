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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
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
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QListWidget *listWidget;
    QPushButton *backButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *profileWindow)
    {
        if (profileWindow->objectName().isEmpty())
            profileWindow->setObjectName(QStringLiteral("profileWindow"));
        profileWindow->resize(757, 569);
        centralwidget = new QWidget(profileWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        backButton = new QPushButton(centralwidget);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(550, 50, 91, 51));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 160, 91, 51));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 20, 91, 51));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 40, 81, 41));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(300, 90, 133, 20));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(300, 130, 131, 20));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(300, 170, 133, 20));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(140, 230, 471, 271));
        backButton_2 = new QPushButton(centralwidget);
        backButton_2->setObjectName(QStringLiteral("backButton_2"));
        backButton_2->setGeometry(QRect(30, 90, 91, 51));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(550, 130, 91, 51));
        profileWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(profileWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 757, 21));
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
        pushButton->setText(QApplication::translate("profileWindow", "\320\237\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\320\275\320\270\320\265 ", nullptr));
        pushButton_2->setText(QApplication::translate("profileWindow", "\320\234\320\276\320\270 \320\272\321\203\321\200\321\201\321\213", nullptr));
        label->setText(QApplication::translate("profileWindow", "\320\234\320\276\320\271 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        backButton_2->setText(QApplication::translate("profileWindow", "\320\241\320\265\321\200\321\202\320\270\321\204\320\270\320\272\320\260\321\202\321\213", nullptr));
        pushButton_3->setText(QApplication::translate("profileWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214\n"
"\320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class profileWindow: public Ui_profileWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEWINDOW_H
