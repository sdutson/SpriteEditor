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
    QVBoxLayout layout;

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
    /// \brief updateScrollView - Updates the contents of the scroll view.
    ///
    void updateScrollView();

    ///
    /// \brief showSaveFileDialog - Displays a file dialog to get the desired save location from the user.
    ///
    void showSaveFileDialog();

    ///
    /// \brief showLoadFileDialog - Displays a file dialog to get the desired load location from the user.
    ///
    void showLoadFileDialog();

    void showColorDialog();

signals:
    void setColor(QColor color);
};
#endif // VIEW_H
