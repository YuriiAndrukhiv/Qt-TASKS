#include "widget.h"

#include <QLabel>
#include <QPushButton>


Widget::Widget(QWidget *parent) : QWidget(parent)
{
    QLabel *lLabel = new QLabel(this);
    lLabel -> setGeometry(50, 0, 100, 30);

    QPushButton *lPushButton = new QPushButton (this);
    lPushButton -> setGeometry(100, 50, 100, 30);
    lPushButton -> setText("Close");

    connect(lPushButton, SIGNAL(clicked()), this, SLOT(close()));

    setGeometry (x(), y(), 300, 150);
    setWindowTitle ("Qt task #1");
}
