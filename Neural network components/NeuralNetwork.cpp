//
// Created by macie on 23/02/2024.
//

#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(vector<Vector> biases, vector<Matrix> weights, Vector last) {
    this->biases = std::move(biases);
    this->weights = std::move(weights);
    this->last = std::move(last);
}

int NeuralNetwork::output(Vector input) {
    for(int i = 0; i < weights.size(); i++){
        input = (weights.at(i)*input + biases.at(i)).ReLU();
    }
    return input * last;
}
