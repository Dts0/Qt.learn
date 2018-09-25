#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
private slots:
    void startProgress();
private:
    Ui::Dialog *ui;
    QLabel *FileNumL;
    QLineEdit *FileNumLE;
    QLabel *ProgressType;
    QComboBox *comboBox;
    QProgressBar *ProgressBar;
    QPushButton *startBtn;
    QGridLayout *Layout;
};

#endif // DIALOG_H
