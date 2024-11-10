#include "Sprite.h"
#include <QImage>
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QByteArray>
#include <QBuffer>

using std::vector;

Sprite::Sprite()
{
    vector<QImage> frames;
}

QImage& Sprite::addFrame(int index)
{
    QImage emptyImage(dimensions.first, dimensions.second, QImage::Format_ARGB32);
    emptyImage.fill(Qt::transparent);

    frames.insert(frames.begin() + index, emptyImage);
    return frames[index];
}

QImage& Sprite::deleteFrame(int index)
{
    frames.erase(frames.begin() + index);
    if(index == 0)
    {
        return frames[index];
    }
    return frames[index - 1];
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

vector<QImage>& Sprite::getFrames()
{
    return frames;
}

QJsonObject Sprite::saveJSON()
{
    QJsonObject spriteJson;
    spriteJson["name"] = this->name;
    spriteJson["width"] = this->dimensions.first;
    spriteJson["height"] = this->dimensions.second;

    // Store the frames(Encoded 64 bit) to the json object.
    QJsonArray jsonFrames;
    for(const QImage& frame : this->frames)
    {
        QByteArray byteArray;
        QBuffer buffer(&byteArray);
        buffer.open(QIODevice::WriteOnly);
        frame.save(&buffer, "PNG");  // TODO: Should we use a differnt format here?
        QString convertedImage = QString::fromUtf8(byteArray.toBase64());

        jsonFrames.append(convertedImage);
    }
    spriteJson["frames"] = jsonFrames;

    return spriteJson;
}

Sprite& Sprite::loadFromJSON(QJsonObject spriteJson)
{
    // TODO: Load frames, dimensions, and name from the file. Build a sprite object and return.
}
