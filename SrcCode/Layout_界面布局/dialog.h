#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QFrame>
#include <QComboBox>
#include <QPixmap>
#include <QLineEdit>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QGridLayout *mainLayout;
    //left
    QLabel *UserNameL;
    QLabel *NameL;
    QLabel *SexL;
    QLabel *DepartmentL;
    QLabel *AgeL;
    QLabel *OthersL;
    QLineEdit *UserNameLE;
    QLineEdit *NameLE;
    QComboBox *SexCBox;
    QLineEdit *DepartmentLE;
    QLineEdit *AgeLE;
    QTextEdit *OthersTE;
    QGridLayout *LeftLayout;

    //right
    QLabel *HeadL;
    QLabel *HeadIconL;
    QPushButton *UpdateHeadIconBtn;
    QHBoxLayout *TopRightLayout;

    QLabel *IntroductionL;
    QTextEdit *IntroductionTE;
    QVBoxLayout *RightLayout;

    QPushButton *OKBtn;
    QPushButton *CancelBtn;
    QHBoxLayout *ButtomLayout;

};

#endif // DIALOG_H
