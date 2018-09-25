
#include <QApplication>
#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QItemSelectionModel>

#include <QDirModel>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QSplitter>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDirModel *model=new QDirModel;

    QTreeView *tree=new QTreeView;
    QListView *list=new QListView;
    QTableView *table=new QTableView;

    tree->setModel(model);
    list->setModel(model);
    table->setModel(model);

    //tree->setSelectionMode(QAbstractItemView::MultiSelection);
    //list->setSelectionMode(QAbstractItemView::MultiSelection);
    //table->setSelectionMode(QAbstractItemView::MultiSelection);

    QObject::connect(tree,SIGNAL(doubleClicked(QModelIndex)),list,SLOT(setRootIndex(QModelIndex)));
    QObject::connect(tree,SIGNAL(doubleClicked(QModelIndex)),table,SLOT(setRootIndex(QModelIndex)));

    QSplitter *splitter=new QSplitter;
    splitter->addWidget(tree);
    splitter->addWidget(list);
    splitter->addWidget(table);
    splitter->setWindowTitle("Cloose File");

    splitter->show();
    //Widget w;
    //w.show();

    return a.exec();
}
