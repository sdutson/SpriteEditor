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
