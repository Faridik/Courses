#ifndef COURSESWINDOW_H
#define COURSESWINDOW_H

#include <QMainWindow>

namespace Ui {
class coursesWindow;
}

class coursesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit coursesWindow(QWidget *parent = 0);
    ~coursesWindow();

private:
    Ui::coursesWindow *ui;

signals:
    void back();
public slots:
    void backToMain();
};

#endif // COURSESWINDOW_H
