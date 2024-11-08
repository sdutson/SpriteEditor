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

    QColor penColor = {Qt::black};

    bool erasing = false; //TODO: change to enum

    explicit Model(QObject *parent = nullptr);

    // void loadJSON(QString source);

    // void saveJSON(QString destinaton);

    QImage& getFrame(int index);

    ///
    /// \brief addFrame - Adds a frame to the model at the desired index.
    /// \return - A referance to the image that was added.
    ///
    QImage& addFrame(int index);

    ///
    /// \brief deleteFrame - Deletes the frame at the current index from the sprite.
    /// \return - The frame to replace the deleted one.
    ///
    QImage& deleteFrame(int index);

    ///
    /// \brief getSize - Returns the number of frames in the model's sprite.
    ///
    int getSize();


public slots:
    void changePixel(QImage& imageToUpdate, int x, int y);

signals:
    void imageUpdated();
};

#endif // MODEL_H
