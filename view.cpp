#include "view.h"
#include "ui_view.h"
#include "model.h"


#include <QLabel>
#include <QImage>


View::View(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
    , model(model)
{
    ui->setupUi(this);
    addFrame();

    // Set up scroll view.
    ui->frames->setWidgetResizable(true);
    QVBoxLayout layout(ui->scrollAreaWidgetContents);
    updateScrollView();

    connect(ui->canvas, &Canvas::changePixel, &model, &Model::changePixel);
    connect(ui->addFrameButton, &QPushButton::clicked, this, &View::addFrame);
    connect(ui->deleteFrameButton, &QPushButton::clicked, this, &View::deleteFrame);
    connect(&model, &Model::imageUpdated, this, &View::updateScrollView);
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
    ui->canvas->switchImage(model.addFrame(index));
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
    ui->canvas->switchImage(model.deleteFrame(index));
}

void View::updateScrollView()
{
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


}
