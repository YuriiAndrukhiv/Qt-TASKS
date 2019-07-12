#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QStringList>
#include <iostream>

int main(int argc, char * argv[])
{
    QCoreApplication lCoreApplication(argc, argv);
    if (lCoreApplication.arguments().size() < 2)
    {
        std::cout << "usage: read-file --path <file path>" << std::endl;
    }

    QFile lFile(lCoreApplication.arguments().at(2));
    if(!lFile.exists())
    {
        std::cout << "File not exists" << std::endl;
        return 1;
    }
    if(!lFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cout << lFile.errorString().toStdString() << std::endl;
        return 1;
    }

    std::cout << lFile.readAll().toStdString() << std::endl;

    lFile.close();
    return lCoreApplication.exec();
}
