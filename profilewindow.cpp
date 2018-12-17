#include "profilewindow.h"
#include "ui_profilewindow.h"

profileWindow::profileWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::profileWindow)
{
    ui->setupUi(this);
    connect(ui->backButton,SIGNAL(pressed()),this,SLOT(backToMain()));
}

void profileWindow::backToMain()
{
    emit back();
}

profileWindow::~profileWindow()
{
    delete ui;
}
