#ifndef MODEL_H
#define MODEL_H

#include <QColor>
#include <QObject>
#include <QImage>
#include <QString>

    class Model : public QObject
{
    Q_OBJECT

private:
    // Sprite& sprite;

    const int COMPUTER_TURN_LENGTH = 1000; // Constant used to ensure computer moves speed up at game progresses.

public:

    // int fps; // TODO: Should this be moved to the animmationBox?

    // QColor penColor;

    explicit Model(QObject *parent = nullptr);

    // void loadJSON(QString source);

    // void saveJSON(QString destinaton);

    // void drawPixel(QImage& imageToUpdate, int x, int y);

    // void erasePixel(QImage& imageToUpdate, int x, int y);

};

#endif // MODEL_H
