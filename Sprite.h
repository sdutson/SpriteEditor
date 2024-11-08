#ifndef SPRITE_H
#define SPRITE_H

#include <QString>
#include <QImage>

using std::vector;
using std::string;

class Sprite {


public:
    Sprite();

    ///
    /// \brief addFrame - adds an empty frame to the sprite.
    /// \return - A referance to the image that was added.
    ///
    QImage& addFrame();

    ///
    /// \brief deleteFrame - Deletes the frame at the given index.
    /// \param index - Index of the frame to delete.
    /// \return - The image to replace the deleted one.
    ///
    QImage& deleteFrame(int index);

    ///
    /// \brief getFrame - gets the frame at index.
    /// \param index - location of the frame to fetch.
    /// \return - the frame at the index in the sprite. nothing if no frame exists at index.
    ///
    QImage& getFrame(int index);

    ///
    /// \brief setName - sets the name of this sprite.
    /// \param name - sprite name.
    ///
    void setName(const string& name);

    ///
    /// \brief getName - gets the name of this sprite.
    /// \return - sprite name.
    ///
    string getName();

    ///
    /// \brief setDimensions
    /// \param dimensions
    ///
    void setDimensions(QPair<int, int> dimensions);

    ///
    /// \brief getDimensions - the dimensions of this sprite
    /// \return -
    ///
    QPair<int, int> getDimensions();

    ///
    /// \brief getSize - Returns the number of frames in the sprite.
    ///
    int getSize();


private:

    ///
    /// \brief dimensions -
    ///
    QPair<int, int> dimensions = {16, 16}; // TODO: Change this to whatever we want our default dimensions to be. Note. This will have to be able to be changed later on.

    vector<QImage> frames;

    QString name;

    int size = {0}; // The number of frames in the sprite.

};

#endif // SPRITE_H
