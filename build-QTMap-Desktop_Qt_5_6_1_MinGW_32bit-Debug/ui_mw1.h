/********************************************************************************
** Form generated from reading UI file 'mw1.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MW1_H
#define UI_MW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MW1
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MW1)
    {
        if (MW1->objectName().isEmpty())
            MW1->setObjectName(QStringLiteral("MW1"));
        MW1->resize(800, 600);
        centralwidget = new QWidget(MW1);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(710, 0, 93, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(710, 50, 93, 41));
        MW1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MW1);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MW1->setMenuBar(menubar);
        statusbar = new QStatusBar(MW1);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MW1->setStatusBar(statusbar);

        retranslateUi(MW1);

        QMetaObject::connectSlotsByName(MW1);
    } // setupUi

    void retranslateUi(QMainWindow *MW1)
    {
        MW1->setWindowTitle(QApplication::translate("MW1", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MW1", "\345\233\236\345\210\260\350\217\234\345\215\225", 0));
        pushButton_2->setText(QApplication::translate("MW1", "\345\255\230\346\241\243", 0));
    } // retranslateUi

};

namespace Ui {
    class MW1: public Ui_MW1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MW1_H
