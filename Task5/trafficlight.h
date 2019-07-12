#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <QWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QTimer>

class TrafficLight : public QWidget
{
    Q_OBJECT
public:
    explicit TrafficLight(QWidget *parent = nullptr);

private slots:
    void start();
    void stop();
    void changeLight();

private:
    void init();

private:

    QRadioButton *mRedRadioButton;
    QRadioButton *mOrangeRadioButton;
    QRadioButton *mGreenRadioButton;

    QPushButton *mStartButton;
    QPushButton *mStopButton;

    QTimer *mTimer;

    int activeLight = 2;
};

#endif // TRAFFICLIGHT_H
