#include <QApplication>
#include "trafficlight.h"


int main (int lArgc, char *lArgv[])
{
    QApplication lApplication (lArgc, lArgv);
    TrafficLight lTrafficLight;
    lTrafficLight.show();

    return lApplication.exec();
}
