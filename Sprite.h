#ifndef SPRITE_H
#define SPRITE_H

#include <QString>
#include <QImage>
#include <QJsonObject>

using std::vector;
using std::string;

///
/// \brief The Sprite class - Header file for the Sprtie class.
/// Reviewed By: Sam Dutson - u1406827
///
class Sprite {

public:
    ///
    /// \brief Sprite - Constructor for a new sprite.
    ///
    Sprite();

    ///
    /// \brief addFrame - Adds an empty image at the desired index.
    /// \return - The index of the frame that was added.
    ///
   int addFrame(int index);

    ///
    /// \brief deleteFrame - Deletes the frame at the given index.
    /// \param index - Index of the frame to delete.
    /// \return - The index of the new 'current' frame.
    ///
    int deleteFrame(int index);

    ///
    /// \brief getFrame - gets the frame at index.
    /// \param index - location of the frame to fetch.
    /// \return - the frame at the index in the sprite. nothing if no frame exists at index.
    ///
    QImage& getFrame(int index);

    ///
    /// \brief copyFrame - Adds a copy of the given frame to frames.
    /// \param frame - The index of the frame to copy.
    /// \return - The index of the frame that was added.
    ///
    int copyFrame(int index);

    ///
    /// \brief setName - sets the name of this sprite.
    /// \param name - sprite name.
    ///
    void setName(const string& name);

    ///
    /// \brief getName - gets the name of this sprite.
    /// \return - sprite name.
    ///
    QString getName();

    ///
    /// \brief setDimensions - Updates the dimensions of the sprite.
    /// \param dimensions - The new dimensions
    ///
    void setDimensions(QPair<int, int> dimensions);

    ///
    /// \brief getSize - Returns the number of frames in the sprite.
    ///
    int getSize();

    ///
    /// \brief saveJSON - Serializes 'this' into a QJsonObject.
    /// \return - A QJsonObject holding all needed data to reproduce 'this' sprite.
    ///
    QJsonObject saveJSON();

    ///
    /// \brief loadFromJSON - Creates a sprite from the given QJsonObject. If the given ojbect is invalid, method returns a nullptr.
    /// \return - A sprite object constructed from spriteJson.
    /// \param spriteJson - The object to be deserialized.
    ///
    static Sprite loadFromJSON(QJsonObject spriteJson);

private:
    QPair<int, int> dimensions = {16, 16};

    vector<QImage> frames;

    QString name;

    int size = {0};

};

#endif // SPRITE_H
