#include "widget.h"

#include <QLabel>
#include <QFile>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    QFile *file=new QFile("str.txt");
    QString str="";

    file->open(QFile::ReadOnly);
    str.append(file->read(qint64(64)));
    QLabel *l=new QLabel(str,this);
    file->close();
}

Widget::~Widget()
{

}
