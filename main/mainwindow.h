
#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include <QtWidgets/QMainWindow>
#include <QImage>
#include <QGraphicsScene>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindowClass ui;
    QGraphicsScene scene;

    QImage changeRGB(QImage inputImg, float gain_r, float gain_g, float gain_b, float offset_r, float offset_g, float offset_b);

protected:
    void closeEvent(QCloseEvent *e);
    void paintEvent(QPaintEvent *e);

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

};

#endif // MAIN_WINDOW_H_
