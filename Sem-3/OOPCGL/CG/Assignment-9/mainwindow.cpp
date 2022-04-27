#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QColorDialog"

#include <QMouseEvent>
#include <QtDebug>
#include <QTime>
#include <QMessageBox>

QImage img(600, 600, QImage::Format_RGB888);
QColor color;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);                     // Setting up user interface.
    dda(-300, 0, 300, 0, qRgb(255, 0, 0)); // X axis
    dda(0, -300, 0, 300, qRgb(255, 0, 0)); // Y axis
    start = true;                          // Condition for mouse event
    ver = 0;                               // Vertex count
}

MainWindow::~MainWindow()
{
    delete ui;
}

class Matrix
{
public:
    float a[2][3];              // To store x1, y1 co-ordinates.
    float b[3][3];              // To store required matrix.
    Matrix operator*(Matrix ob) // Overloading multiplication operator.
    {
        Matrix temp;                // Creating temporary object.
        for (int i = 0; i < 2; i++) // Iterating 2 times for column.
        {
            for (int j = 0; j < 3; j++) // Iterating 3 times for row.
            {
                temp.a[i][j] = 0; // Setting value to zero.
                for (int k = 0; k < 3; k++)
                {
                    temp.a[i][j] += a[i][k] * ob.b[k][j]; // Creating result element for the matrix.
                }
            }
        }
        return temp; // Returning result.
    }
};

void MainWindow::ClearScreen()
{
    // clearing the screen
    for (int x = 0; x < 600; ++x) // Iterating in horizontal.
    {
        for (int y = 0; y < 600; ++y) // Iterating in vertical.
        {
            img.setPixel(x, y, qRgb(0, 0, 0)); // Setting pixel to black colour.
        }
    }
    // Re-drawing Co-ordinate axes
    dda(-300, 0, 300, 0, qRgb(255, 0, 0)); // X-axis
    dda(0, -300, 0, 300, qRgb(255, 0, 0)); // Y-axis
}

void MainWindow::on_pushButton_clicked() // translation
{
    ClearScreen(); // Clearing original figure.
    tx = ui->textEdit->toPlainText().toFloat();
    ty = ui->textEdit_2->toPlainText().toFloat();

    for (int i = 0; i < ver; i++)
    {
        Matrix M, N, ans; // Creating matrices
        /*
            x1 y1   1 0 Tx
            x2 y2   0 1 Ty
            1  1    0 0 1
        */
        float P[2][3] = {{a[i], b[i], 1}, {a[i + 1], b[i + 1], 1}}; // To store x1, y1, x2, y2
        float T[3][3] = {{1, 0, 0}, {0, 1, 0}, {tx, -ty, 1}};       // To store translation value.
        for (int i = 0; i < 2; i++)                                 // Iterating 2 times for column.
        {
            for (int j = 0; j < 3; j++) // Iterating 3 times for row.
            {
                M.a[i][j] = P[i][j]; // Copying value.
            }
        }
        for (int i = 0; i < 3; i++) // Iterating 3 times for column.
        {
            for (int j = 0; j < 3; j++) // Iterating 3 times for row.
            {
                N.b[i][j] = T[i][j]; // Copying value.
            }
        }
        ans = M * N;                                                          // Multiplying M and N to get answer
        dda(ans.a[0][0], ans.a[0][1], ans.a[1][0], ans.a[1][1], color.rgb()); // Drawing that answer to the screen.
    }
}

void MainWindow::on_pushButton_2_clicked() // scaling
{
    ClearScreen(); // Clearing original figure.
    sx = ui->textEdit_3->toPlainText().toFloat();
    sy = ui->textEdit_4->toPlainText().toFloat();

    for (int i = 0; i < ver; i++)
    {
        Matrix M, N, ans;                                           // Creating matrices
        float P[2][3] = {{a[i], b[i], 1}, {a[i + 1], b[i + 1], 1}}; // To store x1, y1, x2, y2
        float S[3][3] = {{sx, 0, 0}, {0, sy, 0}, {0, 0, 1}};        // To store scaling value.
        for (int i = 0; i < 2; i++)                                 // Iterating 2 times for column.
        {
            for (int j = 0; j < 3; j++) // Iterating 3 times for row.
            {
                M.a[i][j] = P[i][j]; // Copying value.
            }
        }
        for (int i = 0; i < 3; i++) // Iterating 3 times for column.
        {
            for (int j = 0; j < 3; j++) // Iterating 3 times for row.
            {
                N.b[i][j] = S[i][j]; // Copying value.
            }
        }
        ans = M * N;                                                          // Multiplying M and N to get answer
        dda(ans.a[0][0], ans.a[0][1], ans.a[1][0], ans.a[1][1], color.rgb()); // Drawing that answer to the screen.
    }
}

