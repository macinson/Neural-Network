//
// Created by macie on 27/02/2024.
//

#include "Layer.h"

#include <utility>
#include "../Common/UsefulMethods.h"

Layer::Layer(int in_f, int out_f, const function<double()>& weightInit, const function<double()>& biasInit): inWeights(Matrix(out_f,in_f,weightInit)), biases(Vector(out_f, biasInit)), nodes(Vector({})), weightGrad({}), biasGrad({}), weightInit(weightInit), biasInit(biasInit) {}


Vector Layer::forward(Vector input) {
    nodes = std::move(input);
    return inWeights * nodes + biases;
}

Vector Layer::backward(const Vector& upstream) {
    weightGrad = Matrix{{upstream}} * Matrix{{nodes}}.transpose();
    biasGrad = upstream;

    return inWeights.transpose() * upstream;
}

void Layer::update(double alpha) {
    inWeights = inWeights - (weightGrad * alpha);
    biases = biases - (biasGrad * alpha);
}

