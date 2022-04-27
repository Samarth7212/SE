#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QColorDialog>
#include <QMessageBox>
#define height 600
#define width 600

QImage img(height, width, QImage::Format_RGB888);
QRgb rgb(qRgb(255, 255, 255));

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void Samarth::func(Ui::MainWindow *ui)
{
    float x1, y1, l, w, r;
    QMessageBox msg; //Object created to display warning msg
    if (ui->textEdit->toPlainText().isEmpty() || ui->textEdit_2->toPlainText().isEmpty() ||
        ui->textEdit_3->toPlainText().isEmpty() ||
        ui->textEdit_4->toPlainText().isEmpty() || !(ui->textEdit->toPlainText().toInt()) || !(ui->textEdit_2->toPlainText().toInt()) || !(ui->textEdit_3->toPlainText().toInt()) || !(ui->textEdit_4->toPlainText().toInt()))
    {
        msg.information(0, "Warning!!!", "Invalid input!!!\nPlease re-enter");
    }
    else if (ui->textEdit->toPlainText().toInt() && ui->textEdit_2->toPlainText().toInt() &&
                 ui->textEdit_3->toPlainText().toInt(),
             ui->textEdit_4->toPlainText().toInt())
    {
        x1 = ui->textEdit->toPlainText().toFloat();
        y1 = ui->textEdit_2->toPlainText().toFloat();
        l = ui->textEdit_3->toPlainText().toFloat();
        w = ui->textEdit_4->toPlainText().toFloat();

        //Rectangle
        DDALine(x1, y1, (x1 + l), y1, ui);
        DDALine((x1 + l), y1, (x1 + l), (y1 + w), ui);
        DDALine(x1, (y1 + w), (x1 + l), (y1 + w), ui);
        DDALine(x1, y1, x1, (y1 + w), ui);

        //Rhombus
        DDALine((x1 + (l / 2)), y1, (x1 + l), (y1 + (w / 2)), ui);
        DDALine((x1 + (l / 2)), y1, x1, (y1 + (w / 2)), ui);
        DDALine((x1 + l), (y1 + (w / 2)), (x1 + (l / 2)), (y1 + w), ui);
        DDALine(x1, (y1 + (w / 2)), (x1 + (l / 2)), (y1 + w), ui);

        //Circle
        r = ((l * w) / (2 * (sqrt((l * l) + (w * w)))));
        BresenhamCircle((x1 + (l / 2)), (y1 + (w / 2)), r, ui);
    }
    else
    {
        msg.information(0, "Warning!!", "Only numerical inputs are allowed!!!");
    }
}

void Samarth::BresenhamCircle(int xCenter, int yCenter, int radius, Ui::MainWindow *ui)
{
    const int P = 1e4;
    int x = 0;
    int y = radius;           //Radius is set to y
    int d = 3 - (2 * radius); //Decision parameter
    int ctr = 0;
    int arrX[P] = {0};
    int arrY[P] = {0};

    while (x <= y)
    {
        //decision parameter is checked and decided whether to decrement y OR not.
        if (d > 0)
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        else
        {
            d = d + (4 * x) + 6;
        }
        x++;

        img.setPixel(xCenter + x, yCenter + y, rgb);
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->show();
        delay(15);
        ctr++;
        arrX[ctr] = x;
        arrY[ctr] = y;
        //        img.setPixel(xCenter + x, yCenter - y, rgb);
        //        img.setPixel(xCenter - x, yCenter - y, rgb);
        //        img.setPixel(xCenter - x, yCenter + y, rgb);
        //        img.setPixel(xCenter + y, yCenter - x, rgb);
        //        img.setPixel(xCenter + y, yCenter + x, rgb);
        //        img.setPixel(xCenter - y, yCenter - x, rgb);
        //        img.setPixel(xCenter - y, yCenter + x, rgb);
    }
    for (int i = 0; i < ctr; i++)
    {
        img.setPixel(xCenter + arrX[i], yCenter - arrY[i], rgb);
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->show();
        delay(20);
    }

    for (int i = 0; i < ctr; i++)
    {
        img.setPixel(xCenter - arrX[i], yCenter - arrY[i], rgb);
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->show();
        delay(20);
    }

    for (int i = 0; i < ctr; i++)
    {
        img.setPixel(xCenter - arrX[i], yCenter + arrY[i], rgb);
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->show();
        delay(20);
    }

    for (int i = 0; i < ctr; i++)
    {
        img.setPixel(xCenter + arrY[i], yCenter - arrX[i], rgb);
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->show();
        delay(20);
    }

    for (int i = 0; i < ctr; i++)
    {
        img.setPixel(xCenter + arrY[i], yCenter + arrX[i], rgb);
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->show();
        delay(20);
    }

    for (int i = 0; i < ctr; i++)
    {
        img.setPixel(xCenter - arrY[i], yCenter - arrX[i], rgb);
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->show();
        delay(20);
    }

    for (int i = 0; i < ctr; i++)
    {
        img.setPixel(xCenter - arrY[i], yCenter + arrX[i], rgb);
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->show();
        delay(20);
    }
}

void Samarth::DDALine(float x1, float y1, float x2, float y2, Ui::MainWindow *ui)
{
    //dx dy values obtained.
    float dx = (x2 - x1);
    float dy = (y2 - y1);
    float Xinc, Yinc;

    //Steps count is decided, higher value is considered
    float step = (abs(dx) >= abs(dy)) ? abs(dx) : abs(dy);

    //Increment values for X and Y direction are obtained.
    Xinc = dx / step;
    Yinc = dy / step;

    //Starting point is taken in x and y variables.
    float x = x1, y = y1;
    int i = 1;

    //While loop to draw line pixel by pixel
    while (i <= step)
    {
        img.setPixel(x, y, rgb);
        x += Xinc;
        y += Yinc;
        i++;
        ui->label->setPixmap(QPixmap::fromImage(img));
        delay(15);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    for (int x = 0; x < height; ++x)
    {
        for (int y = 0; y < width; ++y)
        {
            img.setPixel(x, y, qRgb(0, 0, 0));
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_3_clicked()
{
    //This function allows to choose whichever colour we want.
    QRgb color(QColorDialog::getColor().rgb());
    rgb = color;
}

void Samarth::delay(int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs(millisecondsToWait);
    while (QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void MainWindow::on_pushButton_clicked()
{
    obj.func(ui);
}
