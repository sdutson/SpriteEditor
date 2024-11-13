#ifndef ANIMATIONBOX_H
#define ANIMATIONBOX_H

#include <QWidget>
#include <vector>
#include "Sprite.h"

///
/// \brief AnimationBox.h - Declares the info and methods nessesary for the animation box and fps slider.
/// Review By: David Nixon - U1117506
///

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
    /// \brief paintEvent - Method for drawing the frame on the animation box window.
    /// \param event - Unused.
    ///
    void paintEvent(QPaintEvent *event) override;

public slots:

    ///
    /// \brief changeFPS - Slot from view to take data from slider.
    /// \param newFps - Temporary variable of the fps from the slider.
    ///
    void changeFPS(int newFps);

    ///
    /// \brief displayAnimation - Slot from the model to trigger a display in the animation box.
    /// \param sprite - The sprite and its information to be used.
    ///
    void displayAnimation(Sprite& sprite);

};

#endif // ANIMATIONBOX_H
