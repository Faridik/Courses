#include "filterwindow.h"
#include "ui_filterwindow.h"

filterWindow::filterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::filterWindow)
{
    ui->setupUi(this);
    connect(ui->backButton,SIGNAL(pressed()),this,SLOT(backToMain()));
}

void filterWindow::backToMain()
{
    emit back();
}

filterWindow::~filterWindow()
{
    delete ui;
}
