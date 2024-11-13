#include "canvas.h"
#include "ui_canvas.h"
#include <QImage>
#include <QSize>
#include <QMouseEvent>
#include <QDebug>

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

    if (onionSkinToggled)
    {
        renderOnionSkin(painter, prevImage);
        renderOnionSkin(painter, nextImage);
    }

    const double OPACITY_FULL = 1.0;
    painter.setOpacity(OPACITY_FULL);

    QImage scaledImage = image->scaled(size(), Qt::KeepAspectRatio);
    painter.drawImage(0, 0, scaledImage);
}

void Canvas::renderOnionSkin(QPainter& painter, QImage* frame)
{
    const double OPACITY_ONION = 0.6;
    painter.setOpacity(OPACITY_ONION);

    QImage scaledImage = frame->scaled(size(), Qt::KeepAspectRatio);
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
    // TODO: When the image is scaled up, this doesn't color the correct pixels.
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
