#ifndef PROG_SALLE_H
#define PROG_SALLE_H

#include <QDialog>
#include "program.h"
namespace Ui {
class prog_salle;
}

class prog_salle : public QDialog
{
    Q_OBJECT

public:
    explicit prog_salle(QWidget *parent = nullptr);
    ~prog_salle();
    void on_bp_ajout_2_clicked();

      void on_pushButton_4_clicked();

      void on_le_tri_2_clicked();

      void on_pdf_2_clicked();

      void on_modif_2_clicked();

      void on_le_id_supp_4_clicked();

      void on_historique_2_clicked();

      void on_chart_2_clicked();

      void on_supprimer_historique_2_clicked();

      void on_supprimer_tout_2_clicked();
      void mygame();

private:
    Ui::prog_salle *ui;
    Program ptmp;
       QTimer *timer,*timer2;
       history h;
};

#endif // PROG_SALLE_H
