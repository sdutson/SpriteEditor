#include "view.h"
#include "ui_view.h"
#include "model.h"

View::View(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
    model.addFrame();
    ui->canvas->switchImage(model.getFrame(0));
    connect(ui->canvas, &Canvas::changePixel, &model, &Model::changePixel);
}

View::~View()
{
    delete ui;
}
