#include "changeinfo.h"
#include <QApplication>
#include <QSplitter>
#include <QListWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setFont(QFont("AR PL Kaitim GB"));

    QSplitter *SplitterMain=new QSplitter(Qt::Horizontal);
    SplitterMain->setOpaqueResize(true);
    QListWidget *List=new QListWidget(SplitterMain);
    List->insertItem(0,"基本信息");
    List->insertItem(1,"联系方式");
    List->insertItem(2,"详细资料");

    ChangeInfo *content=new ChangeInfo(SplitterMain);

    QObject::connect(List,SIGNAL(currentRowChanged(int)),content->Stack,SLOT(setCurrentIndex(int)));

    SplitterMain->setWindowTitle("修改用户资料");
    SplitterMain->show();

    //Dialog w;
    //w.show();

    return a.exec();
}
