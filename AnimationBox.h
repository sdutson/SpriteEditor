#ifndef ANIMATIONBOX_H
#define ANIMATIONBOX_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QSize>

namespace Ui {
class AnimationBox;
}

class AnimationBox : public QWidget
{
    Q_OBJECT

    QImage image; // TODO: Set this back to referance.


    bool scribbling;

public:

    explicit AnimationBox(QWidget *parent = nullptr);

    ~AnimationBox();

private:
    Ui::AnimationBox *ui;
};

#endif // ANIMATIONBOX_H