void MainWindow::on_pushButton_3_clicked() // rotation
{
    ClearScreen(); // Clearing original figure.
    x = ui->textEdit_5->toPlainText().toFloat();
    x *= 3.142 / 180; // Converting from degree to radian.

    for (int i = 0; i < ver; i++)
    {
        Matrix M, N, ans;                                                                                       // Creating matrices
        float P[2][3] = {{a[i], b[i], 1}, {a[i + 1], b[i + 1], 1}};                                             // To store x1, y1, x2, y2
        float R[3][3] = {{(float)cos(x), ((float)(-sin(x))), 0}, {(float)sin(x), (float)cos(x), 0}, {0, 0, 1}}; // To store rotation value.
        for (int i = 0; i < 2; i++)                                                                             // Iterating 2 times for column.
        {
            for (int j = 0; j < 3; j++) // Iterating 3 times for row.
            {
                M.a[i][j] = P[i][j]; // Copying value.
            }
        }
        for (int i = 0; i < 3; i++) // Iterating 3 times for column.
        {
            for (int j = 0; j < 3; j++) // Iterating 3 times for row.
            {
                N.b[i][j] = R[i][j]; // Copying value.
            }
        }
        ans = M * N;                                                          // Multiplying M and N to get answer
        dda(ans.a[0][0], ans.a[0][1], ans.a[1][0], ans.a[1][1], color.rgb()); // Drawing that answer to the screen.
    }
}

void MainWindow::dda(float x1, float y1, float x2, float y2, QColor color)
{
    // Giving necessary shift to work with axes.
    x1 += 300;
    y1 += 300;
    x2 += 300;
    y2 += 300;

    float dx, dy, length, x, y; // Necessary variables declared.

    // Change in x and y.
    dx = x2 - x1;
    dy = y2 - y1;

    // Deciding decision parameter i.e. length
    if (abs(dx) > abs(dy))
    {
        length = abs(dx);
    }
    else
    {
        length = abs(dy);
    }

    // Dividing by parameter
    dx = dx / length;
    dy = dy / length;
    x = x1;
    y = y1;
    int i = 0;
    img.setPixel(x, y, color.rgb()); // Setting pixel

    while (i < length) // Drawing line
    {
        // Incrementing variables.
        x = x + dx;
        y = y + dy;
        img.setPixel(x, y, color.rgb());
        i++;
    }
    ui->label_6->setPixmap(QPixmap::fromImage(img)); // Showing changes on the output screen.
}

void MainWindow::mousePressEvent(QMouseEvent *ev) // To handle mouse events.
{
    if (start)
    {
        // Recording x and y values.
        int p = ev->pos().x();
        int q = ev->pos().y();

        // Subtracting to match with axes.
        a[ver] = p - 300;
        b[ver] = q - 300;

        if (ev->button() == Qt::RightButton) // If right button is pressed, complete the polygon
        {
            dda(a[0], b[0], a[ver - 1], b[ver - 1], color.rgb()); // Drawing last line.
            start = false;                                        // Setting condtion as false.
        }
        else // Keep on drawing as per input.
        {
            if (ver > 0)
            {
                dda(a[ver], b[ver], a[ver - 1], b[ver - 1], color.rgb());
            }
        }
        ver++;
    }
    // Last co-ordinate is set equal to first co-ordinate.
    a[ver] = a[0];
    b[ver] = b[0];
}

void MainWindow::on_pushButton_4_clicked() // Clear button
{
    ClearScreen(); // Clearing screen.
    clearFields(); // Clearing input fields.
    start = true;  // Setting condition as true.
    ver = 0;       // Vertex count is set to zero.
}

void MainWindow::clearFields() // To clear all 5 input fields.
{
    // Clear cleans the input field.
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->textEdit_4->clear();
    ui->textEdit_5->clear();
}

void MainWindow::on_pushButton_5_clicked() // To select colour as per desire.
{
    color = QColorDialog::getColor(); // Storing the given value in color variable.
}

void MainWindow::on_pushButton_6_clicked()
{
    // Drawing Equilateral triangle
    ver = 3; // Vertices are 3
    a[0] = 0;
    b[0] = -250;
    a[1] = 125;
    b[1] = 0;
    a[2] = -125;
    b[2] = 0;
    a[3] = a[0], b[3] = b[0];

    // Drawing 3 lines.
    dda(a[0], b[0], a[1], b[1], color.rgb());
    dda(a[2], b[2], a[1], b[1], color.rgb());
    dda(a[0], b[0], a[2], b[2], color.rgb());
}

void MainWindow::on_pushButton_7_clicked()
{
    // Drawing Rhombus
    ver = 4; // Vertices are 4.
    a[0] = 0;
    b[0] = 0;
    a[1] = +100;
    b[1] = -100;
    a[2] = +300;
    b[2] = -100;
    a[3] = 200;
    b[3] = 0;
    a[4] = a[0], b[4] = b[0];

    // Drawing 4 lines.
    dda(a[0], b[0], a[1], b[1], color.rgb());
    dda(a[2], b[2], a[1], b[1], color.rgb());
    dda(a[3], b[3], a[2], b[2], color.rgb());
    dda(a[3], b[3], a[4], b[4], color.rgb());
}
