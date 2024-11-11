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
    emit spriteUpdated();
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
    Sprite loadedSprite = Sprite::loadFromJSON(jsonDoc.object());
    if (loadedSprite.getSize() == 0) {  // TODO: Add more checks here to ensure the sprite was built correctly.
        qWarning("Failed to load sprite from JSON."); // Catch for failed load.
        return;
    }
     // TODO: Warn user if data if going to be overwriten.
    // delete this->sprite; // TODO: Do we need to delete the old sprite?
    this->sprite = loadedSprite;
    emit resetView();
    emit displayAnimation(sprite);
}


