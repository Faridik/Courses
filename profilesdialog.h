#pragma once

#include <QDialog>
#include <QLineEdit>

struct Profile
{
    QString firstName;
    QString lastName;
    QString login;
    QString email;
    QString password;
    bool    editable;
};

class ProfilesDialog : public QDialog
{
    Q_OBJECT

public:

    ProfilesDialog(const Profile &profile, QWidget *parent = nullptr);

private:

    void updateProfile(const Profile &profile);

    QLineEdit *_firstName;
    QLineEdit *_lastName;
    QLineEdit *_login;
    QLineEdit *_email;

    QWidget   *_cources;
    QWidget   *_sertificates;
    QWidget   *_teaching;

    Profile _profile;
};
