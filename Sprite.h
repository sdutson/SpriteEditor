#ifndef SPRITE_H
#define SPRITE_H

#include <QString>
#include <QImage>
#include <vector>

using std::vector;

class Sprite {


public:
    Sprite();

    void addFrame();

    void deleteFrame(QImage &frame);

    QString name;
private:

    int dimensions;

    vector<QImage> frames;

};

#endif // SPRITE_H
