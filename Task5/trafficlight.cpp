#include "trafficlight.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

TrafficLight::TrafficLight(QWidget *parent) : QWidget(parent)
{
    init();

    connect(mStartButton, SIGNAL(clicked()), this, SLOT(start()));
    connect(mStopButton, SIGNAL(clicked()), this, SLOT(stop()));

    connect(mTimer, SIGNAL(timeout()), this, SLOT(changeLight()));
}

void TrafficLight::start()
{
    mTimer ->start(1500);
}

void TrafficLight::stop()
{
    mTimer ->stop();
}

void TrafficLight::changeLight()
{
    activeLight++;
    activeLight = activeLight % 3;
    switch (activeLight)
    {
    case 0: mRedRadioButton->setChecked(true);
        break;
    case 1: mOrangeRadioButton->setChecked(true);
        break;
    case 2: mGreenRadioButton->setChecked(true);
        break;

    }
}

void TrafficLight::init()
{
    mRedRadioButton = new QRadioButton("Red");
    mOrangeRadioButton = new QRadioButton("Orange");
    mGreenRadioButton = new QRadioButton("Green");

    mStartButton = new QPushButton("Start");
    mStopButton = new QPushButton("Stop");

    QHBoxLayout *lHBoxLayoutArgumentOne = new QHBoxLayout;
    QHBoxLayout *lHBoxLayoutArgumentTwo = new QHBoxLayout;
    QHBoxLayout *lHBoxLayoutArgumentThree = new QHBoxLayout;
    QHBoxLayout *lHBoxLayoutArgumentFourth = new QHBoxLayout;
    QVBoxLayout *lVBoxLayout = new QVBoxLayout;

    lHBoxLayoutArgumentOne -> addWidget(mRedRadioButton);
    lHBoxLayoutArgumentTwo -> addWidget(mOrangeRadioButton);
    lHBoxLayoutArgumentThree -> addWidget(mGreenRadioButton);
    lHBoxLayoutArgumentFourth -> addWidget(mStartButton);
    lHBoxLayoutArgumentFourth -> addWidget(mStopButton);

    lVBoxLayout -> addLayout(lHBoxLayoutArgumentOne);
    lVBoxLayout -> addLayout(lHBoxLayoutArgumentTwo);
    lVBoxLayout -> addLayout(lHBoxLayoutArgumentThree);
    lVBoxLayout -> addLayout(lHBoxLayoutArgumentFourth);
    lVBoxLayout -> addLayout(lHBoxLayoutArgumentFourth);


    setLayout(lVBoxLayout);
    setGeometry(x(), y(), 250, 50);
    setWindowTitle("Traffic light");

    mTimer = new QTimer(this);
}
