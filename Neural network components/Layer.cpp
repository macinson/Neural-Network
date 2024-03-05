//
// Created by macie on 27/02/2024.
//

#include "Layer.h"
#include "../Common/UsefulMethods.h"

Layer::Layer(Matrix inWeights, Vector biases): inWeights(std::move(inWeights)), biases(std::move(biases)), nodes({}) {
    this->nodes = Vector(vector<double>(biases.getSize(),0.0));
}

Vector Layer::output(Vector input) {
    nodes = inWeights* input + biases;
    return nodes.ReLU();
}

Vector Layer::update(Vector derivatives, Vector prev, double learningRate) {
    Matrix weightUpdates({});
    Vector thisLayerDerivatives({});
    for(int i = 0; i < this->nodes.getSize(); i++){
        thisLayerDerivatives.addEntry(UsefulMethods::ReLUDerivative(nodes.getComponent(i)) *derivatives.getComponent(i));
    }
    for(int i = 0; i < inWeights.getN(); i++){
        Vector column({});
        for(int j = 0; j < inWeights.getM(); j++){
            column.addEntry(prev.getComponent(i) * thisLayerDerivatives.getComponent(j));
        }
        weightUpdates.addColumn(column);
    }
    Vector next({});
    for(int i = 0; i < inWeights.getN(); i++){
        double mean = 0.0;
        for(int j = 0; j < inWeights.getM(); j++){
            mean += inWeights.getColumn(i).getComponent(j) * thisLayerDerivatives.getComponent(j);
        }
        mean /= inWeights.getM() * 1.0;
        next.addEntry(mean);
    }
    inWeights = inWeights + ((weightUpdates * (-1.0)) * learningRate);
    biases = biases + thisLayerDerivatives * (-1.0) * learningRate;
    return next;
}
