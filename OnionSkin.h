#ifndef ONIONSKIN_H
#define ONIONSKIN_H

#include <QWidget>

namespace Ui {
class OnionSkin;
}

class OnionSkin : public QWidget
{
    Q_OBJECT

public:
    explicit OnionSkin(QWidget *parent = nullptr);
    ~OnionSkin();

private:
    Ui::OnionSkin *ui;
};

#endif // ONIONSKIN_H
