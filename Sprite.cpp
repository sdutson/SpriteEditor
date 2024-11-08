#include "Sprite.h"
#include <QImage>

using std::vector;

Sprite::Sprite()
{
    vector<QImage> frames;
}

void Sprite::addFrame()
{
    QImage emptyImage(dimensions.first, dimensions.second, QImage::Format_ARGB32);
    // emptyImage.fill(Qt::transparent); TODO: Default should be transperant. Uncomment this before submission.
    emptyImage.fill(Qt::white);
    frames.push_back(emptyImage);
}

void Sprite::deleteFrame(int index)
{

}

QImage& Sprite::getFrame(int index)
{
    return frames.at(index);
}

void Sprite::setName(const string& name)
{

}
