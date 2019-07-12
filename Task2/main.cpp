#include <QApplication>

#include <widgets.h>

int main (int lArgc, char *lArgv[])
{
    QApplication lApplication(lArgc, lArgv);

    Widgets lWidhets;
    lWidhets.show();

    return lApplication.exec();
}
