#include "Sprite.h"
#include <QImage>
#include <QString>

using std::vector;

Sprite::Sprite()
{
    vector<QImage> frames;
}

QImage& Sprite::addFrame()
{
    QImage emptyImage(dimensions.first, dimensions.second, QImage::Format_ARGB32);
    // emptyImage.fill(Qt::transparent); TODO: Default should be transperant. Uncomment this before submission.
    emptyImage.fill(Qt::white);
    frames.push_back(emptyImage);
    return frames.back();
}

QImage& Sprite::deleteFrame()
{
    frames.erase(frames.end() - 1);
    return frames.back();
}

QImage& Sprite::getFrame(int index)
{
    return frames.at(index);
}

void Sprite::setName(const string& newName)
{
    this->name = QString::fromStdString(newName); // TODO: How to change this?
}

int Sprite::getSize()
{
    return frames.size();
}
