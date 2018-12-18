#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "profilewindow.h"

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
    profileWindow *profile;    

public slots:
    void openCoursesWindow();
    void openProfile();
    void openLoginWindow();
    void openSigninWindow();
    void openFilterWindow();

    void backFromProfile();
};

#endif // MAINWINDOW_H
