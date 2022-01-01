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
    void func(Ui::MainWindow *);
    void DDALine(float x1, float y1, float x2, float y2, Ui::MainWindow *);
    void delay(int millisecondsToWait);
    void BresenhamCircle(int xCenter, int yCenter, int radius, Ui::MainWindow *);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    Samarth obj;
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
