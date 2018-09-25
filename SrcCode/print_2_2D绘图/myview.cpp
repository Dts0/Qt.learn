#include "myview.h"
#include <QGLWidget>

MyView::MyView(QWidget *parent) :
    QGraphicsView(parent)
{

    resize(400, 400);
    setBackgroundBrush(QPixmap("../print_2/Cat.jpg"));
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 200, 200);

    QGraphicsRectItem *item1 = new QGraphicsRectItem(0,0,20,20);
    item1->setBrush(Qt::red);
    item1->setPos(10,0);
    scene->addItem(item1);

    QGraphicsRectItem *item2 = new QGraphicsRectItem(0,0,20,20);
    item2->setBrush(Qt::green);
    item2->setPos(40,0);
    scene->addItem(item2);
    //新建图形项组
    QGraphicsItemGroup *group = new QGraphicsItemGroup;
    group->addToGroup(item1);
    group->addToGroup(item2);
    scene->addItem(group);
    setScene(scene);

    setAlignment(Qt::AlignLeft | Qt::AlignTop);
    //手型拖动
    setDragMode(QGraphicsView::ScrollHandDrag);
    scene->setSceneRect(0, 0, 800, 800);

    QGLWidget *widget =new QGLWidget(this);
    setViewport(widget);

    //输出(10, 0)点的图形项
    qDebug() << "itemAt(10,0) : " <<itemAt(10, 0);
    qDebug() << "itemAt(40,0) : " <<itemAt(40, 0);
    qDebug() << "#################################";

}


void MyView::keyPressEvent(QKeyEvent *event)
{
    //输出场景中所有的图形项
    qDebug() << items();
    items().at(0)->setPos(100,0);
    items().at(1)->setPos(0,100);
    //执行默认的事件处理
    QGraphicsView::keyPressEvent(event);
}
//滚轮事件
void MyView::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0)
        scale(0.5,0.5);  //视图缩放
    else scale(2,2);
}

void MyView::mousePressEvent(QMouseEvent *event)
{

    QGraphicsView::mousePressEvent(event);

}
