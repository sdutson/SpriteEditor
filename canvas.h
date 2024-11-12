#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QSize>

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:

    QImage* image;

    explicit Canvas(QWidget *parent = nullptr);

    ~Canvas();

    void switchImage(QImage& newImage);

private:
    Ui::Canvas *ui;

    void paintEvent(QPaintEvent *event) override;

 protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;


signals:
    void changePixel(QImage& imageToUpdate, int x, int y);

};

#endif // CANVAS_H
