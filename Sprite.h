#ifndef SPRITE_H
#define SPRITE_H

#include <QString>
#include <QImage>

using std::vector;

class Sprite {


public:
    Sprite();

    void addFrame();

    void deleteFrame(QImage &frame);

    QImage& getFrame(int index);

    QString name;
private:

    int dimensions = {16}; // TODO: Change this to whatever we want our default dimensions to be. Note. This will have to be able to be changed later on.

    vector<QImage> frames;

};

#endif // SPRITE_H
