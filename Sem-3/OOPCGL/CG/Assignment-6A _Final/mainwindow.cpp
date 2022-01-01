#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QTime>
#include <QMessageBox>
#define height 600
#define width 600

QImage img(height, width, QImage::Format_RGB888);
//Default white screen is created
QRgb rgb(qRgb(255, 255, 255));

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::on_pushButton_clicked()
{
    //This function allows to choose different colours.
    QRgb color(QColorDialog::getColor().rgb());
    rgb = color;
}

void Samarth::func(Ui::MainWindow *ui)
{
    QMessageBox msg; //Object created to display warning msg
    if (ui->textEdit->toPlainText().isEmpty() || ui->textEdit_2->toPlainText().isEmpty() ||
        ui->textEdit_3->toPlainText().isEmpty() || !(ui->textEdit->toPlainText().toInt()) || !(ui->textEdit_2->toPlainText().toInt()) || !(ui->textEdit_3->toPlainText().toInt()))
    {
        msg.information(0, "Warning!!!", "Invalid input!!!\nPlease re-enter");
    }
    else if (ui->textEdit->toPlainText().toInt() && ui->textEdit_2->toPlainText().toInt() &&
             ui->textEdit_3->toPlainText().toInt())
    {
        //Input given inside of Xc Yc and Radius is recorded
        int Xc = ui->textEdit->toPlainText().toInt();
        int Yc = ui->textEdit_2->toPlainText().toInt();
        int Rad = ui->textEdit_3->toPlainText().toInt();

        //Function calls to draw circle
        BresenhamCircle(Xc, Yc, Rad, ui);
        BresenhamCircle(Xc, Yc, Rad / 2, ui);

        //Float co-ordinates obtained for DDA line algorithm
        float x1 = Xc + Rad * (float)sqrt(3) / 2;
        float x2 = Xc - Rad * (float)sqrt(3) / 2;
        float y1 = Yc + Rad / 2;

        //Function calls to draw triangle.
        DDALine(x1, y1, x2, y1, ui);
        DDALine(x1, y1, Xc, (float)Yc - Rad, ui);
        BresenhamLine(x2, y1, (float)Xc, (float)Yc - Rad, ui);
    }
    else
    {
        msg.information(0, "Warning!!", "Only numerical inputs are allowed!!!");
    }
}

void Samarth::BresenhamLine(int x1, int y1, int x2, int y2, Ui::MainWindow *ui)
{
    //dx dy values obtained.
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;

    //Steps count is decided, higher value is considered
    steps = (abs(dx) >= abs(dy)) ? abs(dx) : abs(dy);

    //Increment values for X and Y direction are obtained.
    float xinc = dx / (float)steps;
    float yinc = dy / (float)steps;
    float x = x1;
    float y = y1;

    //For loop to draw line pixel by pixel
    for (int i = 0; i <= steps; i++)
    {
        img.setPixel(x, y, rgb);
        x += xinc;
        y += yinc;
        ui->label->setPixmap(QPixmap::fromImage(img));
        delay(15);
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
    //Octant-2
    for (int i = 0; i < ctr; i++)
    {
        img.setPixel(xCenter + arrX[i], yCenter - arrY[i], rgb);
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->show();
        delay(20);
    }

    //Octant-3
    for (int i = 0; i < ctr; i++)
    {
        img.setPixel(xCenter - arrX[i], yCenter - arrY[i], rgb);
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->show();
        delay(20);
    }

    //Octant-4
    for (int i = 0; i < ctr; i++)
    {
        img.setPixel(xCenter - arrX[i], yCenter + arrY[i], rgb);
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->show();
        delay(20);
    }

    //Octant-5
    for (int i = 0; i < ctr; i++)
    {
        img.setPixel(xCenter + arrY[i], yCenter - arrX[i], rgb);
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->show();
        delay(20);
    }

    //Octant-6
    for (int i = 0; i < ctr; i++)
    {
        img.setPixel(xCenter + arrY[i], yCenter + arrX[i], rgb);
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->show();
        delay(20);
    }

    //Octant-7
    for (int i = 0; i < ctr; i++)
    {
        img.setPixel(xCenter - arrY[i], yCenter - arrX[i], rgb);
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->show();
        delay(20);
    }

    //Octant-8
    for (int i = 0; i < ctr; i++)
    {
        img.setPixel(xCenter - arrY[i], yCenter + arrX[i], rgb);
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->show();
        delay(20);
    }
}

//Function to clear screen after plotting
void MainWindow::on_pushButton_2_clicked()
{
    for (int x = 0; x < height; ++x)
    {
        for (int y = 0; y < width; ++y)
        {
            //Each pixel is set to black colour
            img.setPixel(x, y, qRgb(0, 0, 0));
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_3_clicked()
{
    func(ui);
}

//Function to create a delay of given (parameter) millsecondsToWait
void Samarth::delay(int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs(millisecondsToWait);
    while (QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}
