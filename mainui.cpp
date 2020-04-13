#include "mainui.h"
#include "ui_mainui.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
MainUI::MainUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainUI)
{
    ui->setupUi(this);
    w = new MainWindow;
    w->hide();
    connect(w,SIGNAL(show_M()),this,SLOT(yincang()));
    this->setWindowTitle("MainWindow");
}

MainUI::~MainUI()
{
    delete ui;
}

void MainUI::show_M()
{
    w->show();
    this->hide();
    w->ui->pushButton_3->show();
    w->ui->label->hide();
    w->ui->label_2->hide();
    w->ui->label_3->hide();
    w->ui->label_4->hide();
    w->ui->label_5->hide();
    w->ui->label_6->hide();
    w->ui->horizontalSlider->hide();
    w->ui->horizontalSlider_2->hide();
    w->ui->horizontalSlider_3->hide();
    w->ui->horizontalSlider_4->hide();
    w->ui->horizontalSlider_5->hide();
    w->ui->horizontalSlider_6->hide();
    w->ui->pushButton_4->hide();
    w->ui->label_7->hide();
    w->ui->label_8->hide();
    w->ui->textEdit->hide();
    w->ui->lineEdit->hide();
    w->ui->lineEdit_2->hide();
    w->ui->pushButton_7->hide();
    w->ui->pushButton_5->hide();
    w->ui->pushButton_6->hide();
}

void MainUI::show_M_2()
{
    w->show();
    this->hide();
    w->ui->pushButton_3->hide();
    w->ui->label->show();
    w->ui->label_2->show();
    w->ui->label_3->show();
    w->ui->label_4->show();
    w->ui->label_5->show();
    w->ui->label_6->show();
    w->ui->horizontalSlider->show();
    w->ui->horizontalSlider_2->show();
    w->ui->horizontalSlider_3->show();
    w->ui->horizontalSlider_4->show();
    w->ui->horizontalSlider_5->show();
    w->ui->horizontalSlider_6->show();
    w->ui->pushButton_4->hide();
    w->ui->label_7->hide();
    w->ui->label_8->hide();
    w->ui->textEdit->hide();
    w->ui->lineEdit->hide();
    w->ui->lineEdit_2->hide();
    w->ui->pushButton_7->hide();
    w->ui->pushButton_5->show();
    w->ui->pushButton_6->show();
}

void MainUI::show_M_3()
{
    w->show();
    this->hide();
    w->ui->pushButton->hide();
    w->ui->pushButton_3->hide();
    w->ui->pushButton_4->show();
    w->ui->label->hide();
    w->ui->label_2->hide();
    w->ui->label_3->hide();
    w->ui->label_4->hide();
    w->ui->label_5->hide();
    w->ui->label_6->hide();
    w->ui->horizontalSlider->hide();
    w->ui->horizontalSlider_2->hide();
    w->ui->horizontalSlider_3->hide();
    w->ui->horizontalSlider_4->hide();
    w->ui->horizontalSlider_5->hide();
    w->ui->horizontalSlider_6->hide();
    w->ui->label_7->show();
    w->ui->label_8->show();
    w->ui->textEdit->show();
    w->ui->lineEdit->show();
    w->ui->lineEdit_2->show();
    w->ui->pushButton_7->show();
    w->ui->pushButton_5->hide();
    w->ui->pushButton_6->hide();
}

void MainUI::yincang()
{
    w->hide();
    this->show();
}
