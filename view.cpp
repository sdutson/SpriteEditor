#include "view.h"
#include "ui_view.h"
#include "model.h"

View::View(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
    model.addFrame();
    // TODO: Set starting frame of canvas to the image just added to the model. Will just be an empty image.
    ui->canvas->switchImage(model.getFrame(0));
    connect(ui->canvas, &Canvas::changePixel, &model, &Model::changePixel);
}

View::~View()
{
    delete ui;
}
