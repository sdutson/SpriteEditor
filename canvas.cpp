#include "canvas.h"
#include "ui_canvas.h"
#include <QImage>
#include <QSize>

Canvas::Canvas(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Canvas)
    , image("/Users/samueldutson/QT/SpriteEditor/me.png")
{
    ui->setupUi(this);
}

Canvas::~Canvas()
{
    delete ui;
}

void Canvas::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    widgetSize = size();
    QImage scaledImage = image.scaled(widgetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    painter.drawImage(0, 0, scaledImage);
}

// void ScribbleArea::mousePressEvent(QMouseEvent *event)
// {
//     if (event->button() == Qt::LeftButton) {
//         lastPoint = event->position().toPoint();
//         scribbling = true;
//     }
// }

// void ScribbleArea::mouseMoveEvent(QMouseEvent *event)
// {
//     if ((event->buttons() & Qt::LeftButton) && scribbling)
//         drawLineTo(event->position().toPoint());
// }

// void ScribbleArea::mouseReleaseEvent(QMouseEvent *event)
// {
//     if (event->button() == Qt::LeftButton && scribbling) {
//         drawLineTo(event->position().toPoint());
//         scribbling = false;
//     }
// }
