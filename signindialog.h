#pragma once

#include <QDialog>

class SignInDialog : public QDialog
{
    Q_OBJECT

public:
    SignInDialog(int *userid, QWidget *parent = nullptr);

public slots:

    void signin(int *userid, const QString &login, const QString &pass);
};
