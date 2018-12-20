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
	ui->exitButton->setVisible(false);

    connect(ui->coursesButton, SIGNAL(pressed()),this, SLOT(openCoursesWindow()));
    connect(ui->loginButton, SIGNAL(pressed()),this, SLOT(openLoginWindow()));
    connect(ui->profileButton, SIGNAL(pressed()),this, SLOT(openProfile()));
    connect(ui->signinButton, SIGNAL(pressed()),this, SLOT(openSigninWindow()));  
	connect(ui->signinButton, SIGNAL(pressed()), this, SLOT(openSigninWindow()));
	connect(ui->exitButton, SIGNAL(pressed()), this, SLOT(signOut()));

	db = new(sqldb);
	user = "guest";
}

void MainWindow::openCoursesWindow()   ///Область видимости диалога - {}
{                                     ///exec - открытие
    CoursesDialog dialog{{},this};
    dialog.exec();
}

void MainWindow::openLoginWindow()
{
    SignInDialog dialog{this};
	dialog.setUserName(&user);
	if (dialog.exec() == QDialog::Accepted)
	{
		ui->profileButton->setEnabled(true);
		ui->exitButton->setVisible(true);
		ui->exitButton->setEnabled(true);
		ui->loginButton->setEnabled(false);
		ui->loginButton->setVisible(false);

		//connect in db
	}
}

void MainWindow::openSigninWindow()
{
    RegistrationDialog dialog{this};
	
	if (dialog.exec() == QDialog::Accepted)
	{

	}
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
	user = "guest";
	//disconnect from bd
	ui->profileButton->setEnabled(false);
	ui->loginButton->setEnabled(true);
	ui->loginButton->setVisible(true);
	ui->exitButton->setVisible(false);
	ui->exitButton->setEnabled(false);
    /// TODO - сделать реализацию выхода из профиля
}
