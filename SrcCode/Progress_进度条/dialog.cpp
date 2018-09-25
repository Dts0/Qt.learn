#include "dialog.h"
#include "ui_dialog.h"
#include <QProgressDialog>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("Progress");

    FileNumL=new QLabel("文件数目:");
    FileNumLE=new QLineEdit("100000");

    ProgressType=new QLabel("显示类型:");
    comboBox=new QComboBox;
    comboBox->addItem("ProgressBar");
    comboBox->addItem("ProgressDialog");

    ProgressBar=new QProgressBar;

    startBtn=new QPushButton("开始");

    Layout=new QGridLayout(this);
    Layout->addWidget(FileNumL,0,0);
    Layout->addWidget(FileNumLE,0,1);
    Layout->addWidget(ProgressType,1,0);
    Layout->addWidget(comboBox,1,1);
    Layout->addWidget(ProgressBar,2,0,1,2);
    Layout->addWidget(startBtn,3,1);

    Layout->setMargin(15);
    Layout->setSpacing(10);

    connect(startBtn,SIGNAL(clicked(bool)),this,SLOT(startProgress()));
}

void Dialog::startProgress()
{
    int num=FileNumLE->text().toInt();

    if(comboBox->currentIndex()==0)
    {
        ProgressBar->setRange(0,num);
        for(int i=0;i<num;i++)
            ProgressBar->setValue(i);

    }
    else if(comboBox->currentIndex()==1)
    {
        QProgressDialog *ProgressDialog=new QProgressDialog(this);

        ProgressDialog->setWindowModality(Qt::WindowModal);
        ProgressDialog->setWindowTitle("Please wait...");
        ProgressDialog->setLabelText("Copying...");
        ProgressDialog->setCancelButtonText("Cancel");
        ProgressDialog->setRange(0,num);
        for(int i=0;i<num;i++)
        {
            ProgressDialog->setValue(i);
            if(ProgressDialog->wasCanceled())
                return;
        }

    }
}

Dialog::~Dialog()
{
    delete ui;
}
