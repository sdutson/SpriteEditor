#include "view.h"
#include "ui_animationbox.h"
#include "ui_view.h"
#include "model.h"
#include "animationbox.h"
#include <QLabel>
#include <QImage>
#include <QString>
#include <QDebug>

View::View(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
    , model(model)
{
    ui->setupUi(this);
    addFrame();

    ui->colorDisplay->setStyleSheet("background-color: black;");

    // Set up scroll view.
    ui->frames->setWidgetResizable(true);
    QVBoxLayout layout(ui->scrollAreaWidgetContents);
    updateScrollView();

    connect(ui->canvas, &Canvas::changePixel, &model, &Model::changePixel);
    connect(ui->penButton, &QPushButton::clicked, &model, &Model::setToolToPen);
    connect(ui->eraserButton, &QPushButton::clicked, &model, &Model::setToolToEraser);
    connect(ui->addFrameButton, &QPushButton::clicked, this, &View::addFrame);
    connect(ui->deleteFrameButton, &QPushButton::clicked, this, &View::deleteFrame);
    connect(&model, &Model::spriteUpdated, this, &View::updateScrollView);
    connect(ui->saveButton, &QPushButton::clicked, this, &View::showSaveFileDialog);
    connect(ui->loadButton, &QPushButton::clicked, this, &View::showLoadFileDialog);
    connect(ui->colorSelector, &QPushButton::clicked, this, &View::showColorDialog);
    connect(this, &View::setColor, &model, &Model::setColor);
    connect(&model, &Model::displayAnimation, ui->animationBox, &AnimationBox::displayAnimation);
    connect(ui->fpsSlider, &QSlider::valueChanged, ui->animationBox, &AnimationBox::changeFPS);
    connect(ui->fpsSlider, &QSlider::valueChanged, this, &View::updateFPS);
    connect(&model, &Model::resetView, this, &View::resetView);
    connect(ui->copyFrame, &QPushButton::clicked, this, &View::copyFrame);
    connect(ui->Dimension, &QSpinBox::valueChanged, this, &View::updateDimensions);
    connect(ui->jumpToFrame, &QPushButton::clicked, this, &View::jumpToFrame);
    connect(ui->updateName, &QPushButton::clicked, this, &View::setName);
    // TODO: Connect OnionSkin button to canvas, should not be linked through model as OnionSkin is a purely visual change.

    ui->fpsCounter->display(1);

    QPalette palette = ui->fpsCounter->palette();
    palette.setColor(QPalette::WindowText, QColor(172, 226, 252));  // Set the digit color
    ui->fpsCounter->setPalette(palette);
}

View::~View()
{
    delete ui;
}

void View::addFrame()
{
    int index = ui->spinBox->value();
    if(index > model.getSize())
    {
        index = model.getSize();
    }
    else if(index < 0)
    {
        index = 0;
    }
    this->currentFrameIndex = model.addFrame(index);
    ui->canvas->switchImage(model.getFrame(currentFrameIndex));
}

void View::deleteFrame()
{
    if(model.getSize() <= 1)
    {
        return;
    }
    int index = ui->deleteIndex->value();
    if(index > model.getSize() - 1)
    {
        index = model.getSize() - 1;
    }
    else if(index < 0)
    {
        index = 0;
    }
    this->currentFrameIndex = model.deleteFrame(index);
    ui->canvas->switchImage(model.getFrame(currentFrameIndex));
}

void View::copyFrame()
{
    this->currentFrameIndex = model.copyFrame(this->currentFrameIndex);
    ui->canvas->switchImage(model.getFrame(this->currentFrameIndex));
}

void View::updateDimensions()
{
    QPair<int, int> newDimensions(ui->Dimension->value(), ui->Dimension->value());
    model.setSpriteDimensions(newDimensions);
    ui->canvas->switchImage(model.getFrame(this->currentFrameIndex));
}

void View::updateFPS()
{
    int fpsInt = ui->fpsSlider->value();
    ui->fpsCounter->display(fpsInt);
    emit changeFPS(fpsInt);
}

void View::setName()
{
    model.setName(ui->spriteNameText->toPlainText().toStdString());
    ui->spriteNameText->clear();
}

void View::updateScrollView()
{
    // TODO: Rather than a scroll view, we could simply give the user an option to update the frame that is being displayed in the frame view.
    // Clear the existing widgets in the layout
    QLayoutItem *label;
    while ((label = layout.takeAt(0)) != nullptr) {
        delete label->widget();
        delete label;
    }

    // TODO: Try to find a way to not have to rebuilt this every time.
    for(int index = 0; index < model.getSize(); index++)
    {
        QLabel *imageLabel = new QLabel("No image loaded", ui->scrollAreaWidgetContents);
        imageLabel->setScaledContents(true);
        imageLabel->setFixedWidth(100);
        imageLabel->setFixedHeight(100); // TODO: Change these to update based on spries dimensions.

        QPixmap pixmap = QPixmap::fromImage(model.getFrame(index));
        imageLabel->setPixmap(pixmap);
        imageLabel->setText("");

        layout.addWidget(imageLabel);
    }
    layout.update();
}

void View::showSaveFileDialog()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("save file"), "/Users/samueldutson",  tr("JSON files(*.json")); // TODO: Make sure this is enforced.
    model.saveSprite(filePath);
}

void View::showLoadFileDialog()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open file"), "/Users/samueldutson", tr("All files (*.*)"));
    model.loadSprite(filePath);
}

void View::showColorDialog()
{
    QColor color = QColorDialog::getColor();
    ui->colorDisplay->setStyleSheet(QString("background-color: %1;").arg(color.name()));
    emit setColor(color);
}

void View::resetView()
{
    // TODO: Make sure everything gets reset correctly here.
    this->currentFrameIndex = 0;
    ui->canvas->switchImage(model.getFrame(this->currentFrameIndex));
    updateScrollView();
}

void View::jumpToFrame()
{
    this->currentFrameIndex = ui->jumpToIndex->value();
    ui->canvas->switchImage(model.getFrame(this->currentFrameIndex));
}







