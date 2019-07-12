#include "calculator.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>

Calculator::Calculator(QWidget *parent) : QWidget(parent)
{
    QLabel *lLabelArgumentOne = new QLabel("Argument one");
    QLabel *lLabelArgumentTwo = new QLabel("Argument two");
    QLabel *lLabelResult = new QLabel("Result");

    mLineArgumentOne = new QLineEdit();
    mLineArgumentTwo = new QLineEdit();
    mLineResult = new QLineEdit();
    mLineResult -> setReadOnly(true);

    mPushButtonPlus = new QPushButton("+");
    mPushButtonMinus = new QPushButton("-");
    mPushButtonMultiply = new QPushButton("*");
    mpushButtonDivision = new QPushButton("/");
    mPushButtonC = new QPushButton("C");

    QHBoxLayout *lHBoxLayoutArgumentOne = new QHBoxLayout;
    QHBoxLayout *lHBoxLayoutArgumentTwo = new QHBoxLayout;
    QHBoxLayout *lHBoxLayoutResult = new QHBoxLayout;
    QHBoxLayout *lHBoxLayoutOperation = new QHBoxLayout;
    QVBoxLayout *lVBoxLayout = new QVBoxLayout;

    lHBoxLayoutArgumentOne -> addWidget(lLabelArgumentOne);
    lHBoxLayoutArgumentTwo -> addWidget(lLabelArgumentTwo);
    lHBoxLayoutResult -> addWidget(lLabelResult);

    lHBoxLayoutArgumentOne -> addWidget(mLineArgumentOne);
    lHBoxLayoutArgumentTwo -> addWidget(mLineArgumentTwo);
    lHBoxLayoutResult -> addWidget(mLineResult);

    lHBoxLayoutOperation -> addWidget(mPushButtonPlus);
    lHBoxLayoutOperation -> addWidget(mPushButtonMinus);
    lHBoxLayoutOperation -> addWidget(mPushButtonMultiply);
    lHBoxLayoutOperation -> addWidget(mpushButtonDivision);
    lHBoxLayoutOperation -> addWidget(mPushButtonC);

    lVBoxLayout -> addLayout(lHBoxLayoutArgumentOne);
    lVBoxLayout -> addLayout(lHBoxLayoutArgumentTwo);
    lVBoxLayout -> addLayout(lHBoxLayoutResult);
    lVBoxLayout -> addLayout(lHBoxLayoutOperation);


    connect(mPushButtonPlus, SIGNAL(clicked()), this, SLOT(argumentsPlus()));
    connect(mPushButtonMinus, SIGNAL(clicked()), this, SLOT(argumentsMinus()));
    connect(mPushButtonMultiply, SIGNAL(clicked()), this, SLOT(argumentsMultiply()));
    connect(mpushButtonDivision, SIGNAL(clicked()), this, SLOT(argumentsDivision()));
    connect(mPushButtonC, SIGNAL(clicked()), this, SLOT(argumentsC()));


    setLayout(lVBoxLayout);
    setWindowTitle("Qt task #3");
}

Calculator::~Calculator()
{

}

void Calculator::argumentsPlus()
{
    mLineResult -> setText(QString::number(mLineArgumentOne -> displayText().toDouble() + mLineArgumentTwo -> displayText().toDouble()));
}

void Calculator::argumentsMinus()
{
    mLineResult -> setText(QString::number(mLineArgumentOne -> displayText().toDouble() - mLineArgumentTwo -> displayText().toDouble()));
}

void Calculator::argumentsMultiply()
{
     mLineResult -> setText(QString::number(mLineArgumentOne -> displayText().toDouble() * mLineArgumentTwo -> displayText().toDouble()));
}

void Calculator::argumentsDivision()
{
    auto secondArgument = mLineArgumentTwo -> displayText().toDouble();

    if(secondArgument != 0)
         mLineResult -> setText(QString::number(mLineArgumentOne -> displayText().toDouble() / secondArgument));

    else
        mLineResult->setText("Division by zero");
}

void Calculator::argumentsC()
{
    mLineResult -> setText(QString::number(0));
}
