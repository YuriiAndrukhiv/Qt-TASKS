#include "imageviewer.h"
#include <QApplication>

int main(int lArgc, char *lArgv[])
{
    QApplication lApplication(lArgc, lArgv);
    ImageViewer lImageViewer;
    lImageViewer.show();

    return lApplication.exec();
}
