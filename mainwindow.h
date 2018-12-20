#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sqldb.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
	QString user;
	sqldb *db;

public slots:
    void signOut();
    void openCoursesWindow();
    void openProfile();
    void openLoginWindow();
    void openSigninWindow();    
};

#endif // MAINWINDOW_H
