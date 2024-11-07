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
    ///
    void addFrame();

    ///
    /// \brief deleteFrame - deletes frame at index from sprite.
    /// \param index - index of frame to delete.
    ///
    void deleteFrame(int index);

    ///
    /// \brief getFrame - gets the frame at index.
    /// \param index - location of the frame to fetch.
    /// \return - the frame at the index in the sprite. nothing if no frame exists at index.
    ///
    QImage& getFrame(int index);

    ///
    /// \brief setName
    /// \param name
    ///
    void setName(const string& name);

    ///
    /// \brief getName
    /// \return
    ///
    string getName();

private:

    ///
    /// \brief dimensions
    ///
    QPair<int, int> dimensions = {16, 16}; // TODO: Change this to whatever we want our default dimensions to be. Note. This will have to be able to be changed later on.

    vector<QImage> frames;

    QString name;

};

#endif // SPRITE_H
