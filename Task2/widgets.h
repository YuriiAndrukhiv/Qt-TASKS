#ifndef WIDGETS_H
#define WIDGETS_H

#include <QWidget>
#include <QLCDNumber>
#include <QDial>
#include <QSlider>
#include <QScrollBar>
#include <QProgressBar>

class Widgets : public QWidget
{
    Q_OBJECT
public:
    explicit Widgets(QWidget *parent = nullptr);

signals:

public slots:

private slots:
//    void showNumber();

private:
    QLCDNumber *mLCDNumber;
    QDial *mDial;
    QSlider *mSlider;
    QScrollBar *mScroolBar;
    QProgressBar *mProgressBar;

};

#endif // WIDGETS_H
