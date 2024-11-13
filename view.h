#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include "model.h"
#include <QFileDialog>
#include <QColorDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

///
/// \brief The View class - Represents the view of the SpriteEditor.
///
class View : public QMainWindow
{
    Q_OBJECT

public:
    View(Model& model, QWidget *parent = nullptr);
    ~View();

private:
    Ui::View *ui;
    QWidget *imageContainer;
    QVBoxLayout *scrollViewLayout;
    Model& model;
    QVBoxLayout *layout;
    int currentFrameIndex;

private slots:
    ///
    /// \brief addFrame - Slot for when the user pressed the addFrameButton in the ui.
    /// This slot adds a empty frame to the end of the sprite's frames. Also sets the content of the canvas to the new frame.
    ///
    void addFrame();

    ///
    /// \brief deleteFrame - Slot for when the user pressed the deleteFrameButton in the ui.
    /// This slot deletes the last frame from the sprite. The canvas is then updated appropriatly.
    ///
    void deleteFrame();

    ///
    /// \brief copyFrame - Makes a copy of the current frame.
    ///
    void copyFrame();

    ///
    /// \brief updateScrollView - Updates the contents of the scroll view.
    ///
    void updateScrollView();

    ///
    /// \brief updateFPS - Updates the fps of the animation box when the user uses the slider.
    ///
    void updateFPS();

    ///
    /// \brief showSaveFileDialog - Displays a file dialog to get the desired save location from the user.
    ///
    void showSaveFileDialog();

    ///
    /// \brief showLoadFileDialog - Displays a file dialog to get the desired load location from the user.
    ///
    void showLoadFileDialog();


    ///
    /// \brief showColorDialog - Sends signal to prompt user with color picker.
    ///
    void showColorDialog();

    ///
    /// \brief resetView - Resets the view. Called when the user loads in a new sprite.
    ///
    void resetView();

    ///
    /// \brief updateDimensions - Updates the dimensions of the current sprite.
    ///
    void updateDimensions();

    ///
    /// \brief jumpToFrame - Jumps to(Updates canvas) to the frame desired by the user.
    ///
    void jumpToFrame();

    ///
    /// \brief setName - Updates the name of the sprite.
    ///
    void setName();

signals:
    ///
    /// \brief changeFPS - Signal to change fps.
    /// \param newFps - New fps value.
    ///
    void changeFPS(int newFps);

    ///
    /// \brief setColor - Signal to set color.
    /// \param color - New color to set it to.
    ///
    void setColor(QColor color);

};

#endif // VIEW_H
