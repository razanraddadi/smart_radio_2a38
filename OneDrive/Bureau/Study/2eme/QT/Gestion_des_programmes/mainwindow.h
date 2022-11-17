#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "program.h"
#include <QTimer>
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
    void on_bp_ajout_clicked();



    void on_le_id_supp_2_clicked();



    void on_pushButton_2_clicked();

    void on_le_tri_clicked();

    void on_pdf_clicked();
    void mygame();
    void mygame2();


    void on_historique_clicked();


    void on_modif_clicked();

    void on_chart_clicked();

    void on_pushButton_clicked();

    void on_supprimer_tout_clicked();

    void on_supprimer_historique_clicked();

private:
    Ui::MainWindow *ui;
    Program ptmp;
    QTimer *timer,*timer2;
    history h;
};
#endif // MAINWINDOW_H
