#ifndef DETAIL_H
#define DETAIL_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QGridLayout>

class Detail : public QWidget
{
    Q_OBJECT
public:
    explicit Detail(QWidget *parent = nullptr);
private:
    QLabel *NationL;
    QComboBox *NationCBox;
    QLabel *ProvinceL;
    QComboBox *ProvinceCBox;
    QLabel *CityL;
    QLineEdit *CityLE;
    QLabel *IntroductionL;
    QTextEdit *IntroductionTE;

    QGridLayout *Layout;
};

#endif // DETAIL_H
