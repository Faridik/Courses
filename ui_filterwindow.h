/********************************************************************************
** Form generated from reading UI file 'filterwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERWINDOW_H
#define UI_FILTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_filterWindow
{
public:
    QWidget *centralwidget;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QPushButton *backButton;
    QLineEdit *lineEdit_2;
    QTableView *tableView;
    QLabel *label;
    QCheckBox *checkBox_4;
    QLabel *label_2;
    QScrollBar *verticalScrollBar;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *filterWindow)
    {
        if (filterWindow->objectName().isEmpty())
            filterWindow->setObjectName(QStringLiteral("filterWindow"));
        filterWindow->resize(730, 404);
        centralwidget = new QWidget(filterWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(570, 270, 111, 17));
        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(570, 300, 70, 17));
        backButton = new QPushButton(centralwidget);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(30, 320, 91, 41));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(590, 110, 113, 20));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(30, 20, 411, 281));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(520, 70, 51, 20));
        checkBox_4 = new QCheckBox(centralwidget);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(570, 240, 91, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(510, 110, 47, 20));
        verticalScrollBar = new QScrollBar(centralwidget);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(440, 20, 20, 281));
        verticalScrollBar->setOrientation(Qt::Vertical);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(590, 70, 113, 20));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(550, 200, 101, 31));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(550, 150, 91, 31));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(590, 30, 113, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(510, 30, 51, 20));
        filterWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(filterWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 730, 21));
        filterWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(filterWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        filterWindow->setStatusBar(statusbar);

        retranslateUi(filterWindow);

        QMetaObject::connectSlotsByName(filterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *filterWindow)
    {
        filterWindow->setWindowTitle(QApplication::translate("filterWindow", "MainWindow", nullptr));
        checkBox->setText(QApplication::translate("filterWindow", "\320\247\320\270\321\201\320\273\320\276 \320\277\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\276\320\262", nullptr));
        checkBox_2->setText(QApplication::translate("filterWindow", "\320\240\320\265\320\271\321\202\320\270\320\275\320\263", nullptr));
        backButton->setText(QApplication::translate("filterWindow", "\320\235\320\260 \320\263\320\273\320\260\320\262\320\275\321\203\321\216", nullptr));
        label->setText(QApplication::translate("filterWindow", "\320\242\321\215\320\263\320\270", nullptr));
        checkBox_4->setText(QApplication::translate("filterWindow", "\320\224\320\260\321\202\320\260", nullptr));
        label_2->setText(QApplication::translate("filterWindow", "\320\220\320\262\321\202\320\276\321\200\321\213", nullptr));
        pushButton_2->setText(QApplication::translate("filterWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\277\320\276 :", nullptr));
        pushButton_3->setText(QApplication::translate("filterWindow", "\320\230\321\201\320\272\320\260\321\202\321\214", nullptr));
        label_3->setText(QApplication::translate("filterWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class filterWindow: public Ui_filterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERWINDOW_H
