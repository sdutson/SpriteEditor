#ifndef MODEL_H
#define MODEL_H

#include <QColor>
#include <QObject>
#include <QImage>
#include <QString>
#include <QPair>
#include "Sprite.h"

///
/// \brief The Model class - Header file for the model class.
/// Reviewed By: Sam Dutson - u1406827
///
    class Model : public QObject
{
    Q_OBJECT

private:
    Sprite sprite;

public:

    QColor penColor = {Qt::black};

    bool erasing = false;

    ///
    /// \brief Model - Constructor for a model.
    /// \param parent - Not used.
    ///
    explicit Model(QObject *parent = nullptr);

    ///
    /// \brief setSpriteDimensions - Sets/Updates the dimensions of 'sprite'
    /// \param newDimensions - The new dimensions for the sprite.
    ///
    void setSpriteDimensions(QPair<int, int> newDimensions);

    ///
    /// \brief getFrame - Gets the frame at the desired index.
    /// \return  - A reference to the image that was queried.
    ///
    QImage& getFrame(int index);

    ///
    /// \brief addFrame - Adds a frame to the model at the desired index.
    /// \return - The index of the image that was added.
    ///
    int addFrame(int index);

    ///
    /// \brief deleteFrame - Deletes the frame at the current index from the sprite.
    /// \return - The index of the image that was added.
    ///
    int deleteFrame(int index);

    ///
    /// \brief copyFrame - Copies the given frame.
    /// \param frame - The index of the frame to be copied.
    /// \return - The index of the frame that was added.
    ///
    int copyFrame(int index);

    ///
    /// \brief getSize - Returns the number of frames in the model's sprite.
    ///
    int getSize();

    ///
    /// \brief saveSprite - Saves a serialized version of 'sprite' to the json file located at 'filepath'.
    /// \param filepath - The location to save to.
    ///
    void saveSprite(QString filepath);

    ///
    /// \brief loadSprite - Loads the .json file located at 'filepath' and has a new Sprite object created.
    /// Informs view up 'reset' state.
    /// \param filepath - The location to load from.
    ///
    void loadSprite(QString filepath);

    ///
    /// \brief setName - Updates the name of the sprite.
    /// \param newName - The new name for the sprite.
    ///
    void setName(const string & newName);

    ///
    /// \return - The name of 'sprite'
    ///
    QString getName();

public slots:
    ///
    /// \brief changePixel - Updates the desired pixel in the given image. Either erases or draws(determined by the state of the 'erasing' var).
    /// \param imageToUpdate - The image to update.
    /// \param x - The x coordinate of the pixel to edit.
    /// \param y - The y coordinate of the pixel to edit.
    ///
    void changePixel(QImage& imageToUpdate, int x, int y);

    ///
    /// \brief setToolToPen - Sets the drawing tool to a pen.
    ///
    void setToolToPen();

    ///
    /// \brief setToolToEraser - Sets the drawing tool to an eraser.
    ///
    void setToolToEraser();

    ///
    /// \brief setColor - Sets the penColr for the model.
    /// \param color - The color to set the pen to.
    ///
    void setColor(QColor color);

signals:
    ///
    /// \brief displayAnimation - Informs the view to display an animation.
    /// \param sprite - The sprite who's animation is to be displayed.
    ///
    void displayAnimation(Sprite& sprite);

    ///
    /// \brief resetView - Resets the view to the contents of a new sprite(Emmited after user loads in a new sprite.).
    ///
    void resetView();
};

#endif // MODEL_H
