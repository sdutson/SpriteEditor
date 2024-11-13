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
    emit displayAnimation(sprite);
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

int Model::addFrame(int index)
{
    return sprite.addFrame(index);
}

QImage& Model::getFrame(int index)
{
    return sprite.getFrame(index);
}

int Model::deleteFrame(int index)
{
    return sprite.deleteFrame(index);
}

int Model::copyFrame(int index)
{
    return sprite.copyFrame(index);
}

int Model::getSize()
{
    return sprite.getSize();
}

void Model::setSpriteDimensions(QPair<int, int> newDimensions)
{
    sprite.setDimensions(newDimensions);
}

void Model::setName(const string &newName)
{
    sprite.setName(newName);
}

QString Model::getName()
{
    return sprite.getName();
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
    Sprite loadedSprite;
    try
    {
        QFile jsonFile(filepath);
        if (!jsonFile.open(QFile::ReadOnly)) {
            qWarning("Could not open file"); // Catch for bad filepath.
            return;
        }
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonFile.readAll());
        if (jsonDoc.isNull() || !jsonDoc.isObject()) {
            qWarning("Invalid JSON format"); // Catch for bad JSON.
            return;
        }
        loadedSprite = Sprite::loadFromJSON(jsonDoc.object());
        if (loadedSprite.getSize() == 0) {
            qWarning("Failed to load sprite from JSON."); // Catch for failed load.
            return;
        }
    }
    catch(...)
    {
        qWarning("Failed to load Json.");
        return;
    }
    qWarning("Loaded sprite");
    // TODO: Warn user if data if going to be overwriten.
    // delete this->sprite; // TODO: Do we need to delete the old sprite?
    this->sprite = loadedSprite;
    emit resetView();
    emit displayAnimation(sprite);
}


