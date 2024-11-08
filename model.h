#ifndef MODEL_H
#define MODEL_H

#include <QColor>
#include <QObject>
#include <QImage>
#include <QString>
#include "Sprite.h"

    class Model : public QObject
{
    Q_OBJECT

private:
    Sprite sprite;


public:

    // int fps; // TODO: Should this be moved to the animmationBox?

    int size = {0}; // The number of frames in the model's sprite.

    QColor penColor = {Qt::black};

    bool erasing = false; //TODO: change to enum

    explicit Model(QObject *parent = nullptr);

    // void loadJSON(QString source);

    // void saveJSON(QString destinaton);

    QImage& getFrame(int index);

    ///
    /// \brief addFrame - Adds a frame to the model.
    /// \return - A referance to the image that was added.
    ///
    QImage& addFrame();

    ///
    /// \brief deleteFrame - Deletes the last frame from the sprite.
    /// \return - The new last frame in the sprite(post deletion).
    ///
    QImage& deleteFrame();

public slots:
    void changePixel(QImage& imageToUpdate, int x, int y);

};

#endif // MODEL_H
