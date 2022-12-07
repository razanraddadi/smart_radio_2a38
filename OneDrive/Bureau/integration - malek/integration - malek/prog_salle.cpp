#include "prog_salle.h"
#include "ui_prog_salle.h"
#include "program.h"

prog_salle::prog_salle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::prog_salle)
{
    ui->setupUi(this);
    ui->tableView_7->setModel(ptmp.afficher());
     timer = new QTimer(this);
     connect (timer,SIGNAL(timeout()),this,SLOT(mygame()) );
    timer->start(1000);
    timer2 = new QTimer(this);
    connect (timer2,SIGNAL(timeout()),this,SLOT(mygame2()) );
    timer2->start(10000);
}

prog_salle::~prog_salle()
{
    delete ui;
}
void programme_salle::on_bp_ajout_2_clicked()
{
    int id_p =ui->le_id_p->text().toInt();
    QString nom_p=ui->le_nom_p->text();
    QString acteur=ui->le_anim_2->text();
    int id_s=ui->le_ids_2->text().toInt();
     int jj=ui->jj_2->text().toInt();
      int mm=ui->mm_2->text().toInt();
       int yyyy=ui->yyyy_2->text().toInt();
        int heure=ui->hh_2->text().toInt();
         int min=ui->min_2->text().toInt();
         int viwes=ui->leviwes_2->text().toInt();
    Program P(id_p,id_s,nom_p,acteur,jj,mm,yyyy,heure,min,viwes);
    bool test=P.ajouter();
    bool nid=P.getid_p();
    bool nids=P.getid_s();

     ui->tableView_7->setModel(ptmp.afficher());
     if (!nid){test=false;
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("inserer id  \n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);}
    if (!nids){test=false;
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("inserer id salle \n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);}
    if (nom_p==""){test=false;
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("inserer nom du proramme \n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);}

    if (acteur==""){test=false;
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("inserer nom d'acteur\n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);}
    if(test)
    {
       QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout validé\n"
                                                                               "Click Cancel to exit"),QMessageBox::Cancel);}
            else

        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("ajout non validé\n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);}


void programme_salle::on_pushButton_4_clicked()
{
    {

        QString rech=ui->le_rech_2->text();

if(rech=="")
{
      QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("inserer le nom\n"
                                                                          "Click Cancel to exit"),QMessageBox::Cancel);
}
else
         ui->tableView_8->setModel(ptmp.afficher_recherche(rech));

    }
}

void programme_salle::on_le_tri_2_clicked()
{
    ui->tableView_9->setModel(ptmp.afficher_tri());

}

void programme_salle::on_pdf_2_clicked()
{
    {

        QString strStream;
                    QTextStream out(&strStream);
                    const int rowCount = ui->tableView_7->model()->rowCount();
                    const int columnCount =ui->tableView_7->model()->columnCount();


                    out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("programme")
                            <<  "</head>\n"
                            "<body bgcolor=#FFFFFF link=#5000A0>\n"
                                "<h1>Liste des Programmes</h1>"

                                "<table border=1 cellspacing=0 cellpadding=2>\n";

                    // headers
                        out << "<thead><tr bgcolor=#f0f0f0>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tableView_7->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tableView_7->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";
                        // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->tableView_7->isColumnHidden(column)) {
                                       QString data = ui->tableView_7->model()->data(ui->tableView_7->model()->index(row, column)).toString().simplified();
                                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                   }
                               }
                               out << "</tr>\n";
                           }
                           out <<  "</table>\n"
                               "</body>\n"
                               "</html>\n";



            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);


            //QTextDocument document;
            //document.setHtml(html);
            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("program.pdf");
            document->print(&printer);
}
}


void programme_salle::on_modif_2_clicked()
{
    int id_p =ui->le_id_p->text().toInt();
    QString nom_p=ui->le_nom_p->text();
    QString acteur=ui->le_anim_2->text();
    int id_s=ui->le_ids_2->text().toInt();
     int jj=ui->jj_2->text().toInt();
      int mm=ui->mm_2->text().toInt();
       int yyyy=ui->yyyy_2->text().toInt();
        int heure=ui->hh_2->text().toInt();
         int min=ui->min_2->text().toInt();
         int views=ui->leviwes_2->text().toInt();
    Program P(id_p,id_s,nom_p,acteur,jj,mm,yyyy,heure,min,views);
    bool test=P.modifier();
    bool nid=P.getid_p();
    bool nids=P.getid_s();

     ui->tableView_7->setModel(ptmp.afficher());
     if (!nid){test=false;
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("inserer id  \n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);}
    else if (!nids){test=false;
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("inserer id salle \n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);}
    else if (nom_p==""){test=false;
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("inserer nom du proramme \n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);}

    else if (acteur==""){test=false;
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("inserer nom d'acteur\n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);}
    if(test)
    {
       QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification validé\n"
                                                                               "Click Cancel to exit"),QMessageBox::Cancel);}
            else

        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Modification non validé\n"
                                                                       "Click Cancel to exit"),QMessageBox::Cancel);
}

void programme_salle::on_le_id_supp_4_clicked()
{
    {
       int id_p=ui->le_id_supp_3->text().toInt();
         bool test=ptmp.supprimer(id_p);
         ui->tableView_7->setModel(ptmp.afficher());
         if(test)
         {

            QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression validé\n"
                                                                                    "Click Cancel to exit"),QMessageBox::Cancel); }
                 else
             QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Suppression non validé\n"
                                                                            "Click Cancel to exit"),QMessageBox::Cancel);}
}

void programme_salle::on_historique_2_clicked()
{
   ui->tableView_9->setModel(h.afficherh());
}

void programme_salle::on_chart_2_clicked()
{

}

void programme_salle::on_supprimer_historique_2_clicked()
{
    int id_p =ui->le_supph_2->text().toInt();
        bool test=h.supprimer(id_p);
       ui->tableView_9->setModel(h.afficherh());
        if(test)
        {

           QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression validé\n"
                                                                                   "Click Cancel to exit"),QMessageBox::Cancel); }
                else
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Suppression non validé\n"
                                                                           "Click Cancel to exit"),QMessageBox::Cancel);
}

void programme_salle::on_supprimer_tout_2_clicked()
{
    int id_p =ui->le_supph_2->text().toInt();
        bool test=h.supprimertout(id_p);
       ui->tableView_8->setModel(h.afficherh());
        if(test)
        {

           QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression validé\n"
                                                                                   "Click Cancel to exit"),QMessageBox::Cancel); }
                else
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Suppression non validé\n"
                                                                           "Click Cancel to exit"),QMessageBox::Cancel);
}
void programme_salle::mygame()
{  Program P;
    QDate date=QDate::currentDate();
    QTime time2=QTime::currentTime();
   QString time_txt=time2.toString(" hh : mm : ss");
   QString date_text=date.toString("yyyy-MM-dd");
   ui->time_4->setText(time_txt);

   ui->date_2->setText(date_text);
}
