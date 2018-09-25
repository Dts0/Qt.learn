#include <myitem.h>
#include <QCursor>
#include <QGraphicsSceneMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QApplication>
#include <QWidget>
#include <QVariant>
/*
QRectF MyItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth / 2, 0 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}

void MyItem::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *,
                   QWidget *)
{
    //Q_UNUSED(option);  //标明该参数没有使用
    //Q_UNUSED(widget);

    painter->setBrush(!collidingItems().isEmpty()? Qt::red : Qt::green);
    painter->drawEllipse(0, 0, 20, 20);

}
MyItem::MyItem(){

        setToolTip("Click and drag me!");  //提示
        setCursor(Qt::OpenHandCursor);    //改变光标形状
        color = QColor(qrand() % 256, qrand() % 256, qrand() % 256);

        //图形项可获得焦点
        setFlag(QGraphicsItem::ItemIsFocusable);
}


void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() != Qt::LeftButton)
    {
        //如果不是鼠标左键按下，则忽略该事件
        event->ignore();
        return;
    }
    //如果是鼠标左键按下，改变光标形状
    setCursor(Qt::ClosedHandCursor);
}

void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(QLineF(event->screenPos(),
            event->buttonDownScreenPos(Qt::LeftButton)).length()
            < QApplication::startDragDistance())
    {
      //如果按下的点到现在的点的距离小于程序默认的拖动距离，表明没有拖动，则返回
        return;
    }
    //为event所在窗口部件新建拖动对象
    QDrag *drag = new QDrag(event->widget());
    //新建QMimeData对象，它用来存储拖动的数据
    QMimeData *mime = new QMimeData;
     //关联
    drag->setMimeData(mime);
    //放入颜色数据
    mime->setColorData(color);

    //新建QPixmap对象，它用来重新绘制圆形，在拖动时显示
    QPixmap pix(21,21);
    //pix.fill(Qt::white);
    QPainter painter(&pix);
    paint(&painter, 0, 0);
    drag->setPixmap(pix);

    //我们让指针指向圆形的(10,15)点
    drag->setHotSpot(QPoint(10, 15));
    //开始拖动
    drag->exec();
    //改变光标形状
    setCursor(Qt::OpenHandCursor);
}

void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::OpenHandCursor);    //改变光标形状
}


void MyItem::keyPressEvent(QKeyEvent *)
{
    moveBy(0, 10);  //相对现在的位置移动
}*/


RectItem::RectItem()
{
setAcceptDrops(true);  //设置接收拖放
color = QColor(Qt::lightGray);
//图形项可获得焦点
setFlag(QGraphicsItem::ItemIsFocusable);
setFlag(QGraphicsItem::ItemIsMovable);
}

QRectF RectItem::boundingRect() const
{
return QRectF(0, 0, 50, 50);
}

void RectItem::paint(QPainter *painter,
                const QStyleOptionGraphicsItem *,
                QWidget *)
{


    //如果与其他图形项碰撞则显示红色，否则显示绿色

    painter->setBrush(!collidingItems().isEmpty()? Qt::red : Qt::green);
painter->drawRect(0,0,50,50);

}


void RectItem::advance(int phase)
{
    if(!phase) return;  //如果phase为0，则返回
    moveBy(0,10);
}

void RectItem ::keyPressEvent(QKeyEvent *event)
{
    moveBy(0, 10);  //相对现在的位置移动
}

void RectItem::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
if(event->mimeData()->hasColor()) //如果拖动的数据中有颜色数据，便接收
{
   event->setAccepted(true);
   dragOver = true;
   update();
}
else event->setAccepted(false);
}

void RectItem::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
Q_UNUSED(event);
dragOver = false;
update();
}

void RectItem::dropEvent(QGraphicsSceneDragDropEvent *event)
{
dragOver = false;
if (event->mimeData()->hasColor())
  //我们通过类型转换来获得颜色
   color = qvariant_cast<QColor>(event->mimeData()->colorData());
update();
}
