#include "transparencygrid.h"
#include "ui_transparencygrid.h"
#include <QPainter>

TransparencyGrid::TransparencyGrid(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TransparencyGrid)
{
    ui->setupUi(this);
    imageWidth = 16;
    imageHeight = 16;
}

TransparencyGrid::~TransparencyGrid()
{
    delete ui;
}

void TransparencyGrid::setImageSize(int width, int height) {
    imageWidth = width;
    imageHeight = height;
}


void TransparencyGrid::paintEvent(QPaintEvent* event) {
    drawTransparencyGrid();
}

void TransparencyGrid::drawTransparencyGrid()
{
    QPainter painter(this);
    painter.setPen(Qt::NoPen);

    for (int x = 0; x < width(); x+=(size().width()/imageWidth))
    {
        for (int y = 0; y < height(); y+=(size().height()/imageHeight))
        {
            if ((x / (size().width() / imageWidth) + y / (size().height() / imageHeight)) % 2 == 0)
                painter.setBrush(Qt::lightGray);
            else
                painter.setBrush(Qt::white);

            painter.drawRect(x, y, size().width()/imageWidth, size().height()/imageHeight);
        }
    }
}
