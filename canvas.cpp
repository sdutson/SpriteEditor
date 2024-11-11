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
    if (firstPaint) {
        drawTransparencyGrid();
        firstPaint = false;
    }
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
    painter.setBrush(Qt::lightGray);
    painter.setPen(Qt::NoPen);
    painter.drawRect(0, 0, width(), height());
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
         // TODO: Add a chack to out out range coordinates.
        int x = event->pos().x()/(size().width()/image->width());
        int y = event->pos().y()/(size().height()/image->height());
        if (x > 0 && x < image->width() && y > 0 && y < image->height())
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

 void Canvas::mouseReleaseEvent(QMouseEvent *event)
 {
     if (event->button() == Qt::LeftButton)
     {
         // qDebug() << "mouse released";
     }
 }


 void Canvas::drawTransparencyGrid()
 {
     QPainter painter(this);
     painter.setPen(Qt::NoPen);

     for (int x = 0; x < width(); x+=(size().width()/image->width()))
     {
         for (int y = 0; y < height(); y+=(size().height()/image->height()))
         {
             qDebug() << x << " " << y;
             if ((x / (size().width() / image->width()) + y / (size().height() / image->height())) % 2 == 0)
                 painter.setBrush(Qt::lightGray);
             else
                 painter.setBrush(Qt::white);

             painter.drawRect(x, y, size().width()/image->width(), size().height()/image->height());
         }
     }
 }
