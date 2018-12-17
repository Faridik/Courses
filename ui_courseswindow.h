/********************************************************************************
** Form generated from reading UI file 'courseswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSESWINDOW_H
#define UI_COURSESWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_coursesWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QWidget *page1;
    QWidget *page4;
    QWidget *page2;
    QWidget *page5;
    QWidget *page3;
    QWidget *page6;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *back;
    QPushButton *forward;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *coursesWindow)
    {
        if (coursesWindow->objectName().isEmpty())
            coursesWindow->setObjectName(QStringLiteral("coursesWindow"));
        coursesWindow->resize(751, 505);
        centralwidget = new QWidget(coursesWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(3, 7, 721, 451));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        page1 = new QWidget(widget);
        page1->setObjectName(QStringLiteral("page1"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(page1->sizePolicy().hasHeightForWidth());
        page1->setSizePolicy(sizePolicy);

        gridLayout->addWidget(page1, 0, 0, 1, 1);

        page4 = new QWidget(widget);
        page4->setObjectName(QStringLiteral("page4"));
        sizePolicy.setHeightForWidth(page4->sizePolicy().hasHeightForWidth());
        page4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(page4, 0, 1, 1, 1);

        page2 = new QWidget(widget);
        page2->setObjectName(QStringLiteral("page2"));
        sizePolicy.setHeightForWidth(page2->sizePolicy().hasHeightForWidth());
        page2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(page2, 1, 0, 1, 1);

        page5 = new QWidget(widget);
        page5->setObjectName(QStringLiteral("page5"));
        sizePolicy.setHeightForWidth(page5->sizePolicy().hasHeightForWidth());
        page5->setSizePolicy(sizePolicy);

        gridLayout->addWidget(page5, 1, 1, 2, 1);

        page3 = new QWidget(widget);
        page3->setObjectName(QStringLiteral("page3"));
        sizePolicy.setHeightForWidth(page3->sizePolicy().hasHeightForWidth());
        page3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(page3, 2, 0, 2, 1);

        page6 = new QWidget(widget);
        page6->setObjectName(QStringLiteral("page6"));
        sizePolicy.setHeightForWidth(page6->sizePolicy().hasHeightForWidth());
        page6->setSizePolicy(sizePolicy);

        gridLayout->addWidget(page6, 3, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        backButton = new QPushButton(widget);
        backButton->setObjectName(QStringLiteral("backButton"));

        horizontalLayout->addWidget(backButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        back = new QPushButton(widget);
        back->setObjectName(QStringLiteral("back"));

        horizontalLayout->addWidget(back);

        forward = new QPushButton(widget);
        forward->setObjectName(QStringLiteral("forward"));

        horizontalLayout->addWidget(forward);


        verticalLayout_2->addLayout(horizontalLayout);

        coursesWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(coursesWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 751, 21));
        coursesWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(coursesWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        coursesWindow->setStatusBar(statusbar);

        retranslateUi(coursesWindow);

        QMetaObject::connectSlotsByName(coursesWindow);
    } // setupUi

    void retranslateUi(QMainWindow *coursesWindow)
    {
        coursesWindow->setWindowTitle(QApplication::translate("coursesWindow", "MainWindow", nullptr));
        backButton->setText(QApplication::translate("coursesWindow", "\320\235\320\260 \320\263\320\273\320\260\320\262\320\275\321\203\321\216", nullptr));
        back->setText(QApplication::translate("coursesWindow", "PushButton", nullptr));
        forward->setText(QApplication::translate("coursesWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class coursesWindow: public Ui_coursesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSESWINDOW_H
