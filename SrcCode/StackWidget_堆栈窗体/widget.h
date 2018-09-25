#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include <QStackedWidget>

#include <QLayout>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QLabel *l1;
    QLabel *l2;
    QLabel *l3;
    QListWidget *List;
    QStackedWidget *Stack;


};

#endif // WIDGET_H
