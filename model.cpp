#include "model.h"
#include "Sprite.h"
#include <QImage>
#include <QColor>
#include <QString>


Model::Model(QObject *parent) : QObject(parent)
{
    Sprite sprite;
}

void Model::changePixel(QImage& imageToUpdate, int x, int y)
{
    if (erasing)
    {
        imageToUpdate.setPixelColor(x, y, Qt::white);
    }
    else
    {
        imageToUpdate.setPixelColor(x, y, penColor);
    }
    emit spriteUpdated();
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
    // TODO: Get the needed QJsonObject from the Sprite and write it to filepath.
}

void Model::loadSprite(QString filepath)
{
    // TODO: Load in the QJsonObject(If inproperly formatted, simply return.)
    // TODO: call loadFromJson() and reassign the output to 'sprite'. (If null don't reassign and simply return.)
    // TODO: Inform the view it needs to updated and DELETE all data from previous sprite.
    // TODO: Should we warn the user if they are going to overwrite data?

}
