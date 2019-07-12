#ifndef CATCHBUTTON_H
#define CATCHBUTTON_H

#include <QWidget>
#include <QEvent>

class QPushButton;

class CatchButton : public QWidget
{
    Q_OBJECT
public:
    explicit CatchButton(QWidget *parent = nullptr);

protected:
    virtual void mouseMoveEvent(QMouseEvent *mouseEvent);

private:
    void init();
    bool hasButton(int mouseX, int mouseY);
    void moveButton();

private:
    QPushButton* mButton;
};

#endif // CATCHBUTTON_H
