#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QVector<double> x(101), y(101);
    for (int i=0; i<101; ++i)
    {
        x[i] = i/50.0 - 1;
        y[i] = x[i]*x[i];
    }

    ui->customPlot->addGraph();
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    QCPCurve *newCurve = new QCPCurve(ui->customPlot->xAxis, ui->customPlot->yAxis);
    newCurve->setName("Test");
    newCurve->setData(x, y);
    ui->customPlot->xAxis->setRange(x[0], x[100]);
    ui->customPlot->yAxis->setRange(0, y[100]);
    ui->customPlot->rescaleAxes(true);
    ui->customPlot->replot();
    ui->customPlot->removePlottable(ui->customPlot->plottable());

}

MainWindow::~MainWindow()
{
    delete ui;
}
