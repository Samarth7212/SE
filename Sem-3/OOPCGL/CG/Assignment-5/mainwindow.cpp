#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QColorDialog"

#include<QMouseEvent>
#include<QtDebug>
#include<QTime>
#include<QMessageBox>
#include<iostream>

#define height 600
#define width 500
using namespace std;

QImage img(height, width, QImage::Format_RGB888);
QImage img1(height, width, QImage::Format_RGB888);
QColor color;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)

{
    //Setting initial black colour to label.
    for (int x = 0; x < height; ++x)
    {
        for (int y = 0; y < width; ++y)
        {
            //Each pixel is set to black colour
            img.setPixel(x, y, qRgb(0, 0, 0));
            img1.setPixel(x, y, qRgb(0, 0, 0));
        }
    }
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label_7->setPixmap(QPixmap::fromImage(img1));
    ver = 0;

    //Enabling and disabling required buttons.
    ui->pushButton_2->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->textEdit->setEnabled(false);
    ui->textEdit_2->setEnabled(false);
    ui->textEdit_3->setEnabled(false);
    ui->textEdit_4->setEnabled(false);

    //Setting necessary boolean variables.
    mouseEn = false;
    start = false;
    flag = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //Draw Window
    //Top left and bottom right points are entered.
    //Inputs are taken from user.
    QMessageBox msg;

    //Wrong OR empty input cases handled here.
    if (ui->textEdit->toPlainText().isEmpty() || ui->textEdit_2->toPlainText().isEmpty() ||
        ui->textEdit_3->toPlainText().isEmpty() || ui->textEdit_4->toPlainText().isEmpty() || !(ui->textEdit->toPlainText().toInt()) ||
        !(ui->textEdit_2->toPlainText().toInt()) || !(ui->textEdit_3->toPlainText().toInt()) || !(ui->textEdit_4->toPlainText().toInt()))
    {
        msg.information(0, "Warning!!", "Only numerical inputs are allowed!!!");
        //Clearing text fields.
        ui->textEdit->clear();
        ui->textEdit_2->clear();
        ui->textEdit_3->clear();
        ui->textEdit_4->clear();
    }
    else if (ui->textEdit->toPlainText().toInt() && ui->textEdit_2->toPlainText().toInt() &&
             ui->textEdit_3->toPlainText().toInt() && ui->textEdit_4->toPlainText().toInt())
    {
        //Taking input.
        int X1 = ui->textEdit->toPlainText().toInt();
        int Y1 = ui->textEdit_2->toPlainText().toInt();
        int X2 = ui->textEdit_3->toPlainText().toInt();
        int Y2 = ui->textEdit_4->toPlainText().toInt();

        //Calling line drawing functions for drawing window.
        drawLine1(X1, Y1, X2, Y1);
        drawLine1(X2, Y1, X2, Y2);
        drawLine1(X2, Y2, X1, Y2);
        drawLine1(X1, Y2, X1, Y1);

        //Drawing on label.
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->pushButton->setEnabled(false);
    }
}

