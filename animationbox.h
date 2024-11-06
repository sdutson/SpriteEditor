#ifndef ANIMATIONBOX_H
#define ANIMATIONBOX_H

#include <QWidget>

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
    Ui::AnimationBox *ui;
};

#endif // ANIMATIONBOX_H
