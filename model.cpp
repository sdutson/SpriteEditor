#include "model.h"
#include "Sprite.h"
#include <QImage>
#include <QColor>

Model::Model(QObject *parent) : QObject(parent)
{
    Sprite sprite;
}

void Model::drawPixel(QImage& imageToUpdate, int x, int y)
{

}

void Model::erasePixel(QImage& imageToUpdate, int x, int y)
{

}

void Model::addFrame()
{
    sprite.addFrame();
}

QImage& Model::getFrame(int index)
{
    return sprite.getFrame(index);
}
