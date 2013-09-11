#include "Alpha.h"

#include <QVector>
#include <QDebug>

Alpha::Alpha(){}
Alpha::~Alpha(){}

void Alpha::calculate(double x, double y, QVector<double> &result_x, QVector<double> &result_y) {
    qDebug("Start position: x == %.02f y == %.02f", x, y);
}
