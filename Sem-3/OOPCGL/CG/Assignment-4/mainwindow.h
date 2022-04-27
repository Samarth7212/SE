#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Line{
public:
        void DDALine(int x1,int y1,int x2,int y2);
        void delay(int millisecondsToWait);
};

class MainWindow : public QMainWindow,Line
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void drawLine(int x1,int y1,int x2,int y2);
    int sign(float x);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    float a[10],b[10],slope[10],x[10];
    int ver;
    bool start;
protected:
    void mousePressEvent(QMouseEvent *event);
};
#endif // MAINWINDOW_H
