#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void test(int c[4],int d[4]);
    void drawLine1(int x1,int y1,int x2,int y2);
    void drawLine2(int x1,int y1,int x2,int y2);
    void code(int c[4],float x,float y);
    void clip(int c[4],int d[4],float &x,float &y,float m);
    int sign(int x);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    float a[100];//For X Co-odrinates
    float c[100];//Foy Y Co-ordinates
    int ver=0;//Line(Endpoints) count
    bool start,flag,mouseEn;//Necessary boolean variables to make program interactive.
};
#endif // MAINWINDOW_H
