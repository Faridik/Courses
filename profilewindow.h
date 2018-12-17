#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include <QMainWindow>

namespace Ui {
class profileWindow;
}

class profileWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit profileWindow(QWidget *parent = 0);
    ~profileWindow();

private:
    Ui::profileWindow *ui;

signals:
    void back();
public slots:
    void backToMain();
};

#endif // PROFILEWINDOW_H
