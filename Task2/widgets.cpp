#include "widgets.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

Widgets::Widgets(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *lHBoxLayout = new QHBoxLayout;
    QHBoxLayout *lHBoxLayout2 = new QHBoxLayout;
    QHBoxLayout *lHBoxLayout3 = new QHBoxLayout;
    QHBoxLayout *lHBoxLayout4 = new QHBoxLayout;
    QHBoxLayout *lHBoxLayout5 = new QHBoxLayout;
    QVBoxLayout *lVBoxLayout = new QVBoxLayout;

    mLCDNumber = new QLCDNumber;
    mLCDNumber ->display(50);

    mDial = new QDial;
    mDial -> setRange(0, 99);
    mDial -> setValue(50);

    mScroolBar = new QScrollBar;
    mScroolBar -> setOrientation(Qt::Horizontal);
    mScroolBar -> setValue(50);

    mScroolBar = new QScrollBar;
    mScroolBar -> setOrientation(Qt::Horizontal);
    mScroolBar -> setValue(50);

    mSlider = new QSlider;
    mSlider -> setOrientation(Qt::Vertical);
    mSlider -> setValue(50);

    mProgressBar = new QProgressBar;
    mProgressBar -> setOrientation(Qt::Horizontal);
    mProgressBar -> setValue(50);

    lHBoxLayout -> addWidget(mLCDNumber);
    lHBoxLayout2 -> addWidget(mDial);
    lHBoxLayout2 -> addWidget(mScroolBar);
    lHBoxLayout4 -> addWidget(mSlider);
    lHBoxLayout5 -> addWidget(mProgressBar);


    lVBoxLayout -> addLayout(lHBoxLayout);
    lVBoxLayout -> addLayout(lHBoxLayout2);
    lVBoxLayout -> addLayout(lHBoxLayout3);
    lVBoxLayout -> addLayout(lHBoxLayout4);
    lVBoxLayout -> addLayout(lHBoxLayout5);

    connect(mDial, SIGNAL(valueChanged(int)), mLCDNumber, SLOT(display(int)));
    connect(mDial, SIGNAL(valueChanged(int)), mSlider, SLOT(setValue(int)));
    connect(mDial, SIGNAL(valueChanged(int)), mScroolBar, SLOT(setValue(int)));
    connect(mDial, SIGNAL(valueChanged(int)), mProgressBar, SLOT(setValue(int)));

    connect(mScroolBar, SIGNAL(valueChanged(int)), mLCDNumber, SLOT(display(int)));
    connect(mScroolBar, SIGNAL(valueChanged(int)), mDial, SLOT(setValue(int)));
    connect(mScroolBar, SIGNAL(valueChanged(int)), mSlider, SLOT(setValue(int)));
    connect(mScroolBar, SIGNAL(valueChanged(int)), mProgressBar, SLOT(setValue(int)));

    connect(mSlider, SIGNAL(valueChanged(int)), mLCDNumber, SLOT(display(int)));
    connect(mSlider, SIGNAL(valueChanged(int)), mDial, SLOT(setValue(int)));
    connect(mSlider, SIGNAL(valueChanged(int)), mScroolBar, SLOT(setValue(int)));
    connect(mSlider, SIGNAL(valueChanged(int)), mProgressBar, SLOT(setValue(int)));

    connect(mProgressBar, SIGNAL(valueChanged(int)), mLCDNumber, SLOT(display(int)));
    connect(mProgressBar, SIGNAL(valueChanged(int)), mDial, SLOT(setValue(int)));
    connect(mProgressBar, SIGNAL(valueChanged(int)), mScroolBar, SLOT(setValue(int)));


    setGeometry(100, 100, 300, 300);
    setLayout(lVBoxLayout);
    setWindowTitle("Qt task #2");
}
