#ifndef TRANSPARENCYGRID_H
#define TRANSPARENCYGRID_H

#include <QWidget>

namespace Ui {
class TransparencyGrid;
}

class TransparencyGrid : public QWidget
{
    Q_OBJECT

public:
    explicit TransparencyGrid(QWidget *parent = nullptr);
    ~TransparencyGrid();
    void setImageSize(int width, int height);

private:
    int imageWidth;
    int imageHeight;

    Ui::TransparencyGrid *ui;
    void paintEvent(QPaintEvent *event) override;
    void drawTransparencyGrid();
};

#endif // TRANSPARENCYGRID_H
