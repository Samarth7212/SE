#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <QColor>
#include <QColorDialog>

QImage img(500, 500, QImage ::Format_RGB888); // Output screen

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 500; j++)
        {
            img.setPixel(i, j, qRgb(0, 0, 0)); // Intitially, setting to black
        }
    }
    ui->label->setPixmap(QPixmap ::fromImage(img)); // Pixel map set
}

MainWindow::~MainWindow()
{
    delete ui;
}

QColor color; // Colour selected by user.

void MainWindow::DDAline(int x1, int y1, int x2, int y2) // Line drawing algorithm
{
    int Dx = x2 - x1, Dy = y2 - y1, step, k; // Change in x and y.
    float xin, yin, x = x1, y = y1;          // Necessary variables

    // Determining step count
    if (abs(Dx) > abs(Dy))
    {
        step = abs(Dx);
    }
    else
    {
        step = abs(Dy);
    }

    // Determining increment values.
    xin = Dx / (float)step;
    yin = Dy / (float)step;

    img.setPixel(round(x), round(y), color.rgb());  // Setting up pixel.
    ui->label->setPixmap(QPixmap ::fromImage(img)); // Setting pixmap

    for (k = 0; k < step; k++) // Iterating step-times.
    {
        x = x + xin;                                    // Incrementing X
        y = y + yin;                                    // Incrementing Y
        img.setPixel(round(x), round(y), color.rgb());  // Setting up pixel
        ui->label->setPixmap(QPixmap ::fromImage(img)); // Setting pixMap
    }
}

void MainWindow::koch(int x1, int y1, int x2, int y2, int iter) // Koch function
{
    // Declare required variables
    int x3, y3, x4, y4, x, y;
    const float pi = 3.1415927;  // Pi value
    float angle = 60 * pi / 180; // Angle converted to radians.

    // Divide the input line in three equal parts
    x3 = (2 * x1 + x2) / 3;
    y3 = (2 * y1 + y2) / 3;
    x4 = (2 * x2 + x1) / 3;
    y4 = (2 * y2 + y1) / 3;

    // Calculate the coordinate of the apex of the mid-part of line
    x = x3 + (x4 - x3) * cos(angle) + (y4 - y3) * sin(angle);
    y = y3 - (x4 - x3) * sin(angle) + (y4 - y3) * cos(angle);

    if (iter > 1) // If there are moe than one iterations then call koch function for each sub-divided line
    {
        koch(x1, y1, x3, y3, iter - 1);
        koch(x3, y3, x, y, iter - 1);
        koch(x, y, x4, y4, iter - 1);
        koch(x4, y4, x2, y2, iter - 1);
    }
    else // Display all the calculated points
    {
        DDAline(x1, y1, x3, y3);
        DDAline(x3, y3, x, y);
        DDAline(x, y, x4, y4);
        DDAline(x4, y4, x2, y2);
    }
}

void MainWindow::on_pushButton_clicked() // Clear Button
{
    // Iterating 500*500 times
    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 500; j++)
        {
            img.setPixel(i, j, qRgb(0, 0, 0)); // Setting black screen
        }
    }
    ui->label->setPixmap(QPixmap ::fromImage(img)); // Setting pixMap

    // Clearing input fields.
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->textEdit_4->clear();
    ui->textEdit_5->clear();
}

void MainWindow::on_pushButton_2_clicked() // Draw kotch curve
{
    int x1, y1, x2, y2, iter; // Necessary variables

    // User inputs
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui->textEdit_4->toPlainText().toInt();
    iter = ui->textEdit_5->toPlainText().toInt();

    koch(x1, y1, x2, y2, iter); // Calling Koch function
}

void MainWindow::on_pushButton_3_clicked()
{
    color = QColorDialog::getColor(); // Storing the given value in color variable.
}
