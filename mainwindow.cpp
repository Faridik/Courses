#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "coursesdialog.h"
#include "filterdialog.h"
#include "profilesdialog.h"
#include "registrationdialog.h"
#include "signindialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->coursesButton, SIGNAL(pressed()),this, SLOT(openCoursesWindow()));
    connect(ui->loginButton, SIGNAL(pressed()),this, SLOT(openLoginWindow()));
    connect(ui->profileButton, SIGNAL(pressed()),this, SLOT(openProfile()));
    connect(ui->signinButton, SIGNAL(pressed()),this, SLOT(openSigninWindow()));    
}

void MainWindow::openCoursesWindow()   ///Область видимости диалога - {}
{                                     ///exec - открытие
    CoursesDialog dialog{{},this};
    dialog.exec();
}

void MainWindow::openLoginWindow()
{
    SignInDialog dialog{this};
    dialog.exec();
}

void MainWindow::openSigninWindow()
{
    RegistrationDialog dialog{this};
    dialog.exec();
}

void MainWindow::openProfile()
{
    /// TODO - fill profile
    Profile profile;
    profile.editable = true;
    ProfilesDialog dialog{profile, this};
    dialog.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::signOut()
{
    /// TODO - сделать реализацию выхода из профиля
}
