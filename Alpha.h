#ifndef ALPHA_H
#define ALPHA_H

#include <QObject>
#include <QVector>

class Alpha : public QObject {
    Q_OBJECT
public:
    Alpha();
    ~Alpha();
    void calculate(double x, double y, QVector<double> &result_x, QVector<double> &result_y);
};

#endif
