#include "animationbox.h"
#include "ui_animationbox.h"
#include <QTimer>
#include <QImage>
#include <QPainter>
#include <iostream>

AnimationBox::AnimationBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AnimationBox)
    , frameTimer(new QTimer(this))
{
    ui->setupUi(this);

    connect(frameTimer, &QTimer::timeout, this, QOverload<>::of(&AnimationBox::update));
    std::cout << "In AnimationBox constructor" << std::endl; // TODO: Remove me

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
    frameTimer->start(ONE_SECOND_IN_MILLISECONDS / fps);
}

void AnimationBox::paintEvent(QPaintEvent *event)
{
    std::cout << "In AnimationBox paintEvent" << std::endl; // TODO: Remove me

    if (!sprite)
    {
        // Hardcoded default frame for when program starts, needs to be kept in sync with canvas.
        QPainter painter(this);
        painter.setBrush(Qt::lightGray);
        painter.setPen(Qt::NoPen);
        painter.drawRect(0, 0, width(), height());
        return;
    }

    QPainter painter(this);
    QImage scaledImage = sprite->getFrame(currentFrameIndex).scaled(size(), Qt::KeepAspectRatio);
    painter.setBrush(Qt::lightGray);
    painter.setPen(Qt::NoPen);
    painter.drawRect(0, 0, width(), height());
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
    std::cout << fps << std::endl;

}

