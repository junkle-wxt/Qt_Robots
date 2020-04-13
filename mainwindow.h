#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define  PI  3.14159265358979323846

#include <QMainWindow>
#include <Inventor/Qt/SoQt.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/SoDB.h>
#include <Inventor/nodes/SoCube.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoTranslation.h>
#include <Inventor/nodes/SoTransform.h>
#include <Inventor/nodes/SoRotationXYZ.h>
#include<Inventor/SoInput.h>
#include<Inventor/actions/SoSearchAction.h>
#include<Inventor/VRMLnodes/SoVRMLGroup.h>
#include<Inventor/SoOffscreenRenderer.h>
#include<QVector>

//读取wrl模型 返回节点
SoSeparator * openModel(QString fileName);

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = NULL);
    ~MainWindow();
    SoSeparator *root;

    //旋转轴
    SoRotationXYZ *m_rot1;
    SoRotationXYZ *m_rot2;
    SoRotationXYZ *m_rot3;
    SoRotationXYZ *m_rot4;
    SoRotationXYZ *m_rot5;
    SoRotationXYZ *m_rot6;

    SoSeparator * makeRod0();
    SoSeparator * makeRod1();
    SoSeparator * makeRod2();
    SoSeparator * makeRod3();
    SoSeparator * makeRod4();
    SoSeparator * makeRod5();
    SoSeparator * makeRod6();
    void makeScene();
    SoQtExaminerViewer *myView;
    void set_pos(int r1, int r2, int r3, int r4, int r5, int r6);

 signals:
    void show_M();

private slots:
    void axis1(int num);
    void axis2(int num);
    void axis3(int num);
    void axis4(int num);
    void axis5(int num);
    void axis6(int num);
    void go_zero();
    void show1();
    void simulation_bs();
    void emit_signal();
    void go_time();
    void path_record();
    void path_recur();
    void open_record();
    void open_record_time();

    void on_pushButton_4_clicked();

public:
    Ui::MainWindow *ui;
    int r1,r2,r3,r4,r5,r6;
    QTimer *time;
    QTimer *record_time;
    int num;
    bool flag, flag_1, flag_2, flag_3,flag_4,flag_5,flag_6;
    QVector<QVector<int> > v1;
    QVector<int> sub_v1;
    bool record_sta;
};
#endif // MAINWINDOW_H
