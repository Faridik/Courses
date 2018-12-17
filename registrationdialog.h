#pragma once

#include <QDialog>

class RegistrationDialog : public QDialog
{
    Q_OBJECT

    struct User
    {
        QString firstName;
        QString lastName;
        QString login;
        QString email;
        QString pass;
    };

public:

    RegistrationDialog(QWidget *parent = nullptr);

public slots:

    void registerNewUser(const User &user);
};
