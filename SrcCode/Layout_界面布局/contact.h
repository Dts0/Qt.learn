#ifndef CONTACT_H
#define CONTACT_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QCheckBox>

class Contact : public QWidget
{
    Q_OBJECT
public:
    explicit Contact(QWidget *parent = nullptr);
private:
    QLabel *emailL;
    QLabel *addressL;
    QLabel *mailNumL;
    QLabel *mobilePhoneL;
    QLabel *officePhoneL;
    QLineEdit *emailLE;
    QLineEdit *addressLE;
    QLineEdit *mailNumLE;
    QLineEdit *mobilePhoneLE;
    QLineEdit *officePhoneLE;
    QCheckBox *checkReceivable;

    QGridLayout *Layout;
};

#endif // CONTACT_H
