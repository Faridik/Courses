#ifndef COURCESINFO_H
#define COURCESINFO_H

#include <QLabel>
#include <QLineEdit>
#include <QDialog>

class CourcesInfo : public QDialog
{
    Q_OBJECT

public:

    CourcesInfo(QWidget *parent = nullptr);

private:
    QLabel *_image;
    QLineEdit *_name;
    QLineEdit *_autor;
    QLineEdit *_desc;

};


#endif // COURCESINFO_H
