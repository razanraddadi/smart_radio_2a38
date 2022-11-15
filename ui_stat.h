/********************************************************************************
** Form generated from reading UI file 'stat.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAT_H
#define UI_STAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_stat
{
public:

    void setupUi(QDialog *stat)
    {
        if (stat->objectName().isEmpty())
            stat->setObjectName(QStringLiteral("stat"));
        stat->resize(400, 300);

        retranslateUi(stat);

        QMetaObject::connectSlotsByName(stat);
    } // setupUi

    void retranslateUi(QDialog *stat)
    {
        stat->setWindowTitle(QApplication::translate("stat", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class stat: public Ui_stat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAT_H
