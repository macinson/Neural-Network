//
// Created by macie on 27/02/2024.
//

#include "Layer.h"

Layer::Layer(Matrix inWeights, Vector biases): inWeights(std::move(inWeights)), biases(std::move(biases)), nodes({}) {
    this->nodes = Vector(vector<double>(biases.getSize(),0.0));
}

Vector Layer::output(Vector input) {
    nodes = inWeights* input + biases;
    return nodes.ReLU();
}
