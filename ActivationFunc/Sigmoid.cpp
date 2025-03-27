//
// Created by macie on 26/03/2025.
//

#include "Sigmoid.h"

#include <cmath>

Vector Sigmoid::backward(Vector x) {
    if(x.getSize() == 0) return Vector({});
    vector<double> res {};
    for(double d : x.getComponents()) {
        double s = exp(-d)/ pow((1.0+ exp(-d)),2.0);
        res.push_back(s);
    }
    return Vector(res);
}

Vector Sigmoid::forward(Vector x) {
    if(x.getSize() == 0) return Vector({});
    vector<double> res {};
    for(double d : x.getComponents()) {
        double s = 1.0/(1.0+exp(-d));
        res.push_back(s);
    }
    cache = new Vector({});
    return Vector(res);
}

