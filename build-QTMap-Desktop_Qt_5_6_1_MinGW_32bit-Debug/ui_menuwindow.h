/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName(QStringLiteral("MenuWindow"));
        MenuWindow->resize(400, 300);
        buttonBox = new QDialogButtonBox(MenuWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pushButton = new QPushButton(MenuWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 50, 111, 41));
        pushButton_2 = new QPushButton(MenuWindow);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 130, 111, 41));

        retranslateUi(MenuWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), MenuWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MenuWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(MenuWindow);
    } // setupUi

    void retranslateUi(QDialog *MenuWindow)
    {
        MenuWindow->setWindowTitle(QApplication::translate("MenuWindow", "Dialog", 0));
        pushButton->setText(QApplication::translate("MenuWindow", "\345\274\200\345\247\213\346\270\270\346\210\217", 0));
        pushButton_2->setText(QApplication::translate("MenuWindow", "\350\257\273\345\217\226\345\255\230\346\241\243", 0));
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