//Function to draw line on main input window.
void MainWindow::drawLine1(int x1, int y1, int x2, int y2)
{
    int dx, dy, p;//Necessary variables.
    int x, y;
    int i = 0;
    x = x1;
    y = y1;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    if (dx >= dy)
    {
        p = 2 * dy - dx; //Decision parameter.
        while (i <= dx)
        {
            img.setPixel(x, y, color.rgb());
            if (p < 0)
            {
                p = p + 2 * dy;
            }
            else
            {
                p = p + 2 * (dy - dx);
                y = y + sign(y2 - y1);
            }
            x = x + sign(x2 - x1);
            i++;
        }
    }
    else
    {

        p = 2 * dx - dy;
        while (i <= dy)
        {
            img.setPixel(x, y, color.rgb());
            if (p < 0)
            {
                p = p + 2 * dx;
            }
            else
            {
                p = p + 2 * (dx - dy);
                x = x + sign(x2 - x1);
            }
            y = y + sign(y2 - y1);
            i++;
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

//Function to draw line on output window.
void MainWindow::drawLine2(int x1, int y1, int x2, int y2)
{
    float dx, dy, p;
    float x, y;
    float i = 0;
    x = x1;
    y = y1;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    if (dx >= dy)
    {
        p = 2 * dy - dx;
        while (i <= dx)
        {
            img1.setPixel(x, y, color.rgb());
            if (p < 0)
            {
                p = p + 2 * dy;
            }
            else
            {
                p = p + 2 * (dy - dx);
                y = y + sign(y2 - y1);
            }
            x = x + sign(x2 - x1);
            i++;
        }
    }
    else
    {

        p = 2 * dx - dy;
        while (i <= dy)
        {
            img1.setPixel(x, y, color.rgb());
            if (p < 0)
            {
                p = p + 2 * dx;
            }
            else
            {
                p = p + 2 * (dx - dy);
                x = x + sign(x2 - x1);
            }
            y = y + sign(y2 - y1);
            i++;
        }
    }
    ui->label_7->setPixmap(QPixmap::fromImage(img1));
}

//Function to return -1 OR +1 i.e. to determine sign.
int MainWindow::sign(int x)
{
    if (x < 0)
        return -1;
    else
        return 1;
}

//Button to selecct colour.
void MainWindow::on_pushButton_3_clicked()
{
    color = QColorDialog::getColor();
}

//Function to determine region code of line.
void MainWindow::code(int c[], float x, float y)
{
    //LRTB
    int X1 = ui->textEdit->toPlainText().toInt();
    int Y1 = ui->textEdit_2->toPlainText().toInt();
    int X2 = ui->textEdit_3->toPlainText().toInt();
    int Y2 = ui->textEdit_4->toPlainText().toInt();
    if (x < X1)
    {
        c[0] = 1;
    }
    else
    {
        c[0] = 0;
    }

    if (x > X2)
    {
        c[1] = 1;
    }
    else
    {
        c[1] = 0;
    }

    if (y < Y1)
    {
        c[2] = 1;
    }
    else
    {
        c[2] = 0;
    }

    if (y > Y2)
    {
        c[3] = 1;
    }
    else
    {
        c[3] = 0;
    }
}

//Function to clip the lines.
void MainWindow::clip(int c[], int d[], float &x, float &y, float m)
{
    int i = 0; //iterating variable.

    //Digonal co-ordinates of window.
    int X1 = ui->textEdit->toPlainText().toInt();
    int Y1 = ui->textEdit_2->toPlainText().toInt();
    int X2 = ui->textEdit_3->toPlainText().toInt();
    int Y2 = ui->textEdit_4->toPlainText().toInt();

    for (i = 0; i < 4; i++)
    {
        //Line is completely outside the window.
        if (c[i] != 0 && d[i] != 0)
        {
            flag = false;
            //            break;
        }
        if (flag)
        {
            //According to region codes, changing co-ordinates.
            if (c[0] != 0)
            {
                y = m * (X1 - x) + y;
                x = X1;
            }
            else if (c[1] != 0)
            {
                y = m * (X2 - x) + y;
                x = X2;
            }
            else if (c[2] != 0)
            {
                x = ((Y1 - y) / m) + x;
                y = Y1;
            }
            else if (c[3] != 0)
            {
                x = ((Y2 - y) / m) + x;
                y = Y2;
            }
        }
    }
}

//Function to handle mouse press events.
void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if (start)
    {
        if (ev->button() == Qt::RightButton)
        {
            QMessageBox msg;
            msg.information(0, "Information", "Mouse functionality disabled");
            start = false;

            //Activating/Deactivating buttons and text fields.
            ui->pushButton->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_5->setEnabled(false);
            ui->textEdit->setEnabled(true);
            ui->textEdit_2->setEnabled(true);
            ui->textEdit_3->setEnabled(true);
            ui->textEdit_4->setEnabled(true);
        }
        else
        {
            int p, q;
            do
            {
                p = ev->pos().x();
                q = ev->pos().y();
            } while (p > 500 || q > 600);

            a[ver] = p;
            c[ver] = q;

            if ((ver % 2 == 1))
            {
                drawLine1(a[ver], c[ver], a[ver - 1], c[ver - 1]);
            }
            ver++;
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    //Taking input into variables.
    int X1 = ui->textEdit->toPlainText().toInt();
    int Y1 = ui->textEdit_2->toPlainText().toInt();
    int X2 = ui->textEdit_3->toPlainText().toInt();
    int Y2 = ui->textEdit_4->toPlainText().toInt();


    //Drawing window.
    drawLine2(X1, Y1, X2, Y1);
    drawLine2(X2, Y1, X2, Y2);
    drawLine2(X2, Y2, X1, Y2);
    drawLine2(X1, Y2, X1, Y1);

    for (int i = 0; i < ver; i = i + 2)
    {
        flag = true;
        int q[4], s[4];
        code(q, a[i], c[i]);
        code(s, a[i + 1], c[i + 1]);
        test(q, s);
        if (flag == false)
        {
            continue;
        }
        float l = float((c[i + 1] - c[i]) / (a[i + 1] - a[i]));
        clip(q, s, a[i], c[i], l);
        clip(s, q, a[i + 1], c[i + 1], l);
        drawLine2(a[i], c[i], a[i + 1], c[i + 1]);
    }
}

//Function to check if the line is completely outside the polygon.
void MainWindow::test(int c[], int d[])
{
    int i = 0;

    for (i = 0; i < 4; i++)
    {
        if (c[i] != 0 && d[i] != 0)
        {
            flag = false;
        }
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    //clear button
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    start = false;
    flag = true;
    ver = 0;
    for (int i = 0; i < 100; i++)
    {
        a[i] = -1;
        c[i] = -1;
    }
    for (int x = 0; x < height; ++x)
    {
        for (int y = 0; y < width; ++y)
        {
            //Each pixel is set to black colour
            img.setPixel(x, y, qRgb(0, 0, 0));
            img1.setPixel(x, y, qRgb(0, 0, 0));
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label_7->setPixmap(QPixmap::fromImage(img1));

    //Clearing text fields.
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->textEdit_4->clear();
}

void MainWindow::on_pushButton_5_clicked()
{
    //Draw line
    ui->pushButton_3->setEnabled(true);
    QMessageBox msg;
    msg.information(0, "Infromation", "Mouse press functionality enabled");
    start = true;
}
