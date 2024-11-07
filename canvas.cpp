#include "canvas.h"
#include "ui_canvas.h"
#include <QImage>
#include <QSize>
#include <QMouseEvent>
#include <QDebug>

Canvas::Canvas(QWidget *parent)
    : QWidget(parent)
    , image(16, 16, QImage::Format_ARGB32)
    , ui(new Ui::Canvas)
{
    ui->setupUi(this);
    image.fill(Qt::white);
}

Canvas::~Canvas()
{
    delete ui;
}

void Canvas::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    QImage scaledImage = image.scaled(size(), Qt::KeepAspectRatio);
    painter.drawImage(0, 0, scaledImage);
}

void Canvas::switchImage(QImage &newImage)
{
    image = newImage;
}

 void Canvas::mousePressEvent(QMouseEvent *event)
 {
     if (event->button() == Qt::LeftButton)
     {
         image.setPixelColor(event->pos().x()/(size().width()/16), event->pos().y()/(size().height()/16), Qt::black);
         update();
     }
 }

 void Canvas::mouseMoveEvent(QMouseEvent *event)
     {
     if (event->buttons() & Qt::LeftButton)
     {
        image.setPixelColor(event->pos().x()/(size().width()/16), event->pos().y()/(size().height()/16), Qt::black);
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
