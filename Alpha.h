#ifndef ALPHA_H
#define ALPHA_H

#include <QObject>
#include <functional>

class Alpha : public QObject {
    Q_OBJECT

    double Q;
    double q_alpha;
    double e0;
    double m_alpha;

    void euler(double* t0, double* x, double* y, double alpha, double v, double t, double dt, const std::function<double(double, double)> &f);

public:
    Alpha();
    ~Alpha();
    void calculate(double x, double y, unsigned short alpha, double v, double t1, double DeltaT, double dt, QVector<double>& result_x, QVector<double>& result_y);
};

#endif
