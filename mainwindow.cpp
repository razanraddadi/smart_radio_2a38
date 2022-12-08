#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "invite.h"
#include <QMessageBox>
#include <QPainter>
#include <QDesktopServices>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QAbstractPrintDialog>
#include <QUrl>
#include <QDebug>
#include <QSqlQuery>
#include "arduino.h"
#include "QtWidgets"
#include<QLabel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int ret=A.connect_arduino(); // lancer la connexion à arduino
            switch(ret){
            case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                break;
            case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
               break;
            case(-1):qDebug() << "arduino is not available";

            }
             QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

             ui->label_3->setWindowFlags(Qt::FramelessWindowHint);
             ui->label_3->setMask((new QPixmap("C:/Users/Salim Mahdi/Desktop/63787-secure-login.gif"))->mask());
             QMovie *movie=new QMovie("C:/Users/Salim Mahdi/Desktop/63787-secure-login.gif");
             ui->label_3->setMovie(movie);
             movie->start();




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString cin,password;
          cin =ui->lineEdit_CINLOG->text();
          password=ui->lineEdit->text();

          invite I;
          QSqlQuery qry,query;

      if(qry.exec("select CIN,PASSWORD from INVITER where CIN='"+cin +"' and PASSWORD='"+password+"'"))
      {
              int count=0;
      while(qry.next())
      {
            count++;



       if(count==1)
       {
           query.prepare("INSERT INTO INVITER(CIN,PASSWORD) "
                                  "VALUES (:CIN,  :PW)");

                    query.bindValue(":CIN",qry.value(0).toString());

                    query.bindValue(":PW",qry.value(2).toString());

                    query.exec();



            this->hide();
              ui->lineEdit_CINLOG->clear();
              ui->lineEdit->clear();

              Dialog dialog;
                          dialog.setModal(true);
                          dialog.exec();








              }
      }

              if(count<1)
              {


              }
}}
void MainWindow::update_label()
{QString data="";
    int i;
    QString ch;
 QSqlQuery qry,query;

    data=A.read_from_arduino();

    qDebug()<<data;
if(data!="")
{
    for(i=0;i<data.length();i++)
    {

    I.serial=I.serial+data[i];
    }
}


    if(qry.exec("select cin,nom,prenom,metier,age,password,card from INVITER where card='"+I.serial+"'" ))
    {
        if(k==1)
        {
               I.serial="";
              k=0;
        }
            int count=0;


    while(qry.next())
    {QString d="";
      if(qry.value(1).toString()=="salim")
       A.write_to_arduino("1");

       else if(qry.value(1).toString()=="mohamed")
       A.write_to_arduino("2");


    Dialog dialog;
    dialog.setModal(true);
    dialog.exec();
          count++;

     if(count==1)
     {
    if ( I.getaccess()=="active")
     { ch=qry.value(1).toString();
        qDebug()<<ch;

I.setaccess("inactive");
Dialog dialog;
dialog.setModal(true);
dialog.exec();
I.setaccess("active");

I.serial="";
    }
}
     if(count<1)
         {
     I.serial="";
       if ( I.getaccess()=="active")
     {
          A.write_to_arduino("0");






      I.serial="";
      k=1;
      data="";

       }
         }

}



     }




}
