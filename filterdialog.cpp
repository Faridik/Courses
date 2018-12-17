#include "filterdialog.h"

#include <QBoxLayout>
#include <QCheckBox>
#include <QDateEdit>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QTableView>

FilterDialog::FilterDialog(QWidget *parent) : QDialog{parent}
{
    auto *vbox = new QBoxLayout{QBoxLayout::TopToBottom};
    auto *hbox = new QBoxLayout{QBoxLayout::LeftToRight};

    auto *label = new QLabel{tr("Название курса:")};
    label->setAlignment(Qt::AlignVCenter|Qt::AlignRight);

    auto *courseTitle = new QLineEdit{};

    hbox->addWidget(label);
    hbox->addWidget(courseTitle);

    label = new QLabel{tr("Автор:")};
    label->setAlignment(Qt::AlignVCenter|Qt::AlignRight);

    auto *author = new QLineEdit{};

    hbox->addSpacing(10);
    hbox->addWidget(label);
    hbox->addWidget(author);

    auto *table = new QTableView{};

    vbox->addLayout(hbox);
    vbox->addWidget(table, 1);

    auto *homeButton = new QPushButton{tr("Вернуться")};
    connect(homeButton, &QPushButton::clicked, this, &QDialog::reject);

    hbox = new QBoxLayout{QBoxLayout::LeftToRight};
    hbox->addSpacerItem(new QSpacerItem{0, 0, QSizePolicy::Expanding, QSizePolicy::MinimumExpanding});
    hbox->addWidget(homeButton);

    vbox->addLayout(hbox);

    setLayout(vbox);

    setWindowTitle(tr("Поиск курсов"));
    setModal(true);
    setMinimumSize(640, 480);
}
