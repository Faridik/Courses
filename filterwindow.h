#ifndef FILTERWINDOW_H
#define FILTERWINDOW_H

#include <QMainWindow>

namespace Ui {
class filterWindow;
}

class filterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit filterWindow(QWidget *parent = 0);
    ~filterWindow();

private:
    Ui::filterWindow *ui;

signals:
    void back();
public slots:
    void backToMain();
};

#endif // FILTERWINDOW_H
