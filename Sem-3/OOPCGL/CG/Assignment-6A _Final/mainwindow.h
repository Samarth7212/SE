#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class Samarth
{
public:
    friend class MainWindow;
    void func(Ui::MainWindow *);
    void delay(int millisecondsToWait);
    void BresenhamLine(int x1, int y1, int x2, int y2, Ui::MainWindow *);
    void DDALine(float x1, float y1, float x2, float y2, Ui::MainWindow *);
    void BresenhamCircle(int xCenter, int yCenter, int radius, Ui::MainWindow *);
};

class MainWindow : public QMainWindow,Samarth
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;

public:
    Samarth obj;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
};

#endif // MAINWINDOW_H
