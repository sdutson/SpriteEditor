#ifndef TRANSPARENCYGRID_H
#define TRANSPARENCYGRID_H

#include <QWidget>

///
/// \brief transparencygrid.h - Header file for the transparencygrid class.
/// Review By: Will Jackson - u0710534
///

namespace Ui {
class TransparencyGrid;
}

class TransparencyGrid : public QWidget
{
    Q_OBJECT

public:
    ///
    /// \brief TransparencyGrid - Constructor for a transparencygrid.
    /// \param parent - Not used.
    ///
    explicit TransparencyGrid(QWidget *parent = nullptr);

    ///
    /// \brief ~TransparencyGrid - Destructor for a transparencygrid.
    ///
    ~TransparencyGrid();

    ///
    /// \brief setImageSize - Sets the image size to use when drawing the transparencygrid.
    /// \param width - Width of the current image.
    /// \param height - Height of the current image.
    ///
    void setImageSize(int width, int height);

private:
    int imageWidth;
    int imageHeight;
    Ui::TransparencyGrid *ui;

    ///
    /// \brief paintEvent - Redraws the screen.
    /// \param event - Not used.
    ///
    void paintEvent(QPaintEvent *event) override;

    ///
    /// \brief drawTransparencyGrid - Draws the squares that make up the transparency grid.
    ///
    void drawTransparencyGrid();
};

#endif // TRANSPARENCYGRID_H
