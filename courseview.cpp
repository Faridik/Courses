#include "courseview.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QPicture>
#include <QPixmap>

CourceView::CourceView(QWidget *parent) : QWidget(parent)
{
    auto *l = new QHBoxLayout();
    _image = new QLabel();
    _text = new QLabel();

    l->addWidget(_image);
    l->addWidget(_text);
    setLayout(l);
}

void CourceView::setCourse(const QString &imagePath, const QString &text)
{
    QPixmap pixmap;
    pixmap.load(imagePath);
    _image->setPixmap(pixmap);

    _text->setText(text);
}

void CourceView::mousePressEvent(QMouseEvent *)
{
    /// TODO - обрабатываем клик
}
