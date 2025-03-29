//
// Created by macie on 29/03/2025.
//

#include "ReLu.h"

ReLu::ReLu(double alpha) : Activation(), alpha(alpha){
}

Vector ReLu::forward(Vector v) {
    cache = new Vector(v.apply([&](double x){return (x > 0) ?  x : alpha * x;}));
    return *cache;
}

Vector ReLu::backward(Vector v) {
    return v * cache->apply([&](double x){return (x > 0) ?  1 : alpha;});
}


