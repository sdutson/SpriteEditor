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

void Canvas::paintEvent(QPaintEvent* event) {
    bool OnionSkin = true; // TODO: Replace this with signal.
    if (OnionSkin)
    {
        // TODO: Render prev & next frame in lighter opacity, changes are purely visual.
    }
    else
    {
        // TODO: Render frame normally
    }

    QPainter painter(this);
    QImage scaledImage = image->scaled(size(), Qt::KeepAspectRatio);
    painter.drawImage(0, 0, scaledImage);
}

void Canvas::switchImage(QImage& newImage)
{
    image = &newImage;
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
