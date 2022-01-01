#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void dda(float x1, float y1, float x2, float y2, QColor color); // Line drawing function
    void mousePressEvent(QMouseEvent *ev);                          // Mouse event
    void ClearScreen();                                             // CLearing screen
    void clearFields();                                             // Clearing inputs.

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    float x1, y1, x2, y2, tx, ty, sx, sy, x; // Necessary variables.
    float a[20], b[20];                      // To store x and y values for mouse event
    int ver;
    bool start;
};
#endif // MAINWINDOW_H
