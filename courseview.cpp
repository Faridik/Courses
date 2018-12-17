#include "courseview.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QPicture>
#include <QPixmap>

CourceView::CourceView(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *l = new QHBoxLayout();
    QLabel *image = new QLabel();
    QLabel *text = new QLabel();

    QPixmap pixmap;
    bool status = pixmap.load(":/images/123.png");

    if (status)
        image->setPixmap(pixmap);


    text->setText("Great description");

    l->addWidget(image);
    l->addWidget(text);
    setLayout(l);
}
