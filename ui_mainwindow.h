/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLineEdit *le_cin;
    QLineEdit *le_nom;
    QLineEdit *le_prenom;
    QLineEdit *le_metier;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pb_ajouter;
    QLabel *label_13;
    QLineEdit *le_age;
    QLabel *label_12;
    QWidget *tab_2;
    QTableView *tab_invitee;
    QPushButton *pushButton_3;
    QLabel *label_11;
    QPushButton *pushButton_4;
    QWidget *tab_3;
    QLabel *label_5;
    QLineEdit *le_cin_supp;
    QPushButton *pb_supprimer;
    QToolButton *toolButton;
    QWidget *tab_5;
    QLabel *label_10;
    QLineEdit *le_r;
    QPushButton *pb_recherche;
    QTableView *tableView;
    QPushButton *pushButton;
    QWidget *tab_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pb_update;
    QPushButton *pb_annuler;
    QLineEdit *le_cin_modf;
    QLineEdit *le_nom_modf;
    QLineEdit *le_prenom_modf;
    QLineEdit *le_metier_modf;
    QLineEdit *le_age_modf;
    QLabel *label_14;
    QWidget *tab_6;
    QPushButton *pushButton_2;
    QTableView *tableView_2;
    QToolButton *toolButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(844, 558);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 791, 511));
        tabWidget->setStyleSheet(QStringLiteral("background-color: rgb(114, 232, 255);"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 30, 441, 251));
        le_cin = new QLineEdit(groupBox);
        le_cin->setObjectName(QStringLiteral("le_cin"));
        le_cin->setGeometry(QRect(130, 50, 113, 20));
        le_nom = new QLineEdit(groupBox);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(130, 90, 113, 20));
        le_prenom = new QLineEdit(groupBox);
        le_prenom->setObjectName(QStringLiteral("le_prenom"));
        le_prenom->setGeometry(QRect(130, 130, 113, 20));
        le_metier = new QLineEdit(groupBox);
        le_metier->setObjectName(QStringLiteral("le_metier"));
        le_metier->setGeometry(QRect(130, 170, 113, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 47, 14));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 47, 14));
        label_2->setFont(font);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 130, 71, 20));
        label_3->setFont(font);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 170, 71, 16));
        label_4->setFont(font);
        pb_ajouter = new QPushButton(groupBox);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(290, 110, 75, 23));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 210, 61, 16));
        label_13->setFont(font);
        le_age = new QLineEdit(groupBox);
        le_age->setObjectName(QStringLiteral("le_age"));
        le_age->setGeometry(QRect(130, 210, 113, 20));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(600, 210, 91, 61));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_invitee = new QTableView(tab_2);
        tab_invitee->setObjectName(QStringLiteral("tab_invitee"));
        tab_invitee->setGeometry(QRect(30, 20, 621, 301));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 370, 75, 23));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(480, 330, 151, 101));
        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(60, 370, 75, 23));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 40, 47, 14));
        label_5->setFont(font);
        le_cin_supp = new QLineEdit(tab_3);
        le_cin_supp->setObjectName(QStringLiteral("le_cin_supp"));
        le_cin_supp->setGeometry(QRect(190, 40, 113, 20));
        pb_supprimer = new QPushButton(tab_3);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(210, 100, 75, 23));
        toolButton = new QToolButton(tab_3);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(310, 80, 23, 20));
        tabWidget->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        label_10 = new QLabel(tab_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(70, 100, 101, 21));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_10->setFont(font1);
        le_r = new QLineEdit(tab_5);
        le_r->setObjectName(QStringLiteral("le_r"));
        le_r->setGeometry(QRect(350, 100, 113, 20));
        pb_recherche = new QPushButton(tab_5);
        pb_recherche->setObjectName(QStringLiteral("pb_recherche"));
        pb_recherche->setGeometry(QRect(220, 190, 75, 23));
        tableView = new QTableView(tab_5);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(370, 150, 256, 121));
        pushButton = new QPushButton(tab_5);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 250, 75, 23));
        tabWidget->addTab(tab_5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_6 = new QLabel(tab_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(100, 60, 47, 14));
        label_6->setFont(font);
        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(100, 90, 47, 14));
        label_7->setFont(font1);
        label_8 = new QLabel(tab_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(100, 120, 81, 16));
        label_8->setFont(font);
        label_9 = new QLabel(tab_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(100, 150, 81, 16));
        label_9->setFont(font);
        pb_update = new QPushButton(tab_4);
        pb_update->setObjectName(QStringLiteral("pb_update"));
        pb_update->setGeometry(QRect(160, 220, 75, 23));
        pb_annuler = new QPushButton(tab_4);
        pb_annuler->setObjectName(QStringLiteral("pb_annuler"));
        pb_annuler->setGeometry(QRect(250, 220, 75, 23));
        le_cin_modf = new QLineEdit(tab_4);
        le_cin_modf->setObjectName(QStringLiteral("le_cin_modf"));
        le_cin_modf->setGeometry(QRect(320, 60, 113, 20));
        le_nom_modf = new QLineEdit(tab_4);
        le_nom_modf->setObjectName(QStringLiteral("le_nom_modf"));
        le_nom_modf->setGeometry(QRect(320, 90, 113, 20));
        le_prenom_modf = new QLineEdit(tab_4);
        le_prenom_modf->setObjectName(QStringLiteral("le_prenom_modf"));
        le_prenom_modf->setGeometry(QRect(320, 120, 113, 20));
        le_metier_modf = new QLineEdit(tab_4);
        le_metier_modf->setObjectName(QStringLiteral("le_metier_modf"));
        le_metier_modf->setGeometry(QRect(320, 150, 113, 20));
        le_age_modf = new QLineEdit(tab_4);
        le_age_modf->setObjectName(QStringLiteral("le_age_modf"));
        le_age_modf->setGeometry(QRect(320, 180, 113, 20));
        label_14 = new QLabel(tab_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(100, 180, 47, 14));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        label_14->setFont(font2);
        tabWidget->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        pushButton_2 = new QPushButton(tab_6);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 150, 75, 23));
        tableView_2 = new QTableView(tab_6);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(360, 70, 256, 192));
        toolButton_2 = new QToolButton(tab_6);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(280, 150, 23, 20));
        tabWidget->addTab(tab_6, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 844, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "NOM", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "PRENOM", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "METIER", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "AGE", Q_NULLPTR));
        label_12->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Ajouter inviter", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "QRCODE", Q_NULLPTR));
        label_11->setText(QString());
        pushButton_4->setText(QApplication::translate("MainWindow", "STAT", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "afficher inviter", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        toolButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "supprimer un inviter", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Recherche", Q_NULLPTR));
        pb_recherche->setText(QApplication::translate("MainWindow", "Chercher", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "chercher un inviter", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "NOM", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "PRENOM", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "METIER", Q_NULLPTR));
        pb_update->setText(QApplication::translate("MainWindow", "Update", Q_NULLPTR));
        pb_annuler->setText(QApplication::translate("MainWindow", "Annuler", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "AGE", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "modiffier un inviter", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Trier", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "tri inviter", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
