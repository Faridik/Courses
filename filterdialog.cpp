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
    hbox->addWidget(apply);

    vbox = new QBoxLayout{QBoxLayout::TopToBottom};
    vbox->addWidget(searchFilters);
    vbox->addWidget(sortFilters);
    vbox->addLayout(hbox);
    vbox->addSpacerItem(new QSpacerItem{0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding});


    auto *table = new QTableView{};


    connect(apply, &QPushButton::clicked, this, [=]()
    {
        /// TODO - здесь перебираем наши фильтры и заполняем запрос или что там
        ///
        /// например:
        /// if (titleOption->isChecked())
        /// {
        ///     auto title = titleFilter->text();
        ///    // пихаем куда то
        /// }
    });

    hbox = new QBoxLayout{QBoxLayout::LeftToRight};
    hbox->addWidget(table, 1);
    hbox->addLayout(vbox);

    vbox = new QBoxLayout{QBoxLayout::TopToBottom};
    vbox->addLayout(hbox);

    auto *homeButton = new QPushButton{tr("Вернуться")};
    connect(homeButton, &QPushButton::clicked, this, &QDialog::reject);

    hbox = new QBoxLayout{QBoxLayout::LeftToRight};
    hbox->addWidget(homeButton);
    hbox->addSpacerItem(new QSpacerItem{0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding});

    vbox->addLayout(hbox);
    setLayout(vbox);

    setWindowTitle(tr("Поиск курсов"));
    setModal(true);
    setMinimumSize(640, 480);
}
