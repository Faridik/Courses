#pragma once

#include <QWidget>
#include <QLabel>

class CourceView : public QWidget
{
    Q_OBJECT

public:

    CourceView(QWidget *parent = nullptr);

    void setCourse(const QString &imagePath, const QString &text);

protected:

    void mousePressEvent(QMouseEvent *) override;

private:

    QLabel *_image;
    QLabel *_text;
};

