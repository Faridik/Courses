#include "coursesdialog.h"

#include <QBoxLayout>
#include <QGridLayout>
#include <QPushButton>

#include "courseview.h"

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

    auto *forward  = new QPushButton{tr("Следующие")};
    auto *backward = new QPushButton{tr("Предыдущие")};

    connect(backward, &QPushButton::clicked, this, [=]()
    {
       this->showPage(_page + 1);
    });

    connect(forward, &QPushButton::clicked, this, [=]()
    {
       this->showPage(_page - 1);
    });

    auto *homeButton = new QPushButton(tr("Вернуться"));
    connect(homeButton, &QPushButton::clicked, this, &QDialog::reject);

    hbox->addWidget(homeButton);
    hbox->addSpacerItem(new QSpacerItem{0, 0, QSizePolicy::Expanding, QSizePolicy::MinimumExpanding});
    hbox->addWidget(forward);
    hbox->addWidget(backward);

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

void CoursesDialog::showPage(qint32 p)
{
    auto itemsCount = 17; /// TODO - тяните из бд, чисто для примера
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
