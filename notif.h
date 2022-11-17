#ifndef NOTIF_H
#define NOTIF_H

#include <QDialog>

namespace Ui {
class notif;
}

class notif : public QDialog
{
    Q_OBJECT

public:
    explicit notif(QWidget *parent = nullptr);
    ~notif();

private:
    Ui::notif *ui;
};

#endif // NOTIF_H
