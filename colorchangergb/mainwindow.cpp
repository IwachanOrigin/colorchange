
#include "mainwindow.h"
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QColor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.graphicsView->setScene(&scene);
    QImage inputImg(":/MainWindow/test.jpg");
    QImage rtnImg = this->changeRGB(inputImg, 1.2, 1.0, 0.8, 20, 0, -20);
    QGraphicsPixmapItem *image_item = new QGraphicsPixmapItem(QPixmap::fromImage(rtnImg));
    scene.addItem(image_item);
    ui.graphicsView->setScene(&scene);
}

void MainWindow::closeEvent(QCloseEvent* e)
{
}

void MainWindow::paintEvent(QPaintEvent *e)
{
}

QImage MainWindow::changeRGB(QImage inputImg, float gain_r, float gain_g, float gain_b, float offset_r, float offset_g, float offset_b)
{
    QImage rtnImg(inputImg.width(), inputImg.height(), inputImg.format());
    
    for (int i = 0; i < inputImg.height(); i++)
    {
        for (int j = 0; j < inputImg.width(); j++)
        {
            QColor currColor(inputImg.pixel(j, i));
            int r = (int)(currColor.red() * gain_r + offset_r);
            if (r > 255)
            {
                r = 255;
            }
            else if (r < 0)
            {
                r = 0;
            }

            int g = (int)(currColor.green() * gain_g + offset_g);
            if (g > 255)
            {
                g = 255;
            }
            else if (g < 0)
            {
                g = 0;
            }

            int b = (int)(currColor.blue() * gain_b + offset_b);
            if (b > 255)
            {
                b = 255;
            }
            else if (b < 0)
            {
                b = 0;
            }

            rtnImg.setPixel(j, i, qRgb(r, g, b));
        }
    }
    return rtnImg;
}
