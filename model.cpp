#include "model.h"
#include "Sprite.h"
#include <QImage>
#include <QColor>

Model::Model(QObject *parent) : QObject(parent)
{
    Sprite sprite;
}

void Model::changePixel(QImage& imageToUpdate, int x, int y)
{
    if (erasing)
    {
        imageToUpdate.setPixelColor(x, y, Qt::white);
    }
    else
    {
        imageToUpdate.setPixelColor(x, y, penColor);
    }
}

void Model::addFrame()
{
    sprite.addFrame();
}

QImage& Model::getFrame(int index)
{
    return sprite.getFrame(index);
}
