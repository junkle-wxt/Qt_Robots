#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>
#include<QtDebug>
#include <QTimer>
#include <QMessageBox>
#include <QDir>
#include <QTextCodec>

#pragma warning(disable:4819)


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),r1(0),r2(0),r3(0),r4(0),r5(0),r6(0),num(0),flag(false),\
      flag_1(false),flag_2(false),flag_3(false),flag_4(false),flag_5(false),flag_6(false),\
        record_sta(false)
{
    ui->setupUi(this);
    time = new QTimer;
    time->setInterval(5);
    record_time = new QTimer;
    record_time->setInterval(50);
    connect(record_time,SIGNAL(timeout()),this,SLOT(path_recur()));
    connect(time,SIGNAL(timeout()),this,SLOT(simulation_bs()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(go_time()));
    SoQt::init(ui->widget);//OIV与Qt结合初始化 必须加
    m_rot1 = new SoRotationXYZ;
    m_rot2 = new SoRotationXYZ;
    m_rot3 = new SoRotationXYZ;
    m_rot4 = new SoRotationXYZ;
    m_rot5 = new SoRotationXYZ;
    m_rot6 = new SoRotationXYZ;

    //设置角度范围（限位）
    ui->horizontalSlider->setRange(-180,180);
    ui->horizontalSlider_2->setRange(-180,180);
    ui->horizontalSlider_3->setRange(-180,180);
    ui->horizontalSlider_4->setRange(-180,180);
    ui->horizontalSlider_5->setRange(-180,180);
    ui->horizontalSlider_6->setRange(-360,360);

    //初始化归零位置
    ui->horizontalSlider->setValue(0);
    ui->horizontalSlider_2->setValue(0);
    ui->horizontalSlider_3->setValue(0);
    ui->horizontalSlider_4->setValue(0);
    ui->horizontalSlider_5->setValue(0);
    ui->horizontalSlider_6->setValue(0);

    //装配机械臂
    makeScene();

}


MainWindow::~MainWindow()
{
    delete ui;
}

SoSeparator *MainWindow::makeRod0()
{
        SoSeparator* base = new SoSeparator;//因为函数要返回soseparator*类型
        SoTransform* form0 = new SoTransform;
        form0->translation.setValue(0, 0, 0);
        QString s1 = QDir::currentPath().left(QDir::currentPath().size()-4)+"/models/base.wrl";
        QTextCodec *code = QTextCodec::codecForName("GB2312");//解决中文路径问题
         s1 = code->fromUnicode(s1).data();
        SoSeparator *mygraph = openModel(s1);
        mygraph->ref();
        base->addChild(form0);
        base->addChild(mygraph);
        return base;
}

SoSeparator *MainWindow::makeRod1()
{
        SoSeparator* YT_shoulder = new SoSeparator;//因为函数要返回soseparator*类型
        YT_shoulder->ref();

        SoTransform* form1 = new SoTransform;//这个是
        form1->translation.setValue(0, 70,0);//导入的模型记录了建立的原点,通过装配体测两零件间的坐标系原点距离

        m_rot1->axis = SoRotationXYZ::Y;
        QString s1 = QDir::currentPath().left(QDir::currentPath().size()-4)+"/models/guanjie1.wrl";
        QTextCodec *code = QTextCodec::codecForName("GB2312");//解决中文路径问题
         s1 = code->fromUnicode(s1).data();
        SoSeparator *mygraph =openModel(s1);
        mygraph->ref();

        YT_shoulder->addChild(form1);
        YT_shoulder->addChild(m_rot1);
        YT_shoulder->addChild(mygraph);
        return YT_shoulder;
}

SoSeparator *MainWindow::makeRod2()
{
        SoSeparator* YT_arm = new SoSeparator;
        m_rot2->axis = SoRotationXYZ::X;
        SoTransform* form2 = new SoTransform;
        form2->translation.setValue(static_cast<float>(71.65),static_cast<float>(72.15),0);
         QString s1 = QDir::currentPath().left(QDir::currentPath().size()-4)+"/models/guanjie2.wrl";
         QTextCodec *code = QTextCodec::codecForName("GB2312");//解决中文路径问题
          s1 = code->fromUnicode(s1).data();
        SoSeparator* mygraph =openModel(s1);
        mygraph->ref();
        YT_arm->addChild(form2);
        YT_arm->addChild(m_rot2);
        YT_arm->addChild(mygraph);
        return YT_arm;
}

SoSeparator *MainWindow::makeRod3()
{
        SoSeparator* YT_elbow = new SoSeparator;//因为函数要返回soseparator*类型
        YT_elbow->ref();
        m_rot3->axis = SoRotationXYZ::X;
        SoTransform* form3 = new SoTransform;
        form3->translation.setValue(static_cast<float>(7.75), static_cast<float>(384.8), 0);
         QString s1 = QDir::currentPath().left(QDir::currentPath().size()-4)+"/models/guanjie3.wrl";
         QTextCodec *code = QTextCodec::codecForName("GB2312");//解决中文路径问题
          s1 = code->fromUnicode(s1).data();
        SoSeparator *mygraph = openModel(s1);
        YT_elbow->addChild(form3);
        YT_elbow->addChild(m_rot3);
        YT_elbow->addChild(mygraph);
        return YT_elbow;
}

SoSeparator *MainWindow::makeRod4()
{
        SoSeparator* YT_forearm = new SoSeparator;//因为函数要返回soseparator*类型
        YT_forearm->ref();
        SoTransform* form4 = new SoTransform;
        form4->translation.setValue(static_cast<float>(9.1), static_cast<float>(352.8), 0);
        m_rot4->axis = SoRotationXYZ::X;
         QString s1 = QDir::currentPath().left(QDir::currentPath().size()-4)+"/models/guanjie4.wrl";
         QTextCodec *code = QTextCodec::codecForName("GB2312");//解决中文路径问题
          s1 = code->fromUnicode(s1).data();
        SoSeparator *mygraph = openModel(s1);
        YT_forearm->addChild(form4);
        YT_forearm->addChild(m_rot4);
        YT_forearm->addChild(mygraph);
        return YT_forearm;
}

SoSeparator *MainWindow::makeRod5()
{
        SoSeparator* YT_wrist = new SoSeparator;
        YT_wrist->ref();
        m_rot5->axis = SoRotationXYZ::Y;
        SoTransform* form5 = new SoTransform;
        form5->translation.setValue(static_cast<float>(54.1), static_cast<float>(65.6), 0);
         QString s1 = QDir::currentPath().left(QDir::currentPath().size()-4)+"/models/guanjie5.wrl";
         QTextCodec *code = QTextCodec::codecForName("GB2312");//解决中文路径问题
          s1 = code->fromUnicode(s1).data();
        SoSeparator *mygraph = openModel(s1);
        YT_wrist->addChild(form5);
        YT_wrist->addChild(m_rot5);
        YT_wrist->addChild(mygraph);
        return YT_wrist;
}

SoSeparator *MainWindow::makeRod6()
{
        SoSeparator* YT_tool_flange = new SoSeparator;//因为函数要返回soseparator*类型
        YT_tool_flange->ref();
        SoTransform* form6 = new SoTransform;
        form6->translation.setValue(static_cast<float>(65.6), static_cast<float>(54.1), 0);
        m_rot6->axis = SoRotationXYZ::X;
         QString s1 = QDir::currentPath().left(QDir::currentPath().size()-4)+"/models/falan.wrl";
         QTextCodec *code = QTextCodec::codecForName("GB2312");//解决中文路径问题
          s1 = code->fromUnicode(s1).data();
        SoSeparator *mygraph = openModel(s1);
        YT_tool_flange->addChild(form6);
        YT_tool_flange->addChild(m_rot6);
        YT_tool_flange->addChild(mygraph);
        return YT_tool_flange;
}

void MainWindow::makeScene()
{
        root = new SoSeparator;
        root->ref();   //这个是总结点，要释放下
        SoSeparator *robot = new SoSeparator;
        SoSeparator *Rod0 = new SoSeparator;
        SoSeparator *Rod1 = new SoSeparator;
        SoSeparator *Rod2 = new SoSeparator;
        SoSeparator *Rod3 = new SoSeparator;
        SoSeparator *Rod4 = new SoSeparator;
        SoSeparator *Rod5 = new SoSeparator;
        SoSeparator *Rod6 = new SoSeparator;

        Rod0 = makeRod0();
        Rod1 = makeRod1();
        Rod1->setName("rod1");
        Rod2 = makeRod2();
        Rod2->setName("rod2");
        Rod3 = makeRod3();
        Rod3->setName("rod3");
        Rod4 = makeRod4();
        Rod4->setName("rod4");
        Rod5 = makeRod5();
        Rod5->setName("rod5");
        Rod6 = makeRod6();
        Rod6->setName("rod6");
        //设置旋转角度
        m_rot1->angle = 0*PI/180;
        m_rot2->angle = 0*PI/180;
        m_rot3->angle = 0*PI/180;
        m_rot4->angle = 0*PI/180;
        m_rot5->angle = 0*PI/180;
        m_rot6->angle = 0*PI/180;

        //按相对坐标  Rod0->addChild(Rod1);表示在ROd0坐标系中组装
        robot->addChild(Rod0);
        Rod0->addChild(Rod1);
        Rod1->addChild(Rod2);
        Rod2->addChild(Rod3);
        Rod3->addChild(Rod4);
        Rod4->addChild(Rod5);
        Rod5->addChild(Rod6);
        root->addChild(robot);
        myView = new SoQtExaminerViewer(ui->widget);
        myView->setBackgroundColor(SbColor(static_cast<float>(0.7),static_cast<float>(0.7),static_cast<float>(0.7)));
        myView->setSceneGraph(root);
        myView->viewAll();
        myView->show();
}

void MainWindow::set_pos(int r1, int r2, int r3, int r4, int r5, int r6)
{
    ui->horizontalSlider->setValue(r1);
    ui->horizontalSlider_2->setValue(r2);
    ui->horizontalSlider_3->setValue(r3);
    ui->horizontalSlider_4->setValue(r4);
    ui->horizontalSlider_5->setValue(r5);
    ui->horizontalSlider_6->setValue(r6);
}

void MainWindow::go_zero()
{
    set_pos(0,0,0,0,0,0);
}

void MainWindow::show1()
{
    QWidget *nnn = new QWidget();
    nnn->show();
}

void MainWindow::simulation_bs()
{
    if(!flag_1)
    {
        if(!flag)
        {
            r1++;
            set_pos(r1,r2,r3,r4,r5,r6);
            if(r1 == 180)
            {
                flag = true;
            }
        }
        if(flag)
        {
            r1--;
            set_pos(r1,r2,r3,r4,r5,r6);
            if(r1 == 0)
            {
                flag = false;
                flag_1 = true;
                flag_2 = true;
            }
        }
    }

    if(flag_2)
    {
        if(!flag)
        {
            r2++;
            set_pos(r1,r2,r3,r4,r5,r6);
            if(r2 == 180)
            {
                flag = true;
            }
        }
        if(flag)
        {
            r2--;
            set_pos(r1,r2,r3,r4,r5,r6);
            if(r2 == 0)
            {
                flag = false;
                flag_2 = false;
                flag_3 = true;
            }
        }
    }
    if(flag_3)
    {
        if(!flag)
        {
            r3++;
            set_pos(r1,r2,r3,r4,r5,r6);
            if(r3 == 130)
            {
                flag = true;
            }
        }
        if(flag)
        {
            r3--;
            set_pos(r1,r2,r3,r4,r5,r6);
            if(r3 == 0)
            {
                flag = false;
                flag_3 = false;
                flag_4 = true;
            }
        }
    }
    if(flag_4)
    {
        if(!flag)
        {
            r4++;
            set_pos(r1,r2,r3,r4,r5,r6);
            if(r4 == 180)
            {
                flag = true;
            }
        }
        if(flag)
        {
            r4--;
            set_pos(r1,r2,r3,r4,r5,r6);
            if(r4 == 0)
            {
                flag = false;
                flag_4 = false;
                flag_5 = true;
            }
        }
    }
    if(flag_5)
    {
        if(!flag)
        {
            r5++;
            set_pos(r1,r2,r3,r4,r5,r6);
            if(r5 == 180)
            {
                flag = true;
            }
        }
        if(flag)
        {
            r5--;
            set_pos(r1,r2,r3,r4,r5,r6);
            if(r5 == 0)
            {
                flag = false;
                flag_5 = false;
                flag_6 = true;
            }
        }
    }
    if(flag_6)
    {
        if(!flag)
        {
            r6++;
            set_pos(r1,r2,r3,r4,r5,r6);
            if(r6 == 180)
            {
                flag = true;
            }
        }
        if(flag)
        {
            r6--;
            set_pos(r1,r2,r3,r4,r5,r6);
            if(r6 == 0)
            {
                flag = false;
                flag_6 = false;
                time->stop();
                 flag_1  =  false;
                 QMessageBox::information(this,"tip",tr("Finished"));
            }
        }
    }
}

void MainWindow::emit_signal()
{
    emit show_M();
}

void MainWindow::go_time()
{
    time->start();
}

void MainWindow::path_record()
{
    if(record_sta)
    {
        sub_v1.clear();
        sub_v1.push_back(ui->horizontalSlider->value());
        sub_v1.push_back(ui->horizontalSlider_2->value());
        sub_v1.push_back(ui->horizontalSlider_3->value());
        sub_v1.push_back(ui->horizontalSlider_4->value());
        sub_v1.push_back(ui->horizontalSlider_5->value());
        sub_v1.push_back(ui->horizontalSlider_6->value());
        v1.push_back(sub_v1);
    }
}

void MainWindow::path_recur()
{
    if(!v1.isEmpty())
    {
        QVector<int> &sub =  v1.first();
        ui->horizontalSlider->setValue(sub[0]);
        ui->horizontalSlider_2->setValue(sub[1]);
        ui->horizontalSlider_3->setValue(sub[2]);
        ui->horizontalSlider_4->setValue(sub[3]);
        ui->horizontalSlider_5->setValue(sub[4]);
        ui->horizontalSlider_6->setValue(sub[5]);
        v1.pop_front();
    }else
    {
         record_time->stop();
         QMessageBox::information(this,"tip",tr("Recurrence Successfully!"));
    }
}

void MainWindow::open_record()
{
    record_sta = true;
    v1.clear();
}

void MainWindow::open_record_time()
{
    record_sta = false;
    record_time->start();
}

SoSeparator *openModel(QString fileName)
{
        SoInput myInput;
        SoSearchAction search;
        search.setType(SoVRMLGroup::getClassTypeId());
        SoSeparator *root = new SoSeparator;
        search.setInterest(SoSearchAction::FIRST);
        search.apply(root);

        // 打开wrl文件
        if(!myInput.openFile(fileName.toStdString().data()))
        {
            qDebug()<<"open error  "<<"lines:"<<__LINE__;
            exit(-1);
        }
        SoVRMLGroup *objectmodel=SoDB::readAllVRML(&myInput);
        root->addChild(objectmodel);
        return  root;
}

void MainWindow::axis1(int num)
{
    m_rot1->angle =static_cast<float>(num* PI/180);
}

void MainWindow::axis2(int num)
{
    m_rot2->angle =static_cast<float>(num* PI/180);
}

void MainWindow::axis3(int num)
{
    m_rot3->angle =static_cast<float>(num* PI/180);
}

void MainWindow::axis4(int num)
{
    m_rot4->angle =static_cast<float>(num* PI/180);
}

void MainWindow::axis5(int num)
{
    m_rot5->angle =static_cast<float>(num* PI/180);
}

void MainWindow::axis6(int num)
{
    m_rot6->angle =static_cast<float>(num* PI/180);
}

void MainWindow::on_pushButton_4_clicked()
{
        QMessageBox::information(this,"tip",tr("Connect error!"));
}
