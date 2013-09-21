#include "Alpha.h"

#include <QVector>
#include <QDebug>
#include <QtCore/qmath.h>

Alpha::Alpha() {
    Q = 79 * 1.6e-19;
    q_alpha = 2 * 1.6e-19;
    e0 = 8.85e-12;
    m_alpha = 4 * 1.67e-27;
}

Alpha::~Alpha() {

}

void Alpha::euler(double* t0, double* x, double* y, double* v_x, double* v_y, double t, double dt, const std::function<double(double, double)> &f) {
    double t_end = t - dt;
    while (*t0 < t_end) {
        *x = *x + dt * *v_x;
        *v_x = *v_x + dt * f(*x, *y) * (*x / (qSqrt(*x * *x + *y * *y)));
        *y = *y + dt * *v_y;
        *v_y = *v_y + dt * f(*x, *y) * (*y / (qSqrt(*x * *x + *y * *y)));
        *t0 = *t0 + dt;
    }
    *x = *x + *v_x * (t - *t0);
    *v_x = *v_x + f(*x, *y) * (t - *t0) * (*x / (qSqrt(*x * *x + *y * *y)));
    *y = *y + *v_y * (t - *t0);
    *v_y = *v_y + f(*x, *y) * (t - *t0) * (*y / (qSqrt(*x * *x + *y * *y)));
}

void Alpha::calculate(double x, double y, short alpha, double v, double t1, double DeltaT, double dt, QVector<double>& result_x, QVector<double>& result_y) {
    double t2;
    double alpha_in_radian = alpha * 3.1415 / 180;
    double v_x = v * qCos(alpha_in_radian), v_y = v * qSin(alpha_in_radian);
    t2 = DeltaT;

    qDebug("Start position: x == %.02f y == %.02f", x, y);

    result_x.push_back(x);
    result_y.push_back(y);

    while (t2 < 20.) {
        Alpha::euler(&t1, &x, &y, &v_x, &v_y, t2, dt, [this](double x, double y) {
                return Q * q_alpha / (4 * 3.1415 * e0 * m_alpha * (x * x + y * y));
        });

        result_x.push_back(x);
        result_y.push_back(y);

        qDebug("New position: x == %.02f y == %.02f", x, y);

        t1 = t2; t2 = t2 + DeltaT;
    }



}
