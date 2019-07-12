#include <QApplication>
#include "widget.h"

int main (int lArgc, char *lArgv[])
{
    QApplication lApplication (lArgc, lArgv);
    Widget lWidget;
    lWidget.show();


    return lApplication.exec();

}
