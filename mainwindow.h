#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "partenariats.h"
#include <QSqlQuery>
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
    void on_bouton_ajouter_clicked();
    void on_bouton_supprimer_clicked();
    void on_bouton_modifier_clicked();
    void on_bouton_tri_clicked();
    void on_bouton_chercher_clicked();

private:
    Ui::MainWindow *ui;
     Partenariats p;
};
#endif // MAINWINDOW_H
