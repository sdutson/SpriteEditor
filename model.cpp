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
    emit imageUpdated();
}

QImage& Model::addFrame(int index)
{
    return sprite.addFrame(index);
}

QImage& Model::getFrame(int index)
{
    return sprite.getFrame(index);
}

QImage& Model::deleteFrame(int index)
{
    return sprite.deleteFrame(index);
}

int Model::getSize()
{
    return sprite.getSize();
}

