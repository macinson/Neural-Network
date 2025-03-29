//
// Created by macie on 28/03/2025.
//

#include "SoftMax.h"
#include <cmath>

#include "../Common/Matrix.h"

SoftMax::SoftMax() : Activation(){

}


Vector SoftMax::forward(Vector v) {
    Vector e = v.apply([](double x){return exp(x);});
    cache = new Vector(e/e.sum());
    return *cache;
}

Vector SoftMax::backward(Vector v) {
    return (Matrix::diagonalize(*cache) - (Matrix{{*cache}}* Matrix{{*cache}}.transpose())) * v;
}

