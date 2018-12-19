#include "filterdialog.h"

#include <QBoxLayout>
#include <QCheckBox>
#include <QDateEdit>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QSpinBox>
#include <QTableView>

FilterDialog::FilterDialog(QWidget *parent) : QDialog{parent}
{
    auto *titleOption = new QCheckBox{tr("Название:")};
    auto *titleFilter = new QLineEdit{};
    titleFilter->setEnabled(false);
    connect(titleOption, &QCheckBox::toggled, titleFilter, &QLineEdit::setEnabled);

    auto row = 0;

    auto *grid  = new QGridLayout{};
    grid->addWidget(titleOption, row, 0);
    grid->addWidget(titleFilter, row, 1);
    row++;



    auto *authorOption = new QCheckBox{tr("Автор:")};
    auto *authorFilter = new QLineEdit{};
    authorFilter->setEnabled(false);
    connect(authorOption, &QCheckBox::toggled, authorFilter, &QLineEdit::setEnabled);

    grid->addWidget(authorOption, row, 0);
    grid->addWidget(authorFilter, row, 1);
    row++;



    auto *tagsOption = new QCheckBox{tr("Тэги:")};
    auto *tagsFilter = new QLineEdit{};
    tagsFilter->setEnabled(false);
    connect(tagsOption, &QCheckBox::toggled, tagsFilter, &QLineEdit::setEnabled);

    grid->addWidget(tagsOption, row, 0);
    grid->addWidget(tagsFilter, row, 1);
    row++;



    auto *dateOption = new QCheckBox{tr("Дата:")};
    auto *dateFilter = new QDateEdit{};
    dateFilter->setEnabled(false);
    connect(dateOption, &QCheckBox::toggled, dateFilter, &QDateEdit::setEnabled);

    grid->addWidget(dateOption, row, 0);
    grid->addWidget(dateFilter, row, 1);
    row++;

    auto *searchFilters = new QGroupBox{tr("Фильтры поиска:")};
    searchFilters->setLayout(grid);

    auto *vbox = new QBoxLayout{QBoxLayout::TopToBottom};

    auto *sortByTitle  = new QRadioButton{tr("По названию")};
    auto *sortByAuthor = new QRadioButton{tr("По автору")};
    auto *sortByDate   = new QRadioButton{tr("По дате")};
    auto *sortByViews  = new QRadioButton{tr("По числу просмотров")};
    auto *sortByRating = new QRadioButton{tr("По рейтингу")};

    vbox->addWidget(sortByTitle);
    vbox->addWidget(sortByAuthor);
    vbox->addWidget(sortByDate);
    vbox->addWidget(sortByViews);
    vbox->addWidget(sortByRating);

    auto *sortFilters = new QGroupBox{tr("Настройки сортировки:")};
    sortFilters->setCheckable(true);
    sortFilters->setChecked(false);
    sortFilters->setLayout(vbox);

    auto *apply = new QPushButton{tr("Применить")};

    auto *hbox = new QBoxLayout{QBoxLayout::LeftToRight};
    hbox->addSpacerItem(new QSpacerItem{0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding});


    auto *cancel = new QPushButton{tr("Отмена")};
    connect(cancel, &QPushButton::clicked, this, &QDialog::reject);

    hbox->addWidget(cancel);
    hbox->addWidget(apply);

    vbox = new QBoxLayout{QBoxLayout::TopToBottom};
    vbox->addWidget(searchFilters);
    vbox->addWidget(sortFilters);
    vbox->addLayout(hbox);

    connect(apply, &QPushButton::clicked, this, [=]()
    {
         _filters.title  = titleOption->isChecked() ? titleFilter->text() : "";
         _filters.author = authorOption->isChecked() ? authorFilter->text() : "";
         _filters.tags = tagsOption->isChecked() ? tagsFilter->text() : "";
         _filters.date = dateOption->isChecked() ? dateFilter->date() : QDate{};

         _filters.sort = SortBy::Nothing;

         if (searchFilters->isChecked())
         {
             if (sortByTitle)
                 _filters.sort = SortBy::Title;
             else if (sortByAuthor)
                 _filters.sort = SortBy::Author;
             else if (sortByDate)
                 _filters.sort = SortBy::Date;
             else if (sortByViews)
                 _filters.sort = SortBy::Views;
             else if (sortByRating)
                 _filters.sort = SortBy::Rating;
         }

        this->accept();
    });   

    setLayout(vbox);

    setWindowTitle(tr("Поиск курсов"));
    setModal(true);
}
