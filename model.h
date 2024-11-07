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

    QColor penColor = Qt::black;
    bool erasing = false; //TODO: change to enum

    explicit Model(QObject *parent = nullptr);

    // void loadJSON(QString source);

    // void saveJSON(QString destinaton);

    QImage& getFrame(int index);

    void addFrame();

public slots:
    void changePixel(QImage& imageToUpdate, int x, int y);

};

#endif // MODEL_H
