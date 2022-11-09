#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "salles.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:



    void on_pushButtonajout_clicked();

    void on_pushButtonsupprimer_clicked();

    void on_pushButtonmodifier_clicked();

private:
    Ui::MainWindow *ui;
    Salles S;
};
#endif // MAINWINDOW_H
