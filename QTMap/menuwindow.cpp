#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "mw1.h"
#include "ui_mw1.h"


#include <QDebug>

MenuWindow::MenuWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose,1);
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::on_pushButton_clicked(){
    this->hide();
    MW1 *mwdlg = new MW1 (this);
    mwdlg->newgame();
    connect(mwdlg,SIGNAL(sendsignal()),this,SLOT(reshow()));
    mwdlg->show();
}

void MenuWindow::reshow(){
    this->show();
}

void MenuWindow::on_pushButton_2_clicked()
{
    this->hide();
    MW1 *mwdlg = new MW1 (this);
    mwdlg->loadgame();
    connect(mwdlg,SIGNAL(sendsignal()),this,SLOT(reshow()));
    mwdlg->show();
}
