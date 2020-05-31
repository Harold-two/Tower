#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include<QLabel>
#include<QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
    void paintEvent(QPaintEvent );
    void timerEvent(QTimerEvent *);
    void check(int in);
    static int num;
    QPushButton *btn[10];

private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H
