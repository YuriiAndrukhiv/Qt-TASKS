#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>

class QLineEdit;
class QPushButton;

class Calculator : public QWidget
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();


private:
    QLineEdit *mLineArgumentOne;
    QLineEdit *mLineArgumentTwo;
    QLineEdit *mLineResult;

    QPushButton *mPushButtonPlus;
    QPushButton *mPushButtonMinus;
    QPushButton *mPushButtonMultiply;
    QPushButton *mpushButtonDivision;
    QPushButton *mPushButtonC;

signals:

private slots:
    void argumentsPlus();
    void argumentsMinus();
    void argumentsMultiply();
    void argumentsDivision();
    void argumentsC();
};

#endif // CALCULATOR_H
