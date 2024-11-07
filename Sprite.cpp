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
    // emptyImage.fill(Qt::transparent); TODO: Default should be transperant. Uncomment this before submission.
    emptyImage.fill(Qt::white);
    frames.push_back(emptyImage);
}

void Sprite::deleteFrame(QImage &frame)
{

}

QImage& Sprite::getFrame(int index)
{
    return frames.at(index);
}
