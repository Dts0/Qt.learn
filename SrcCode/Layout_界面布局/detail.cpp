#include "detail.h"

Detail::Detail(QWidget *parent) : QWidget(parent)
{
    NationL=new QLabel("国家:");
    NationCBox=new QComboBox;
    NationCBox->insertItem(0,"中国");
    //The other nations

    ProvinceL=new QLabel("省份:");
    ProvinceCBox=new QComboBox;
    ProvinceCBox->insertItem(0,"北京");
    ProvinceCBox->insertItem(1,"山东");
    //The other provinces

    CityL=new QLabel("城市:");
    CityLE=new QLineEdit;

    IntroductionL=new QLabel("个人说明:");
    IntroductionTE=new QTextEdit;

    Layout=new QGridLayout(this);
    Layout->setMargin(15);
    Layout->setSpacing(10);
    Layout->addWidget(NationL,0,0);
    Layout->addWidget(NationCBox,0,1);
    Layout->addWidget(ProvinceL,1,0);
    Layout->addWidget(ProvinceCBox,1,1);
    Layout->addWidget(CityL,2,0);
    Layout->addWidget(CityLE,2,1);
    Layout->addWidget(IntroductionL,3,0);
    Layout->addWidget(IntroductionTE,3,1);

}
