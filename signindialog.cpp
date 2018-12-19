#include "signindialog.h"

#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "registrationdialog.h"

SignInDialog::SignInDialog(QWidget *parent) : QDialog{parent}
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
        signin(login->text(), pass->text());
    });

    auto *registerButton = new QPushButton{tr("Регистрация")};

    // при нажатии на вход - пытаемся войти
    connect(registerButton, &QPushButton::clicked, this, [=]()
    {
        RegistrationDialog dialog{this};

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

void SignInDialog::signin(const QString &login, const QString &pass)
{
    Q_UNUSED(login);
    Q_UNUSED(pass);

    /// TODO здесь обращаемся в БД, проверяем все и тд

    auto success = true;

    if (success)
    {
        /// TODO помечаем что где надо
        accept();
    }
    else
    {
        /// TODO помечаем поля с ошибками
    }
}
