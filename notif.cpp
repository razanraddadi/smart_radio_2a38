#include "notif.h"
#include "ui_notif.h"

notif::notif(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::notif)
{
    ui->setupUi(this);
}

notif::~notif()
{
    delete ui;
}
