#include <QCoreApplication>
#include <iostream>
#include "QTimer"
#include <boost/program_options.hpp>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTimer *ltimer = new QTimer;
    int t=0;

    boost::program_options::options_description optionDescription("Allowedoptions");
    optionDescription.add_options()
        ("help", "Produce help message")
        ("timeout", boost::program_options::value<int>(), "delay time")
        ;
    boost::program_options::variables_map vm;

    try
    {
    boost::program_options::store(boost::program_options::parse_command_line(argc,
                                                                             argv,
                                                                             optionDescription),
                                  vm);
    boost::program_options::notify(vm);

    if (vm.count("help"))
    {
        std::cout << optionDescription << std::endl;
    }
    if (vm.count("timeout"))
    {
        t = vm["timeout"].as<int>();
    }
    }

    catch(std::exception& ex)
    {
         std::cout << optionDescription << std::endl;
    }

    std::cout<<"Time delay:"<<t<<std::endl;

    QObject::connect (ltimer, SIGNAL(timeout()), &a, SLOT(quit()));
    ltimer ->start(t);


    return a.exec();
}
