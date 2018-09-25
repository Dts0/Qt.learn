#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("UserInfo");
    //left
    UserNameL=new QLabel("用户名:");
    UserNameLE=new QLineEdit;
    NameL=new QLabel("姓名:");
    NameLE=new QLineEdit;
    SexL=new QLabel("性别:");
    SexCBox=new QComboBox;
      SexCBox->addItem("男");
      SexCBox->addItem("女");
    DepartmentL=new QLabel("部门:");
    DepartmentLE=new QLineEdit;
    AgeL=new QLabel("年龄:");
    AgeLE=new QLineEdit;
    OthersL=new QLabel("备注:");
    OthersTE=new QTextEdit;
    //OthersL->setFrameStyle(QFrame::Panel|QFrame::Sunken);

    LeftLayout=new QGridLayout;
    LeftLayout->addWidget(UserNameL,0,0);
    LeftLayout->addWidget(UserNameLE,0,1);
    LeftLayout->addWidget(NameL,1,0);
    LeftLayout->addWidget(NameLE,1,1);
    LeftLayout->addWidget(SexL,2,0);
    LeftLayout->addWidget(SexCBox,2,1);
    LeftLayout->addWidget(DepartmentL,3,0);
    LeftLayout->addWidget(DepartmentLE,3,1);
    LeftLayout->addWidget(AgeL,4,0);
    LeftLayout->addWidget(AgeLE,4,1);
    LeftLayout->addWidget(OthersL,5,0);
    LeftLayout->addWidget(OthersTE,5,1);

    //

    //rightTop
    HeadL=new QLabel("头像:");
    HeadIconL=new QLabel;
    QPixmap icon("../Layout/logo.ico");
    HeadIconL->setPixmap(icon);
    HeadIconL->resize(icon.width(),icon.height());
    UpdateHeadIconBtn=new QPushButton("更新");

    TopRightLayout=new QHBoxLayout;
    TopRightLayout->setSpacing(20);
    TopRightLayout->addWidget(HeadL);
    TopRightLayout->addWidget(HeadIconL);
    TopRightLayout->addWidget(UpdateHeadIconBtn);

    //rightCenter
    IntroductionL=new QLabel("个人介绍:");
    IntroductionTE=new QTextEdit;

    //right
    RightLayout=new QVBoxLayout;
    RightLayout->setMargin(10);//边缘10px
    RightLayout->addLayout(TopRightLayout);
    RightLayout->addWidget(IntroductionL);
    RightLayout->addWidget(IntroductionTE);

    //Buttom
    OKBtn=new QPushButton("确定");
    CancelBtn=new QPushButton("取消");

    ButtomLayout=new QHBoxLayout;
    ButtomLayout->addWidget(OKBtn);
    ButtomLayout->addWidget(CancelBtn);

    //final
    mainLayout=new QGridLayout(this);
    mainLayout->addLayout(LeftLayout,0,0);
    mainLayout->addLayout(RightLayout,0,1);
    mainLayout->addLayout(ButtomLayout,1,1,Qt::AlignCenter);

    mainLayout->setSizeConstraint(QLayout::SetFixedSize);//固定大小

}

Dialog::~Dialog()
{
    delete ui;
}
