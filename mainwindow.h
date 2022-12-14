#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Alpha.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    bool isClicked;
    QVector<double> result_x, result_y;
    Alpha alpha;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButtonCalculate_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
