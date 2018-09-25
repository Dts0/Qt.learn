#include "contact.h"

Contact::Contact(QWidget *parent) : QWidget(parent)
{
    emailL=new QLabel("电子邮件:");
    emailLE=new QLineEdit;
    addressL=new QLabel("联系地址:");
    addressLE=new QLineEdit;
    mailNumL=new QLabel("邮政编码:");
    mailNumLE=new QLineEdit;
    mobilePhoneL=new QLabel("移动电话:");
    mobilePhoneLE=new QLineEdit;
    checkReceivable=new QCheckBox("接收留言");
    officePhoneL=new QLabel("办公电话:");
    officePhoneLE=new QLineEdit;

    Layout=new QGridLayout(this);
    //Layout->setMargin(15);
    Layout->setSpacing(10);
    Layout->addWidget(emailL,0,0);
    Layout->addWidget(emailLE,0,1);
    Layout->addWidget(addressL,1,0);
    Layout->addWidget(addressLE,1,1);
    Layout->addWidget(mailNumL,2,0);
    Layout->addWidget(mailNumLE,2,1);
    Layout->addWidget(mobilePhoneL,3,0);
    Layout->addWidget(mobilePhoneLE,3,1);
    Layout->addWidget(checkReceivable,3,2);
    Layout->addWidget(officePhoneL,4,0);
    Layout->addWidget(officePhoneLE,4,1);

    Layout->setSizeConstraint(QLayout::SetFixedSize);
}
