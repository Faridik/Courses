#include "registrationdialog.h"

#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCryptographicHash>
#include <QtSql/QSqlQuery>
#include <Qtime>

RegistrationDialog::RegistrationDialog(int *userid, QWidget *parent) : QDialog{parent}
{
    auto *vbox = new QBoxLayout{QBoxLayout::TopToBottom};

    auto *label = new QLabel{tr("Данные пользователя")};
    label->setAlignment(Qt::AlignCenter);

    auto *firstName = new QLineEdit{};
    firstName->setPlaceholderText(tr("Имя"));

    auto *lastName = new QLineEdit{};
    lastName->setPlaceholderText(tr("Фамилия"));

    auto *login = new QLineEdit{};
    login->setPlaceholderText(tr("Логин"));

    auto *email = new QLineEdit{};
    email->setPlaceholderText(tr("E-mail"));

    auto *pass = new QLineEdit{};
    pass->setPlaceholderText(tr("Пароль"));
    pass->setEchoMode(QLineEdit::Password);

    auto *registerUserButton = new QPushButton{tr("Зарегистрировать")};
    connect(registerUserButton, &QPushButton::clicked, this, [=]()
    {
        User user;
        user.firstName = firstName->text();
        user.lastName  = lastName->text();
        user.login     = login->text();
        user.email     = email->text();
        user.pass      = pass->text();

        registerNewUser(userid, user);
    });

    auto *homeButton = new QPushButton{tr("Вернуться")};
    connect(homeButton, &QPushButton::clicked, this, &QDialog::reject);

    vbox->addSpacerItem(new QSpacerItem{0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding});
    vbox->addWidget(label);
    vbox->addWidget(firstName);
    vbox->addWidget(lastName);
    vbox->addWidget(login);
    vbox->addWidget(email);
    vbox->addWidget(pass);
    vbox->addWidget(registerUserButton);
    vbox->addWidget(homeButton);
    vbox->addSpacerItem(new QSpacerItem{0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding});

    auto *hbox = new QBoxLayout{QBoxLayout::LeftToRight};
    hbox->addSpacerItem(new QSpacerItem{0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding});
    hbox->addLayout(vbox);
    hbox->addSpacerItem(new QSpacerItem{0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding});

    setLayout(hbox);

    setWindowTitle(tr("Регистрация пользователя"));
    setModal(true);
    setMinimumSize(480, 360);
}

void RegistrationDialog::registerNewUser(int *userid, const RegistrationDialog::User &user)
{
	Q_UNUSED(user);

	///проверка на правильность введённого, пароль мб

	QSqlQuery query;
	query.exec(QString("SELECT id FROM users_con WHERE login = '") + user.login + QString("'"));
	query.next();
	if (query.value(0).toInt())
	{
		///такой логин существует
	}
	else
	{
		qsrand(QTime::currentTime().msec());

		//генерация соли
		QString salt = "\0";
		for (int i = 0; i < 5 + qrand() % 6; ++i)
			salt += QChar(33 + qrand() % 94);
		QString pass = user.pass + salt;

		//ввод логина, хеш пароля и соли
		query.exec(QString("INSERT INTO users_con (login, pass, salt) VALUES ('") +
			user.login + QString("', '") +
			QCryptographicHash::hash(pass.toUtf8(), QCryptographicHash::Sha256).toHex() +
			QString("', '") + salt + QString("')"));

		//вывод id из бд
		query.exec(QString("SELECT id FROM users_con WHERE login = '") + user.login + QString("'"));
		query.next();
		*userid = query.value(0).toInt();

		//ввод дополнительных данных
		query.exec(QString("INSERT INTO users (id, firstname, lastname, creationdate, email) VALUES (") +
			QString::number(*userid) + QString(", '") +
			user.firstName + QString("', '") +
			user.lastName + QString("', current_timestamp, '") +
			user.email + QString("')"));

		accept();
	}
}
