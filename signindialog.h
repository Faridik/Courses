#pragma once

#include <QDialog>

class SignInDialog : public QDialog
{
    Q_OBJECT

public:

    SignInDialog(QWidget *parent = nullptr);

public slots:

    void signin(const QString &login, const QString &pass);
};
