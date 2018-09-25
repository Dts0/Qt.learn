#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Title");
    QTextEdit *text1=new QTextEdit(this);
    text1->setText("Left");

    text1->setAlignment(Qt::AlignCenter);
    text1->move(50,100);

    QDockWidget *Dock=new QDockWidget("Dock1",this);
    Dock->setFeatures(QDockWidget::DockWidgetFeature::AllDockWidgetFeatures);
    Dock->setAllowedAreas(Qt::RightDockWidgetArea);
    QTextEdit *te1=new QTextEdit("Hello Dock1",Dock);
    Dock->setWidget(te1);
    addDockWidget(Qt::RightDockWidgetArea,Dock);

}

MainWindow::~MainWindow()
{
    delete ui;
}
