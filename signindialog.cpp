#include "signindialog.h"

#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCryptographicHash>
#include <QtSql/QSqlQuery>

#include "registrationdialog.h"

SignInDialog::SignInDialog(int *userid, QWidget *parent) : QDialog{parent}
{
    auto *vbox = new QBoxLayout{QBoxLayout::TopToBottom};

    auto *label = new QLabel{tr("Вход")};
    label->setAlignment(Qt::AlignCenter);

    auto *login = new QLineEdit{};
    login->setPlaceholderText(tr("Логин"));

    auto *pass  = new QLineEdit{};
    pass->setPlaceholderText(tr("Пароль"));
    pass->setEchoMode(QLineEdit::Password);

    auto *signinButton = new QPushButton{tr("Войти")};

    // при нажатии на вход - пытаемся войти
    connect(signinButton, &QPushButton::clicked, this, [=]()
    {
        signin(userid,login->text(), pass->text());
    });

    auto *registerButton = new QPushButton{tr("Регистрация")};

    // при нажатии на вход - пытаемся войти
    connect(registerButton, &QPushButton::clicked, this, [=]()
    {
        RegistrationDialog dialog{userid, this};

        if (dialog.exec() == QDialog::Accepted)
            this->accept();
    });


    auto *homeButton = new QPushButton{tr("Вернуться")};
    connect(homeButton, &QPushButton::clicked, this, &QDialog::reject);

    vbox->addSpacerItem(new QSpacerItem{0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding});
    vbox->addWidget(label);
    vbox->addWidget(login);
    vbox->addWidget(pass);    
    vbox->addWidget(signinButton);
    vbox->addWidget(registerButton);
    vbox->addWidget(homeButton);
    vbox->addSpacerItem(new QSpacerItem{0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding});

    auto *hbox = new QBoxLayout{QBoxLayout::LeftToRight};
    hbox->addSpacerItem(new QSpacerItem{0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding});
    hbox->addLayout(vbox);
    hbox->addSpacerItem(new QSpacerItem{0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding});

    setLayout(hbox);
    setWindowTitle(tr("Авторизация"));

    setMinimumSize(480, 360);
    setModal(true);
}

void SignInDialog::signin(int *userid, const QString &login, const QString &pass)
{
    Q_UNUSED(login);
    Q_UNUSED(pass);

	QSqlQuery query;
	query.exec(QString("SELECT * FROM users_con WHERE login = '") + login + QString("'"));
	if (query.next())
	{
		if (QCryptographicHash::hash((pass + query.value("salt").toString()).toUtf8(), QCryptographicHash::Sha256).toHex()
			== query.value("pass").toString().toUtf8())
		{
			// подключился
			*userid = query.value("id").toInt();
			accept();
		}
		else
		{
			/// TODO неверный логин или пароль
		}
	}
	else
	{
		/// TODO пользователь с таким логином не найден
	}
}
