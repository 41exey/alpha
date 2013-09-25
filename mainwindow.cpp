#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qcustomplot.h"
#include "Alpha.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    isClicked = false;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonCalculate_clicked()
{
    if (isClicked)
        return;

    isClicked = true;
/*
    // Test QCustomPlot widget
    QVector<double> parabola_x(101), parabola_y(101);
    for (int i=0; i<101; ++i) {
        parabola_x[i] = i/50.0 - 1;
        parabola_y[i] = parabola_x[i]*parabola_x[i];
    }

    ui->customPlot->addGraph();
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    QCPCurve *newCurve = new QCPCurve(ui->customPlot->xAxis, ui->customPlot->yAxis);
    newCurve->setName("Test");
    newCurve->setData(parabola_x, parabola_y);
    ui->customPlot->xAxis->setRange(parabola_x[0], parabola_x[100]);
    ui->customPlot->yAxis->setRange(0, parabola_y[100]);
    ui->customPlot->rescaleAxes(true);
    ui->customPlot->replot();
    ui->customPlot->removePlottable(ui->customPlot->plottable());
    */

    // Alpha class
    Alpha * alpha = new Alpha();
    QVector<double> result_x, result_y;
    // Calculate a alpha particle
    //alpha->calculate(-50., 0., 2, 5., 20., 0, .5, .1 / .3, result_x, result_y);
    alpha->calculate(ui->doubleSpinBoxStartX->value(),
                     ui->doubleSpinBoxStartY->value(),
                     ui->doubleSpinBoxA->value(),
                     ui->doubleSpinBoxV->value(),
                     ui->doubleSpinBoxD->value(), 0, .5, .1 / .3, result_x, result_y);


    // Plot the result
    ui->customPlot->addGraph();
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    QCPCurve *newCurve = new QCPCurve(ui->customPlot->xAxis, ui->customPlot->yAxis);
    newCurve->setName("Test");
    newCurve->setData(result_x, result_y);
    ui->customPlot->xAxis->setRange(-60, 60);
    ui->customPlot->yAxis->setRange(-60, 60);
    ui->customPlot->rescaleAxes(true);
    ui->customPlot->replot();
    ui->customPlot->removePlottable(ui->customPlot->plottable());

    // Test position coordonates
    for(auto it_x = result_x.begin(), it_y = result_y.begin(); it_x != result_x.end(); ++it_x, ++it_y) {
        qDebug("Position now: x == %.02f y == %.02f", *it_x, *it_y);
    }


}
