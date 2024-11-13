#include "Sprite.h"
#include <QImage>
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QByteArray>
#include <QBuffer>
#include <QPainter>

using std::vector;

///
/// \brief Sprite class - Stores and updates all needed data for a sprite object.
/// Reviewed By: Sam Dutson - u1406827

Sprite::Sprite()
{
    vector<QImage> frames;
}

void Sprite::setDimensions(QPair<int, int> dimensions)
{
    this->dimensions = dimensions;
    for(QImage& frame: frames)
    {
        QImage resized(dimensions.first, dimensions.second, QImage::Format_ARGB32);
        resized.fill(Qt::transparent);

        QPainter painter(&resized);
        painter.drawImage(0, 0, frame);
        painter.end();

        frame = resized;
    }
}

int Sprite::addFrame(int index)
{
    QImage emptyImage(dimensions.first, dimensions.second, QImage::Format_ARGB32);
    emptyImage.fill(Qt::transparent);

    frames.insert(frames.begin() + index, emptyImage);
    return index;
}

int Sprite::copyFrame(int index)
{
    QImage copyImage = frames[index].copy();
    frames.insert(frames.begin() + index + 1, copyImage);
    return index + 1;
}

int Sprite::deleteFrame(int index)
{
    frames.erase(frames.begin() + index);
    if(index == 0)
    {
        return index;
    }
    return index - 1;
}

QImage& Sprite::getFrame(int index)
{
    try
    {
        return frames.at(index);
    }
    catch(...)
    {
        static QImage transparentImage(dimensions.first, dimensions.second, QImage::Format_ARGB32);
        transparentImage.fill(Qt::transparent);
        return transparentImage;
    }
}

void Sprite::setName(const string& newName)
{
    this->name = QString::fromStdString(newName); // TODO: How to change this?
}

int Sprite::getSize()
{
    return frames.size();
}

QString Sprite::getName()
{
    return this->name;
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
        frame.save(&buffer, "PNG");
        QString convertedImage = QString::fromUtf8(byteArray.toBase64());

        jsonFrames.append(convertedImage);
    }
    spriteJson["frames"] = jsonFrames;

    return spriteJson;
}

Sprite Sprite::loadFromJSON(QJsonObject spriteJson)
{
    Sprite loadedSprite;
    try
    {
        if(!spriteJson.contains("frames") || !spriteJson["frames"].isArray())
        {
            qWarning("Frames could not be loaded.");
            loadedSprite.frames.clear();
            return loadedSprite;
        }
        QJsonArray encodedFrames = spriteJson["frames"].toArray();

        for(const QJsonValue &jsonFrame: encodedFrames)
        {
            if(!jsonFrame.isString())
            {
                qWarning("Frame is improperly formatted");
                loadedSprite.frames.clear();
                return loadedSprite;
            }
            QByteArray byteArray = QByteArray::fromBase64(jsonFrame.toString().toUtf8());
            QImage image;
            if(!image.loadFromData(byteArray))
            {
                qWarning("Unable to load image from json.");
                loadedSprite.frames.clear();
                return loadedSprite;
            }
            loadedSprite.frames.push_back(image);
        }

        if(!spriteJson.contains("name") || !spriteJson["name"].isString()
            || !spriteJson.contains("width") || !spriteJson.contains("height"))
        {
            qWarning("Name and dimensions improperly formatted.");
            loadedSprite.frames.clear();
            return loadedSprite;
        }

        loadedSprite.name = spriteJson["name"].toString();
        loadedSprite.dimensions.first = spriteJson["width"].toInt();
        loadedSprite.dimensions.second = spriteJson["height"].toInt();
    }
    catch(...)
    {
        qWarning("Exception thrown when loading sprite.");
        loadedSprite.frames.clear();
        return loadedSprite;
    }
    return loadedSprite;
}
