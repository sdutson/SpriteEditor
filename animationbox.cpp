#include "animationbox.h"
#include "ui_animationbox.h"

AnimationBox::AnimationBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AnimationBox)
{
    ui->setupUi(this);
}

AnimationBox::~AnimationBox()
{
    delete ui;
}
