#pragma once

#include <QDialog>
#include <QGridLayout>
#include <QtSql/QSqlQuery>

#include "filterdialog.h"


class CoursesDialog : public QDialog
{
    Q_OBJECT

public:

    CoursesDialog(const Filters &filters, QWidget *parent = nullptr);


    void applyFilters(const Filters &filters);
    void showPage(qint32 p);

private:

    Filters _filters;

    QGridLayout *_grid;

	QSqlQuery query;

	qint32 itemsCount;

    qint32 _page;
    qint32 _viewsPerPage;
};
