#include <QApplication>
#include "catchbutton.h"

int main(int lArgc, char *lArgv[])
{
    QApplication lApplication(lArgc, lArgv);
    CatchButton button;
    button.show();

    return lApplication.exec();
}
