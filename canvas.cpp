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
     if (event->button() == Qt::LeftButton)
     {
         // TODO: Add a chack to out out range coordinates.
        int x = event->pos().x()/(size().width()/image->width());
        int y = event->pos().y()/(size().height()/image->height());
        emit changePixel(*image, x, y);
        update();
     }
 }

 void Canvas::mouseMoveEvent(QMouseEvent *event)
     {
     if (event->buttons() & Qt::LeftButton)
     {
         int x = event->pos().x()/(size().width()/image->width());
         int y = event->pos().y()/(size().height()/image->height());
         emit changePixel(*image, x, y);
         update();
     }

 }

 void Canvas::mouseReleaseEvent(QMouseEvent *event)
 {
     if (event->button() == Qt::LeftButton)
     {
         // qDebug() << "mouse released";
     }
 }
