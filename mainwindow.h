#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "salles.h"
#include <QMainWindow>
#include<QSqlQuery>
#include<QSqlQueryModel>

#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>

#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>

#include <QTextStream>
#include <QFile>
#include <QDataStream>


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

    void sendMail();
    void mailSent(QString);
    void browse();

    void on_pushButtonajout_clicked();

    void on_pushButtonsupprimer_clicked();

    void on_pushButtonmodifier_clicked();

    void on_pushButton_chercher_clicked();

    void on_pushButton_tri_clicked();

    void on_pdf_clicked();

    void on_sendBtb_clicked();

    void on_camera_2_clicked();

private:
    Ui::MainWindow *ui;
    Salles S;
       QStringList files;
};
#endif // MAINWINDOW_H
