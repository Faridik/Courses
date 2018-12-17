#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "signindialog.h"
#include "registrationdialog.h"
#include "filterdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    courses(NULL),
    profile(NULL)
{
    ui->setupUi(this);
    connect(ui->coursesButton, SIGNAL(pressed()),this, SLOT(openCoursesWindow()));
    connect(ui->loginButton, SIGNAL(pressed()),this, SLOT(openLoginWindow()));
    connect(ui->profileButton, SIGNAL(pressed()),this, SLOT(openProfile()));
    connect(ui->signinButton, SIGNAL(pressed()),this, SLOT(openSigninWindow()));
    connect(ui->filterButton, SIGNAL(pressed()),this, SLOT(openFilterWindow()));
}


void MainWindow::openCoursesWindow()
{
    courses = new coursesWindow();
    connect(courses,SIGNAL(back()),this,SLOT(backFromCourses()));
    this->hide();
    courses->show();
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
    profile = new profileWindow();
    connect(profile,SIGNAL(back()),this,SLOT(backFromProfile()));
    this->hide();
    profile->show();
}

void MainWindow::openFilterWindow()
{
    FilterDialog dialog{this};

    if (dialog.exec() == QDialog::Accepted)
    {
        /// TODO - применяем фильтры
    }
}


void MainWindow::backFromCourses()
{
    this->show();
    courses->hide();
    delete courses;
    courses=NULL;
}

void MainWindow::backFromProfile()
{
    this->show();
    profile->hide();
    delete profile;
    profile = NULL;
}

MainWindow::~MainWindow()
{
    if (courses) delete courses;
    if (profile) delete profile;
    delete ui;
}
