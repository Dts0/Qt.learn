#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    color=new QColor(0,0,0);
    brush=new QBrush(*color);
    scene=new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(*brush);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_GetR_sliderMoved(int position)
{
    ui->RedL->setText(QString::number(position));
    color->setRed(position);
    brush->setColor(*color);
    ui->graphicsView->setBackgroundBrush(*brush);
}

void Widget::on_GetG_sliderMoved(int position)
{
    ui->GreenL->setText(QString::number(position));
    color->setGreen(position);
    brush->setColor(*color);
    ui->graphicsView->setBackgroundBrush(*brush);
}

void Widget::on_GetB_sliderMoved(int position)
{
    ui->BlueL->setText(QString::number(position));
    color->setBlue(position);
    brush->setColor(*color);
    ui->graphicsView->setBackgroundBrush(*brush);
}
