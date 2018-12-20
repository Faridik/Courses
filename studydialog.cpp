#include "studydialog.h"

#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>

StudyDialog::StudyDialog(QWidget *parent) : QDialog{parent}
{
    auto *vbox = new QBoxLayout{QBoxLayout::TopToBottom};
    auto *grid = new QGridLayout{};
    auto *label = new QLabel{tr("Модули")};
    label->setAlignment(Qt::AlignCenter);

    auto *exitButton = new QPushButton{tr("Вернуться")};
    connect(exitButton, &QPushButton::clicked, this, &QDialog::reject);

    QTableView *view = new QTableView;

    /// TODO - Сделать вывод модулей в таблицу, модули из БД берем

    vbox->addWidget(label);
    vbox->addWidget(view);
    vbox->addWidget(exitButton);

    vbox->addLayout(grid);

    setLayout(vbox);
    setWindowTitle(tr("Прохождение курса"));

    setMinimumSize(480, 360);
    setModal(true);

}
