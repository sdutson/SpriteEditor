#include "model.h"
#include "Sprite.h"
#include <QImage>
#include <QColor>
#include <QString>
#include <QFile>
#include <QJsonDocument>

Model::Model(QObject *parent) : QObject(parent)
{
    Sprite sprite;
    fps = 1; // TODO: Temp hardcoded value, remove later.
}

void Model::changePixel(QImage& imageToUpdate, int x, int y)
{
    if (erasing)
    {
        imageToUpdate.setPixelColor(x, y, Qt::transparent);
    }
    else
    {
        imageToUpdate.setPixelColor(x, y, penColor);
    }
    emit spriteUpdated();
    emit displayAnimation(sprite, fps);
}

void Model::setToolToPen()
{
    erasing = false;
}

void Model::setToolToEraser()
{
    erasing = true;
}

void Model::setColor(QColor color)
{
    penColor = color;
}

QImage& Model::addFrame(int index)
{
    return sprite.addFrame(index);
    emit spriteUpdated();
}

QImage& Model::getFrame(int index)
{
    return sprite.getFrame(index);
    emit spriteUpdated();
}

QImage& Model::deleteFrame(int index)
{
    return sprite.deleteFrame(index);
}

int Model::getSize()
{
    return sprite.getSize();
}

void Model::saveSprite(QString filepath)
{
    QJsonDocument jsonDoc(sprite.saveJSON());
    QFile jsonFile(filepath);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(jsonDoc.toJson());
}

void Model::loadSprite(QString filepath)
{
    // TODO: Load in the QJsonObject(If inproperly formatted, simply return.)
    // TODO: call loadFromJson() and reassign the output to 'sprite'. (If null don't reassign and simply return.)
    // TODO: Inform the view it needs to updated and DELETE all data from previous sprite.
    // TODO: Should we warn the user if they are going to overwrite data?

}


