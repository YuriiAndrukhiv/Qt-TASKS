#include <QApplication>
#include "calculator.h"


int main (int lArgc, char * lArgv [])
{
     QApplication lApplication (lArgc, lArgv);

     Calculator lCalculator;
     lCalculator.show ();


     return lApplication.exec ();
}
