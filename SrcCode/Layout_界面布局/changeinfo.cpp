#include "changeinfo.h"

ChangeInfo::ChangeInfo(QWidget *parent) : QFrame(parent)
{
    BaseInfo=new Dialog();
    contact=new Contact();
    detail=new Detail();
    Stack=new QStackedWidget;
    Stack->setFrameStyle(QFrame::Panel|QFrame::Raised);
    Stack->addWidget(BaseInfo);
    Stack->addWidget(contact);
    Stack->addWidget(detail);

    ChangeBtn=new QPushButton("修改");
    CloseBtn=new QPushButton("关闭");
    BtnLayout=new QHBoxLayout;
    BtnLayout->setStretch(0,1);
    BtnLayout->setStretch(1,1);
    BtnLayout->setAlignment(Qt::AlignCenter);
    BtnLayout->addWidget(ChangeBtn);
    BtnLayout->addWidget(CloseBtn);

    RightLayout=new QVBoxLayout(this);
    RightLayout->setMargin(10);
    RightLayout->setSpacing(10);
    RightLayout->addWidget(Stack);
    RightLayout->addLayout(BtnLayout);



}
ChangeInfo::~ChangeInfo()
{
    delete BaseInfo;
    delete contact;
    delete detail;
}
