//
// Created by macie on 27/03/2025.
//

#include "MSE.h"

#include <cmath>

pair<double, Vector> MSE::calc(Vector y_true, Vector y_pred) {
    double loss = 0.0;
    for(double d : (y_true - y_pred).getComponents()) {
        loss += pow(d,2);
    }
    return {loss,(y_pred - y_true) * 2};
}
