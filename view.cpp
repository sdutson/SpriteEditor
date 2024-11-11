#include "view.h"
#include "ui_animationbox.h"
#include "ui_view.h"
#include "model.h"
#include "animationbox.h"
#include <QLabel>
#include <QImage>
#include <QString>
#include <QDebug>
#include <QMessageBox>

View::View(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
    , model(model)
{
    ui->setupUi(this);
    addFrame();

    ui->colorDisplay->setStyleSheet("background-color: black;");

    layout = new QVBoxLayout(ui->scrollAreaWidgetContents);
    ui->scrollAreaWidgetContents->setLayout(layout);

    connect(ui->canvas, &Canvas::changePixel, &model, &Model::changePixel);
    connect(ui->penButton, &QPushButton::clicked, &model, &Model::setToolToPen);
    connect(ui->eraserButton, &QPushButton::clicked, &model, &Model::setToolToEraser);
    connect(ui->addFrameButton, &QPushButton::clicked, this, &View::addFrame);

    //TODO: Delete this message when done -
    //We need to make sure the commented out portion doesn't break any code,
    //It appears that this was part of what was breaking the scroll view.
    //I added the new connection so that add frame button updates the scroll view.
    connect(ui->addFrameButton, &QPushButton::clicked, this, &View::updateScrollView);
    //connect(&model, &Model::spriteUpdated, this, &View::updateScrollView);

    connect(ui->deleteFrameButton, &QPushButton::clicked, this, &View::deleteFrame);
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
}

void View::updateScrollView()
{
    if (currentFrameIndex < 0 || currentFrameIndex >= model.getSize()) {
        qWarning() << "Invalid currentFrameIndex:" << currentFrameIndex;
        return;
    }

    QImage canvasImage = model.getFrame(currentFrameIndex);
    if (canvasImage.isNull()) {
        qWarning() << "Canvas image is null!";
        return;
    }


    QLabel *imageLabel = new QLabel(ui->scrollAreaWidgetContents);
    imageLabel->setScaledContents(true);
    imageLabel->setFixedSize(100, 100);
    imageLabel->setStyleSheet("border: 1px solid red;");

    QPixmap pixmap = QPixmap::fromImage(canvasImage);
    imageLabel->setPixmap(pixmap);
    layout->addWidget(imageLabel);

    layout->update();
}

void View::showSaveFileDialog()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("save file"), "/Users",  tr("Json files (*.json)"));
    model.saveSprite(filePath);
}

void View::showLoadFileDialog()
{
    QMessageBox::warning(this, "Warning", "Loading in a new sprite will overwrite all unsaved data.", QMessageBox::Ok);
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open file"), "/Users", tr("All files (*.*)"));
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
    this->currentFrameIndex = 0;
    ui->canvas->switchImage(model.getFrame(this->currentFrameIndex));
    ui->spriteNameText->setPlainText(model.getName());
    updateScrollView();
}

void View::jumpToFrame()
{
    this->currentFrameIndex = ui->jumpToIndex->value();
    ui->canvas->switchImage(model.getFrame(this->currentFrameIndex));
}







