#include "Sprite.h"
#include <QImage>

using std::vector;

Sprite::Sprite()
{
    vector<QImage> frames;
}

void Sprite::addFrame()
{
    QImage emptyImage(dimensions, dimensions, QImage::Format_ARGB32);
    frames.push_back(emptyImage);
}

void Sprite::deleteFrame(QImage &frame)
{

}

QImage& Sprite::getFrame(int index)
{
    return frames.at(index);
}
