#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>

class ImageViewer : public QWidget
{
    Q_OBJECT
public:
    explicit ImageViewer(QWidget *parent = nullptr);

private:
    QLabel *mViewImage;
    QLineEdit *mPathImage;

private slots:
    void downloadImage();
};



#endif // IMAGEVIEWER_H
