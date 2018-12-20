#pragma once

#include <QDialog>

class SignInDialog : public QDialog
{
    Q_OBJECT

public:
	void setUserName(QString* un);
    SignInDialog(QWidget *parent = nullptr);

private:
	QString *username;

public slots:

    void signin(const QString &login, const QString &pass);
};
