//
// Created by macie on 30/03/2025.
//

#include "CrossEntropy.h"

#include <valarray>

pair<double, Vector> CrossEntropy::calc(Vector y_true, Vector y_pred) {
    Vector y_pred_clipped = y_pred.clip(1e-16,1-1e-16);

    double loss = -(y_true * y_pred_clipped.apply([](double x) {return log(x);})).sum();
    Vector grad = y_true/y_pred_clipped * -1;

    return {loss,grad};
}

