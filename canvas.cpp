#include "canvas.h"
#include "ui_canvas.h"
#include <QImage>
#include <QMouseEvent>

///
/// \brief canvas.cpp - Custom widget that allows a user to draw and erase on an image.
/// Reviewed By: Will Jackson - u0710534
///

Canvas::Canvas(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Canvas)
{
    ui->setupUi(this);
}

Canvas::~Canvas()
{
    delete ui;
}

void Canvas::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    const double OPACITY_FULL = 1.0;
    const double OPACITY_ONION = 0.6;
    if (onionSkinToggled)
    {
        renderImage(painter, prevImage, OPACITY_ONION);
        renderImage(painter, nextImage, OPACITY_ONION);
    }
    renderImage(painter, image, OPACITY_FULL);
}

void Canvas::renderImage(QPainter& painter, QImage* image, const double opacity)
{

    painter.setOpacity(opacity);
    QImage scaledImage = image->scaled(size(), Qt::KeepAspectRatio);
    painter.drawImage(0, 0, scaledImage);
}

void Canvas::switchImage(QImage& newImage, QImage& newPrevImage, QImage& newNextImage)
{
    image     = &newImage;
    prevImage = &newPrevImage;
    nextImage = &newNextImage;
    update();
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        int x = event->pos().x()/(size().width()/image->width());
        int y = event->pos().y()/(size().height()/image->height());
        if (x >= 0 && x < image->width() && y >= 0 && y < image->height())
        {
            emit changePixel(*image, x, y);
            update();
        }
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        int x = event->pos().x()/(size().width()/image->width());
        int y = event->pos().y()/(size().height()/image->height());
        if (x >= 0 && x < image->width() && y >= 0 && y < image->height())
        {
            emit changePixel(*image, x, y);
            update();
        }
    }
}

void Canvas::toggleOnionSkin()
{
    onionSkinToggled = !onionSkinToggled;
    update();
}
