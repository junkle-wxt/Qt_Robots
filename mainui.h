#ifndef MAINUI_H
#define MAINUI_H

#include <QWidget>
#include "mainwindow.h"
namespace Ui {
class MainUI;
}

class MainUI : public QWidget
{
    Q_OBJECT

public:
    explicit MainUI(QWidget *parent = NULL);
    ~MainUI();

private:
    Ui::MainUI *ui;
    MainWindow *w;
public slots:
    void show_M();
    void show_M_2();
    void show_M_3();
    void yincang();
};

#endif // MAINUI_H
