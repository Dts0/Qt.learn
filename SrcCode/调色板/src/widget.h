#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QColor>
#include <QGraphicsItem>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


private slots:
    void on_GetR_sliderMoved(int position);

    void on_GetG_sliderMoved(int position);

    void on_GetB_sliderMoved(int position);

private:
    Ui::Widget *ui;
    QColor *color;
    QBrush *brush;
    QGraphicsScene *scene;
};


#endif // WIDGET_H
