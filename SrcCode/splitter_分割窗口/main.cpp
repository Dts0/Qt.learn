#include "mainwindow.h"
#include <QApplication>
#include <QSplitter>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setFont(QFont("ZYSong18030"));
    QSplitter *sWindowL=new QSplitter(Qt::Horizontal);//default=Qt::Horizontal
    QTextEdit *textLeft=new QTextEdit("Left",sWindowL);
    textLeft->setAlignment(Qt::AlignCenter);//居中对齐
    //end left
    QSplitter *sWindowR=new QSplitter(Qt::Vertical,sWindowL);
    //sWindowR->setOpaqueResize(false);
    QTextEdit *textRightUp=new QTextEdit("RightUp",sWindowR);
    textRightUp->setAlignment(Qt::AlignCenter);
    QTextEdit *textRightDown=new QTextEdit("RightDown",sWindowR);
    textRightDown->setAlignment(Qt::AlignCenter);
    //end right

    //sWindowL->setStretchFactor(1,1);
    sWindowL->setWindowTitle("Splitter");
    sWindowL->show();
    //MainWindow w;
    //w.show();

    return a.exec();
}
