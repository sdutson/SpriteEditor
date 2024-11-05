#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QImage>

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

    QImage& image;
    bool scribbling;

public:
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas();

private:
    Ui::Canvas *ui;

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // CANVAS_H
