#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QSize>
#include "Sprite.h"

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:

    QImage* image;

    QImage* prevImage;

    QImage* nextImage;

    explicit Canvas(QWidget *parent = nullptr);

    ~Canvas();

    void switchImage(QImage& newImage, QImage& newPrevImage, QImage& newNextImage);

private:
    Ui::Canvas *ui;

    void paintEvent(QPaintEvent *event) override;

    bool onionSkinToggled = false;

    void renderImage(QPainter& painter, QImage* frame, const double opacity);

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

public slots:
    void toggleOnionSkin();

signals:
    void changePixel(QImage& imageToUpdate, int x, int y);

};

#endif // CANVAS_H
