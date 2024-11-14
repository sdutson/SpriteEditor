#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QImage>

///
/// \brief canvas.h - Header file for the canvas class.
/// Review By: Will Jackson - u0710534
///

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:

    ///
    /// \brief Canvas - Constructor for a canvas.
    /// \param parent - Not used.
    ///
    explicit Canvas(QWidget *parent = nullptr);

    ///
    /// \brief ~Canvas - Destructor for a canvas.
    ///
    ~Canvas();

    ///
    /// \brief switchImage - switch the current selected images to new ones.
    /// \param newImage - the new currently displayed image.
    /// \param newPrevImage - the new previously displayed image.
    /// \param newNextImage - the new next displayed image.
    ///
    void switchImage(QImage& newImage, QImage& newPrevImage, QImage& newNextImage);

private:
    QImage* image;
    QImage* prevImage;
    QImage* nextImage;
    bool onionSkinToggled = false;
    Ui::Canvas *ui;

    ///
    /// \brief paintEvent - redraws the screen.
    /// \param event - unused.
    ///
    void paintEvent(QPaintEvent *event) override;

    ///
    /// \brief renderImage - displays the image onto the canvas.
    /// \param painter - the painter object used to draw to the canvas.
    /// \param image - the image to draw onto the canvas.
    /// \param opacity - 0 is fully transparent, 1 is fully opaque.
    ///
    void renderImage(QPainter& painter, QImage* image, const double opacity);

protected:
    ///
    /// \brief mousePressEvent - override that emits changePixel signal to model
    /// \param event - mouse event trigger that is used for the location of the cursor during event
    ///
    void mousePressEvent(QMouseEvent *event) override;

    ///
    /// \brief mousePressEvent - override that emits changePixel signal to model
    /// \param event - mouse event trigger that is used for the location of the cursor during event
    ///
    void mouseMoveEvent(QMouseEvent *event) override;

public slots:
    ///
    /// \brief toggleOnionSkin - toggles the onion skin feature on/off.
    ///
    void toggleOnionSkin();

signals:
    ///
    /// \brief changePixel - signal to modify pixel.
    /// \param imageToUpdate - the image that should have pixels modified.
    /// \param x - the x coordinate of the pixel.
    /// \param y - the y coordinate of the pixel.
    ///
    void changePixel(QImage& imageToUpdate, int x, int y);

};

#endif // CANVAS_H
