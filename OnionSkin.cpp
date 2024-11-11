#include "OnionSkin.h"
#include "ui_onionskin.h"

OnionSkin::OnionSkin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OnionSkin)
{
    ui->setupUi(this);
}

OnionSkin::~OnionSkin()
{
    delete ui;
}
