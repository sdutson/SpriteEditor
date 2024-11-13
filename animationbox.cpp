#include "animationbox.h"
#include "ui_animationbox.h"
#include <QTimer>
#include <QImage>
#include <QPainter>

///
/// \brief AnimationBox - Stores the information to implement the Animation box and fps slider.
/// Review By: David Nixon - U1115706
///

AnimationBox::AnimationBox(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::AnimationBox),
    frameTimer(new QTimer(this)),
    sprite(nullptr)
{
    ui->setupUi(this);
    connect(frameTimer, &QTimer::timeout, this, QOverload<>::of(&AnimationBox::update));
    fps = 1;
}

AnimationBox::~AnimationBox()
{
    delete ui;
}

void AnimationBox::displayAnimation(Sprite& sprite)
{
    this->sprite = &sprite;
    currentFrameIndex = 0;
    const double ONE_SECOND_IN_MILLISECONDS = 1'000.0; // Double literal to prevent truncation from integer division.
    if(fps>0){
        frameTimer->start(ONE_SECOND_IN_MILLISECONDS / fps);
    }
    else{
        frameTimer->stop();
    }
}

void AnimationBox::paintEvent(QPaintEvent *event)
{
    if (!sprite)
    {
        return;
    }
    QPainter painter(this);
    QImage scaledImage = sprite->getFrame(currentFrameIndex).scaled(size(), Qt::KeepAspectRatio);
    painter.drawImage(0, 0, scaledImage);
    if (currentFrameIndex == sprite->getSize() - 1)
    {
        currentFrameIndex = 0;
    }
    else
    {
        currentFrameIndex++;
    }
}

void AnimationBox::changeFPS(int newFPS)
{
    fps = newFPS;
    // Update the animation fps if a sprite is loaded
    if (sprite) {
        displayAnimation(*sprite);
    }
}

