#pragma once

#include <QDialog>
#include <QDate>

enum class SortBy : qint32
{
    Nothing = 0,
    Title,
    Author,
    Date,
    Views,
    Rating
};

struct Filters
{
   QString title;
   QString tags;
   QString author;
   QDate   date;
   SortBy  sort;
};

class FilterDialog : public QDialog
{
    Q_OBJECT

public:


    FilterDialog(QWidget *parent = nullptr);

    inline const Filters& filters() const { return _filters; }

private:

    Filters _filters;
};
