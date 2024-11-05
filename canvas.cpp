#include "canvas.h"
#include "ui_canvas.h"

Canvas::Canvas(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Canvas)
    , image("me.png")
{
    ui->setupUi(this);
    update();
}

Canvas::~Canvas()
{
    delete ui;
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
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
