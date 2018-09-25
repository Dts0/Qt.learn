#ifndef CHANGEINFO_H
#define CHANGEINFO_H

#include "dialog.h"
#include "contact.h"
#include "detail.h"
#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>


class ChangeInfo : public QFrame
{
    Q_OBJECT
public:
    explicit ChangeInfo(QWidget *parent = nullptr);

    ~ChangeInfo();
    QStackedWidget *Stack;
signals:

public slots:
private:
    Dialog *BaseInfo;
    Contact *contact;
    Detail *detail;

    QPushButton *ChangeBtn;
    QPushButton *CloseBtn;
    QHBoxLayout *BtnLayout;


    QVBoxLayout *RightLayout;

};

#endif // CHANGEINFO_H
