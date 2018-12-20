#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "courcesinfo.h"
#include "studydialog.h"

CourcesInfo::CourcesInfo(QWidget *parent) : QDialog{parent}
{
   auto *hbox= new QBoxLayout{QBoxLayout::TopToBottom};
   auto *grid = new QGridLayout{};

   _image = new QLabel();
   _image->setMaximumSize(40,40);

   hbox->addWidget(_image);

    auto *name = new QLabel{tr("Название курса")};
    name->setAlignment(Qt::AlignCenter);
    auto *autor = new QLabel{tr("Автор курса")};
    auto *desc  = new QLabel{tr("Описание")};

     auto row = 0;

    _name = new QLineEdit{};
    _autor= new QLineEdit{};
    _desc = new QLineEdit{};


    auto readOnly = true;

    _name->setReadOnly(readOnly);
    _autor->setReadOnly(readOnly);
    _desc->setReadOnly(readOnly);

    auto *studyButton = new QPushButton{tr("Пройти курс")};

    connect(studyButton, &QPushButton::clicked, this, [=]()
    {
        StudyDialog dialog{this};

        if (dialog.exec() == QDialog::Accepted)
            this->accept();
    });

   auto *exitButton = new QPushButton{tr("Вернуться")};
   connect(exitButton, &QPushButton::clicked, this, &QDialog::reject);

    grid->addWidget(name,row,0);
    grid->addWidget(_name, row, 1);
    row++;

    grid->addWidget(autor,row,0);
    grid->addWidget(_autor, row, 1);
    row++;

    grid->addWidget(desc,row,0);
    grid->addWidget(_desc, row, 1);
    row++;

    grid->addWidget(exitButton);
    grid->addWidget(studyButton);


    hbox->addLayout(grid);
    setLayout(hbox);

    setWindowTitle(tr("Страница курса"));
    setModal(true);
    setMinimumSize(480, 360);


}
