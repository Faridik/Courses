#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "coursesdialog.h"
#include "filterdialog.h"
#include "profilesdialog.h"
#include "registrationdialog.h"
#include "signindialog.h"

#include <QtSql/QSqlQuery>


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
	userid = 0;
	if (userid) db->connectFromUser();
	else db->connect();
}

void MainWindow::openCoursesWindow()   ///Область видимости диалога - {}
{                                     ///exec - открытие
    CoursesDialog dialog{{},this};
    dialog.exec();
}

void MainWindow::openLoginWindow()
{
    SignInDialog dialog{&userid, this};
	if (dialog.exec() == QDialog::Accepted)
	{
		ui->profileButton->setEnabled(true);
		ui->exitButton->setVisible(true);
		ui->exitButton->setEnabled(true);
		ui->loginButton->setEnabled(false);
		ui->loginButton->setVisible(false);

		db->disconnect();
		db->connectFromUser();
	}
}

void MainWindow::openSigninWindow()
{
    RegistrationDialog dialog{&userid, this};
	if (dialog.exec() == QDialog::Accepted)
	{
		ui->profileButton->setEnabled(true);
		ui->exitButton->setVisible(true);
		ui->exitButton->setEnabled(true);
		ui->loginButton->setEnabled(false);
		ui->loginButton->setVisible(false);

		db->disconnect();
		db->connectFromUser();
	}
}

void MainWindow::openProfile()
{
    /// TODO - fill profile
	QSqlQuery query;
	query.exec(QString("SELECT * FROM users WHERE id = ") + QString::number(userid));
	query.next();


    Profile profile;
	profile.email = query.value("email").toString();
	profile.firstName = query.value("firstname").toString();
	profile.lastName = query.value("lastname").toString();
    profile.editable = true;

	query.exec(QString("SELECT * FROM users_con WHERE id = ") + QString::number(userid));
	query.next();
	
	profile.login = query.value("login").toString();

    ProfilesDialog dialog{profile, this};
    dialog.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::signOut()
{
	userid = 0;
	db->disconnect();
	db->connect();

	ui->profileButton->setEnabled(false);
	ui->loginButton->setEnabled(true);
	ui->loginButton->setVisible(true);
	ui->exitButton->setVisible(false);
	ui->exitButton->setEnabled(false);
    /// TODO - сделать реализацию выхода из профиля
}
