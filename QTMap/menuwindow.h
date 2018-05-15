#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QDialog>

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = 0);
    ~MenuWindow();
private slots:
    void on_pushButton_clicked();
    void reshow();

    void on_pushButton_2_clicked();

private:
    Ui::MenuWindow *ui;
};

#endif // MENUWINDOW_H
