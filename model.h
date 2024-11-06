#ifndef MODEL_H
#define MODEL_H

#include <QColor>
#include <QImage>
#include <QString>

class Model
{
public:
    Q_OBJECT

    int fps; // TODO: Should this be moved to the animmationBox?

    QColor penColor;

    Model();

    void loadJSON(QString source);

    void saveJSON(QString destinaton);

    void drawPixel(QImage& imageToUpdate, int x, int y);

    void erasePixel(QImage& imageToUpdate, int x, int y);

private:
    Sprite& sprite;


};

#endif // MODEL_H
