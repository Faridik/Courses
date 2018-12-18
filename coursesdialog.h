#pragma once

#include <QDialog>
#include <QGridLayout>

class CoursesDialog : public QDialog
{
    Q_OBJECT

public:

    CoursesDialog(QWidget *parent = nullptr);

    void showPage(qint32 p);

private:

    QGridLayout *_grid;

    qint32 _page;
    qint32 _viewsPerPage;
};
