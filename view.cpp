#include "view.h"
#include "ui_view.h"
#include "model.h"
#include "animationbox.h"
#include <QLabel>
#include <QImage>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <iostream>

View::View(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
    , model(model)
{
    ui->setupUi(this);
    addFrame();
    ui->transparencyGrid->setImageSize(model.getFrame(currentFrameIndex).width(), model.getFrame(currentFrameIndex).height());

    ui->colorDisplay->setStyleSheet("background-color: black;");

    layout = new QVBoxLayout(ui->scrollAreaWidgetContents);
    ui->scrollAreaWidgetContents->setLayout(layout);

    connect(ui->canvas, &Canvas::changePixel, &model, &Model::changePixel);
    connect(ui->penButton, &QPushButton::clicked, &model, &Model::setToolToPen);
    connect(ui->eraserButton, &QPushButton::clicked, &model, &Model::setToolToEraser);
    connect(ui->addFrameButton, &QPushButton::clicked, this, &View::addFrame);
    connect(ui->addFrameButton, &QPushButton::clicked, this, &View::updateScrollView);
    connect(ui->canvas, &Canvas::changePixel, this, &View::updateScrollView);
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
    updateScrollView();
}

void View::copyFrame()
{
    this->currentFrameIndex = model.copyFrame(this->currentFrameIndex);
    ui->canvas->switchImage(model.getFrame(this->currentFrameIndex));
    updateScrollView();
}

void View::updateDimensions()
{
    QPair<int, int> newDimensions(ui->Dimension->value(), ui->Dimension->value());
    model.setSpriteDimensions(newDimensions);
    ui->canvas->switchImage(model.getFrame(this->currentFrameIndex));
    ui->transparencyGrid->setImageSize(model.getFrame(this->currentFrameIndex).width(), model.getFrame(this->currentFrameIndex).height());
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
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    for (int i = 0; i < model.getSize(); ++i) {
        QImage canvasImage = model.getFrame(i);
        if (canvasImage.isNull()) {
            qWarning() << "Canvas image is null for frame: " << i;
            continue;
        }

        QLabel *imageLabel = new QLabel(ui->scrollAreaWidgetContents);
        imageLabel->setScaledContents(true);
        imageLabel->setStyleSheet("border: 1px solid rgb(225, 245, 247);"); // Adjusts the border window color.
        QPixmap pixmap = QPixmap::fromImage(canvasImage.scaled(size(), Qt::KeepAspectRatio));
        if (pixmap.isNull()) {
            qWarning() << "Failed to convert QImage to QPixmap for frame: " << i;
            continue;
        }

        imageLabel->setPixmap(pixmap);
        imageLabel->setFixedSize(80, 80); // Set label size such that it fits neatly in the scorll view.
        layout->addWidget(imageLabel);
    }
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







