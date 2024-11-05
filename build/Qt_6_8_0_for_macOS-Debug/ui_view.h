/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "canvas.h"

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QWidget *centralwidget;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QLabel *spriteName;
    Canvas *canvas;
    QWidget *animationBox;
    QScrollArea *frames;
    QWidget *scrollAreaWidgetContents;
    QPushButton *addFrameButton;
    QPushButton *deleteFrameButton;
    QSlider *fpsSlider;
    QLabel *dimensionLabel;
    QSpinBox *xDimension;
    QSpinBox *yDimension;
    QPushButton *penButton;
    QPushButton *eraserButton;
    QPushButton *colorSelector;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName("View");
        View->resize(800, 600);
        centralwidget = new QWidget(View);
        centralwidget->setObjectName("centralwidget");
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(10, 20, 100, 32));
        loadButton = new QPushButton(centralwidget);
        loadButton->setObjectName("loadButton");
        loadButton->setGeometry(QRect(10, 50, 100, 32));
        spriteName = new QLabel(centralwidget);
        spriteName->setObjectName("spriteName");
        spriteName->setGeometry(QRect(330, 20, 60, 20));
        canvas = new Canvas(centralwidget);
        canvas->setObjectName("canvas");
        canvas->setGeometry(QRect(190, 50, 350, 350));
        animationBox = new QWidget(centralwidget);
        animationBox->setObjectName("animationBox");
        animationBox->setGeometry(QRect(600, 10, 125, 125));
        frames = new QScrollArea(centralwidget);
        frames->setObjectName("frames");
        frames->setGeometry(QRect(600, 200, 125, 250));
        frames->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 123, 248));
        frames->setWidget(scrollAreaWidgetContents);
        addFrameButton = new QPushButton(centralwidget);
        addFrameButton->setObjectName("addFrameButton");
        addFrameButton->setGeometry(QRect(600, 450, 60, 30));
        deleteFrameButton = new QPushButton(centralwidget);
        deleteFrameButton->setObjectName("deleteFrameButton");
        deleteFrameButton->setGeometry(QRect(665, 450, 60, 30));
        fpsSlider = new QSlider(centralwidget);
        fpsSlider->setObjectName("fpsSlider");
        fpsSlider->setGeometry(QRect(575, 150, 175, 25));
        fpsSlider->setMaximum(30);
        fpsSlider->setOrientation(Qt::Orientation::Horizontal);
        dimensionLabel = new QLabel(centralwidget);
        dimensionLabel->setObjectName("dimensionLabel");
        dimensionLabel->setGeometry(QRect(190, 420, 210, 30));
        xDimension = new QSpinBox(centralwidget);
        xDimension->setObjectName("xDimension");
        xDimension->setGeometry(QRect(400, 420, 42, 30));
        yDimension = new QSpinBox(centralwidget);
        yDimension->setObjectName("yDimension");
        yDimension->setGeometry(QRect(450, 420, 42, 30));
        penButton = new QPushButton(centralwidget);
        penButton->setObjectName("penButton");
        penButton->setGeometry(QRect(10, 160, 50, 32));
        eraserButton = new QPushButton(centralwidget);
        eraserButton->setObjectName("eraserButton");
        eraserButton->setGeometry(QRect(80, 160, 50, 32));
        colorSelector = new QPushButton(centralwidget);
        colorSelector->setObjectName("colorSelector");
        colorSelector->setGeometry(QRect(10, 280, 100, 100));
        View->setCentralWidget(centralwidget);
        menubar = new QMenuBar(View);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 36));
        View->setMenuBar(menubar);
        statusbar = new QStatusBar(View);
        statusbar->setObjectName("statusbar");
        View->setStatusBar(statusbar);

        retranslateUi(View);

        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View)
    {
        View->setWindowTitle(QCoreApplication::translate("View", "View", nullptr));
        saveButton->setText(QCoreApplication::translate("View", "Save Sprite", nullptr));
        loadButton->setText(QCoreApplication::translate("View", "Load Sprite", nullptr));
        spriteName->setText(QCoreApplication::translate("View", "Unnamed", nullptr));
        addFrameButton->setText(QCoreApplication::translate("View", "Add", nullptr));
        deleteFrameButton->setText(QCoreApplication::translate("View", "Delete", nullptr));
        dimensionLabel->setText(QCoreApplication::translate("View", "Sprite Dimensions(Width,  Height) ", nullptr));
        penButton->setText(QCoreApplication::translate("View", "Pen", nullptr));
        eraserButton->setText(QCoreApplication::translate("View", "Eraser", nullptr));
        colorSelector->setText(QCoreApplication::translate("View", "Color Selector", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
