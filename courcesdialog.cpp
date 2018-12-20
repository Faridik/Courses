#include "coursesdialog.h"

#include <QBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QtSql/QSqlQuery>
#include <QVariant>

#include "courseview.h"
#include "filterdialog.h"

CoursesDialog::CoursesDialog(const Filters &filters, QWidget *parent) : QDialog{parent},
    _filters{filters},
    _page{0},
    _viewsPerPage{6} /// TODO - сколько на 1й странице курсов, должно быть четным, очевидно
{



    _grid = new QGridLayout{};

    for (auto i = 0; i < _viewsPerPage; i++)
    {
        _grid->addWidget(new CourceView{}, i / 2, i % 2);
    }

    auto *vbox = new QBoxLayout{QBoxLayout::TopToBottom};
    auto *hbox = new QBoxLayout{QBoxLayout::LeftToRight};

    auto *filtersButton = new QPushButton{tr("Поиск курсов")};
    connect(filtersButton, &QPushButton::clicked, this, [=]()
    {
        FilterDialog dialog{this};

        if (dialog.exec() == QDialog::Accepted)
        {
            this->applyFilters(dialog.filters());
            this->showPage(0);
        }
    });

    hbox->addSpacerItem(new QSpacerItem{0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding});
    hbox->addWidget(filtersButton);

    vbox->addLayout(hbox);

	auto *backward = new QPushButton{ tr("Предыдущие") };
    auto *forward  = new QPushButton{tr("Следующие")};
 

    connect(backward, &QPushButton::clicked, this, [=]()
    {
        this->showPage(_page - 1);
    });

    connect(forward, &QPushButton::clicked, this, [=]()
    {
        this->showPage(_page + 1);
    });

    auto *homeButton = new QPushButton(tr("Вернуться"));
    connect(homeButton, &QPushButton::clicked, this, &QDialog::reject);

    hbox = new QBoxLayout{QBoxLayout::LeftToRight};

    hbox->addWidget(homeButton);
    hbox->addSpacerItem(new QSpacerItem{0, 0, QSizePolicy::Expanding, QSizePolicy::MinimumExpanding});
	hbox->addWidget(backward);
	hbox->addWidget(forward);

    vbox->addLayout(_grid, 1);
    vbox->addSpacerItem(new QSpacerItem{0, 0, QSizePolicy::Expanding, QSizePolicy::MinimumExpanding});
    vbox->addLayout(hbox, 0);

    /// TODO - запрос в бд чего показывать

    showPage(0);

    setLayout(vbox);

    setModal(true);
    setMinimumSize(640, 480);
    setWindowTitle(tr("Популярные курсы"));
}

void CoursesDialog::applyFilters(const Filters &filters)
{
	/// TODO - магия бд тут +
	QString from;
	bool prev = false;

	from = QString("FROM courses_inf c ");

	if ((filters.author != "") || (filters.sort == SortBy::Author))
		from += QString("JOIN users u ON c.userowner_id = u.id ");

	if ((filters.author != "") ||
		(filters.date != QDate{}) ||
		(filters.tags != "") ||
		(filters.title != ""))
	{
		from += QString("WHERE ");

		if (filters.author != "") //lower() for sql, toLower() for qt
		{
			QStringList list = filters.author.split(" ");

			from += "(";
			from += QString("lower(u.firstname) like '%") + list[0].toLower() + QString("%' OR ");
			from += QString("lower(u.lastname) like '%") + list[0].toLower() + QString("%'");
			for (int i = 1; i < list.size(); ++i)
			{
				from += QString(") AND (lower(u.firstname) like '%") + list[i].toLower() + QString("%' OR ");
				from += QString("lower(u.lastname) like '%") + list[i].toLower() + QString("%'");
			}
			from += " ) ";

			prev = true;
		}

		if (filters.date != QDate{})
		{
			if (prev) from += QString("AND ");
			from += QString("c.creationdate = '") + filters.date.toString("yyyy-MM-dd") + QString("'::date ");
			prev = true;
		}

		if (filters.tags != "")
		{
			if (prev) from += QString("AND ");
			
			QString tags = filters.tags;
			tags.remove(QChar('<'));
			tags.remove(QChar('>'));

			QStringList list = tags.split(",");

			from += QString("lower(c.tags) like '%") + list[0].toLower().trimmed() + QString("%' ");
			for (int i = 1; i < list.size(); ++i)
				from += QString("AND lower(c.tags) like '%") + list[i].toLower().trimmed() + QString("%' ");

			prev = true;
		}

		if (filters.title != "")
		{
			if (prev) from += QString("AND ");

			QStringList list = filters.title.split(" ");

			from += QString("lower(c.title) like '%") + list[0].toLower() + QString("%' ");
			for (int i = 1; i < list.size(); ++i)
				from += QString("AND lower(c.title) like '") + list[i].toLower() + QString("%' ");

			prev = true;
		}
	}

	query.exec("SELECT count(*) " + from);
	query.next();
	itemsCount = query.value(0).toInt();

	if (filters.sort == SortBy::Author)
		from += QString("ORDER BY u.firstname, u.lastname");
	if (filters.sort == SortBy::Date)
		from += QString("ORDER BY c.creationdate DESC");
	if (filters.sort == SortBy::Rating)
		from += QString("ORDER BY c.rating DESC");;
	if (filters.sort == SortBy::Title)
		from += QString("ORDER BY c.title");;
	if (filters.sort == SortBy::Views)
		from += QString("ORDER BY c.views DESC");;

	query.exec("SELECT * " + from);
	query.next();
}

void CoursesDialog::showPage(qint32 p)   /// заполнение по 6 шт
{
    itemsCount = 17; /// TODO - тяните из бд, чисто для примера
	query.exec("SELECT count(*) FROM courses_inf"); //применение фильтров?

    auto max = itemsCount / _viewsPerPage + 1;

    _page = qMin(qMax(0, p), max - 1);
    max   = (_page + 1) * _viewsPerPage;
    auto min = _page * _viewsPerPage;

    for (auto i = min; i < max; i++)
    {
        auto *item = static_cast<CourceView*>(_grid->itemAtPosition((i - min) / 2, (i - min) % 2)->widget());

        if (i < itemsCount)
        {
            /// TODO - пока чисто символически
            item->setCourse(":/images/123.png", QString::number(i));
            item->setEnabled(true);
        }
        else
        {
            /// TODO - пока чисто символически
            item->setCourse("", "");
            item->setEnabled(false);
        }
    }
}
