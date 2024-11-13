#ifndef ANIMATIONBOX_H
#define ANIMATIONBOX_H

#include <QWidget>
#include <vector>
#include "Sprite.h"

using std::vector;

namespace Ui {
class AnimationBox;
}

class AnimationBox : public QWidget
{
    Q_OBJECT

public:
    explicit AnimationBox(QWidget *parent = nullptr);

    ~AnimationBox();

private:
    int fps;
    Ui::AnimationBox *ui;
    QTimer* frameTimer;
    Sprite* sprite;
    int currentFrameIndex;

    ///
    /// \brief paintEvent -
    /// \param event -
    ///
    void paintEvent(QPaintEvent *event) override;

public slots:
    void changeFPS(int newFps);
    void displayAnimation(Sprite& sprite);
};

#endif // ANIMATIONBOX_H
