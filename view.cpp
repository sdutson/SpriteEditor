#include "view.h"
#include "ui_view.h"
#include "model.h"

View::View(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
    , model(model)
{
    ui->setupUi(this);
    addFrame();

    connect(ui->canvas, &Canvas::changePixel, &model, &Model::changePixel);
    connect(ui->addFrameButton, &QPushButton::clicked, this, &View::addFrame);
    connect(ui->deleteFrameButton, &QPushButton::clicked, this, &View::deleteFrame);
}

View::~View()
{
    delete ui;
}


void View::addFrame()
{
    ui->canvas->switchImage(model.addFrame());
}

void View::deleteFrame()
{
    if(model.getSize() <= 1) return;
    ui->canvas->switchImage(model.deleteFrame());
}
