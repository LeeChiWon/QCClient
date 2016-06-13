#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow *pMain=nullptr; //메인윈도우 변수

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Init(); //초기화
    //backho1
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Init()
{
    pMain=this; //메인윈도우 복사
    ui->mdiArea->setBackground(*new QBrush(*new QPixmap(":/Image/Image/background.png"))); //QMDIArea 배경화면 추가
}

void MainWindow::LoadSubWindow(QWidget *widget)
{
    auto Window=ui->mdiArea->addSubWindow(widget);
    Window->setWindowTitle(widget->windowTitle());
    Window->setWindowIcon(widget->windowIcon());
    Window->show();
}

void MainWindow::on_action_Configration_triggered() //환경설정 버튼 클릭 이벤트
{
     if(cConfigration_Form.isNull())
     {
         cConfigration_Form=new Configration_Form();
         LoadSubWindow(cConfigration_Form);
     }
}

void MainWindow::on_action_Show_WorkPlan_triggered() //작업계획 버튼 클릭 이벤트
{
    if(cWorkPlan_Form.isNull())
    {
        cWorkPlan_Form=new WorkPlan_Form();
        LoadSubWindow(cWorkPlan_Form);
    }
}

void MainWindow::on_action_Show_Temperature_triggered() //온도현황판 버튼 클릭 이벤트
{
    if(cTemperature_Form.isNull())
    {
        cTemperature_Form=new Temperature_Form();
        LoadSubWindow(cTemperature_Form);
    }
}
