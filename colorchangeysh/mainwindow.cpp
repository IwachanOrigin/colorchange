
#include "mainwindow.h"
#include <cmath>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QColor>

const float PI = 3.141592;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.graphicsView->setScene(&scene);
    QImage inputImg(":/MainWindow/test.jpg");
    QImage rtnImg = this->changeYSH(inputImg, 1.0, 1.3, 120);
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

QImage MainWindow::changeYSH(QImage inputImg, float gain_y, float gain_s, float offset_h)
{
    QImage rtnImg(inputImg.width(), inputImg.height(), inputImg.format());

    for (int i = 0; i < inputImg.height(); i++)
    {
        for (int j = 0; j < inputImg.width(); j++)
        {
            QColor currColor(inputImg.pixel(j, i));
            int r = (int)currColor.red();
            int g = (int)currColor.green();
            int b = (int)currColor.blue();
            // Convert to Y, CR, CB
            double y = 0.299 * r + 0.587 * g + 0.114 * b;
            double cr = r - y;
            double cb = g - y;
            // Convert to Y, Sat, Hue
            double sat = sqrt((float)cr * (float)cr + (float)cb * (float)cb);
            double hue = 0.0;
            if (sat > 0.0)
            {
                hue = atan2((double)cr, (double)cb) * 180.0 / PI;
                if (hue < 0)
                {
                    hue = hue + 360.0;
                }
            }
            else
            {
                hue = 0.0;
            }

            //  to Y, Sat, Hue
            y *= gain_y;
            sat *= gain_s;
            if (y == 0)
            {
                sat = 0;
            }
            hue += offset_h;
            if (hue > 360)
            {
                hue -= 360;
            }
            if (hue < 0)
            {
                hue += 360;
            }

            // Convert to Y, CR, CB
            double rad = PI * hue / 180.0;
            cr = sat * sin(rad);
            cb = sat * cos(rad);

            // Convert to R, G, B
            r = (int)(y + cr);
            if (r > 255)
            {
                r = 255;
            }
            if (r < 0)
            {
                r = 0;
            }

            g = (int)(y - 0.299 / 0.587 * cr - 0.114 / 0.587 * cb);
            if (g > 255)
            {
                g = 255;
            }
            if (g < 0)
            {
                g = 0;
            }

            b = (int)(y + cb);
            if (b > 255)
            {
                b = 255;
            }
            if (b < 0)
            {
                b = 0;
            }
            rtnImg.setPixel(j, i, qRgb(r, g, b));
        }
    }
    return rtnImg;
}
