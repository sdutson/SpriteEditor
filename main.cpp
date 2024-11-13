#include "view.h"
#include "model.h"
#include <QApplication>

///
/// Assign 08: Sprite Editor
///

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model model;
    View w(model);
    w.show();
    return a.exec();
}
