#ifndef MODEL_H
#define MODEL_H

#include <QColor>
#include <QObject>
#include <QImage>
#include <QString>

class Model : public QObject
{

public:
    Q_OBJECT

    // int fps; // TODO: Should this be moved to the animmationBox?

    // QColor penColor;

    explicit Model(QObject *parent = nullptr);

    // void loadJSON(QString source);

    // void saveJSON(QString destinaton);

    // void drawPixel(QImage& imageToUpdate, int x, int y);

    // void erasePixel(QImage& imageToUpdate, int x, int y);

private:
    // Sprite& sprite;


};

#endif // MODEL_H
