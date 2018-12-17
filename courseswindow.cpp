#include "courseswindow.h"
#include "ui_courseswindow.h"

#include "courseview.h"

coursesWindow::coursesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::coursesWindow)
{
    ui->setupUi(this);

    ui->gridLayout->removeWidget(ui->page1);
    ui->gridLayout->removeWidget(ui->page2);
    ui->gridLayout->removeWidget(ui->page3);
    ui->gridLayout->removeWidget(ui->page4);
    ui->gridLayout->removeWidget(ui->page5);
    ui->gridLayout->removeWidget(ui->page6);

    delete ui->page1;
    delete ui->page2;
    delete ui->page3;
    delete ui->page4;
    delete ui->page5;
    delete ui->page6;

    ui->page1 = new CourceView(ui->centralwidget);
    ui->page2 = new CourceView(ui->centralwidget);
    ui->page3 = new CourceView(ui->centralwidget);
    ui->page4 = new CourceView(ui->centralwidget);
    ui->page5 = new CourceView(ui->centralwidget);
    ui->page6 = new CourceView(ui->centralwidget);

    ui->gridLayout->addWidget(ui->page1, 0, 0);
    ui->gridLayout->addWidget(ui->page2, 1, 0);
    ui->gridLayout->addWidget(ui->page3, 2, 0);
    ui->gridLayout->addWidget(ui->page4, 0, 1);
    ui->gridLayout->addWidget(ui->page5, 1, 1);
    ui->gridLayout->addWidget(ui->page6, 2, 1);

    connect(ui->backButton,SIGNAL(pressed()),this,SLOT(backToMain()));
}

void coursesWindow::backToMain()
{
    emit back();
}

coursesWindow::~coursesWindow()
{
    delete ui;
}
