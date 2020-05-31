#include "mainscene.h"
#include "ui_mainscene.h"
#include<QPaintEvent>
#include <QWidget>
#include <QPainter>     //画家
#include <QMouseEvent>
#include<QPushButton>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    startTimer(1000);
    this->setFixedSize(1200,450);
    this->setWindowIcon(QPixmap(":/ruc/overwatch.jpg"));
    this->setWindowTitle("Overwatch");
    //关闭
    connect(ui->actionquit,&QAction::triggered,[=](){this->close();});
    //造塔

    int i,m=0;
    for(i=0;i<4;i++)
    {
    m=140+100*i;
    btn[i] =new QPushButton("塔位",this);
    btn[i]->setGeometry(m,270,40,65);
    }
    m=0;
    for(i=4;i<8;i++)
    {
        m=140+100*(i-4);
        btn[i] =new QPushButton("塔位",this);
        btn[i]->setGeometry(m,120,40,65);
    }
    for(i=0;i<8;i++)
    {
    if(connect(btn[i],&QPushButton::clicked,this, &MainScene::check)==0)
    {
        check(i);
    }
    };

}
int MainScene::num=0;
void MainScene::paintEvent(QPaintEvent )
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/ruc/map3.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
void MainScene::timerEvent(QTimerEvent *)
{

    num=1;
    ui->label_2->setText(QString::number(num++));

}


void MainScene::check(int j)
{
    if(num>10)
    {
        btn[j]->setText("炮塔");
        num=num-10;
    }
}

MainScene::~MainScene()
{
    delete ui;
}

