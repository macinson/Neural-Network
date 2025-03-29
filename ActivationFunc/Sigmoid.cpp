//
// Created by macie on 26/03/2025.
//

#include "Sigmoid.h"

#include <cmath>

Sigmoid::Sigmoid() : Activation() {
}


Vector Sigmoid::backward(Vector x) {
    if(x.getSize() == 0) return Vector({});
    return x * (Vector(cache->getSize(), [](){return 1.0;}) - (*cache)) * (*cache);
}

Vector Sigmoid::forward(Vector x) {
    if(x.getSize() == 0) return Vector({});
    vector<double> res {};
    for(double d : x.getComponents()) {
        double s = 1.0/(1.0+exp(-d));
        res.push_back(s);
    }
    cache = new Vector(res);
    return *cache;
}

