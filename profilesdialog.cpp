#include "profilesdialog.h"

#include <QBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTabWidget>


ProfilesDialog::ProfilesDialog(const Profile &profile, QWidget *parent) : QDialog{parent},
    _profile{profile}
{
    auto *vbox = new QBoxLayout{QBoxLayout::TopToBottom};
    auto *hbox = new QBoxLayout{QBoxLayout::LeftToRight};

    auto *grid = new QGridLayout{};

    _firstName = new QLineEdit{};
    _lastName  = new QLineEdit{};
    _login     = new QLineEdit{};
    _email     = new QLineEdit{};

    auto readOnly = true;

    _firstName->setReadOnly(readOnly);
    _lastName->setReadOnly(readOnly);
    _login->setReadOnly(readOnly);
    _email->setReadOnly(readOnly);

    auto row = 0;

    auto *label = new QLabel{tr("Имя:")};

    grid->addWidget(label, row, 0);
    grid->addWidget(_firstName, row, 1);
    row++;

    label = new QLabel{tr("Фамилия:")};
    grid->addWidget(label, row, 0);
    grid->addWidget(_lastName, row, 1);
    row++;

    label = new QLabel{tr("Логин:")};
    grid->addWidget(label, row, 0);
    grid->addWidget(_login, row, 1);
    row++;

    label = new QLabel{tr("E-mail:")};
    grid->addWidget(label, row, 0);
    grid->addWidget(_email, row, 1);
    row++;

    if (_profile.editable)     /// если наш профиль то можем редак
    {
        auto *edit = new QPushButton{tr("Редактировать")};
        grid->addWidget(edit, row++, 1);

        connect(edit, &QPushButton::clicked, this, [=]()
        {
            auto p = _profile;

            if (true) /// TODO - dialog.exec return true
                this->updateProfile(p);
        });
    }

    hbox->addLayout(grid);
    hbox->addSpacerItem(new QSpacerItem{0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding});

    auto *group = new QGroupBox{tr("Профиль")};
    group->setLayout(hbox);

    auto *tabs    = new QTabWidget{};

    _cources = new QWidget{};
    _cources->setMinimumSize(480, 200);

    _sertificates = new QWidget{};
    _teaching = new QWidget{};

    tabs->addTab(_cources, tr("Курсы"));                /// TODO - форма отображения курсов, своих/чужих
    tabs->addTab(_sertificates, tr("Сертификаты"));  /// TODO - форма отображения сертификатов
    tabs->addTab(_teaching, tr("Преподавание")); /// TODO - форма отображения статистики

    auto *homeButton = new QPushButton{tr("Вернуться")};
    connect(homeButton, &QPushButton::clicked, this, &QDialog::reject);

    hbox = new QBoxLayout{QBoxLayout::LeftToRight};
    hbox->addSpacerItem(new QSpacerItem{0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding});
    hbox->addWidget(homeButton);

    vbox->addWidget(group);
    vbox->addWidget(tabs, 1);
    vbox->addLayout(hbox);

    setLayout(vbox);

    setWindowTitle(tr("Параметры профиля"));

    updateProfile(_profile);
}

void ProfilesDialog::updateProfile(const Profile &profile)
{
    _profile = profile;

    _firstName->setText(_profile.firstName);
    _lastName->setText(_profile.lastName);
    _login->setText(_profile.login);
    _email->setText(_profile.email);

    /// TODO - зполнить прочие виджеты
}
