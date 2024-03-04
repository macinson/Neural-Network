//
// Created by macie on 23/02/2024.
//

#include "NeuralNetwork.h"
#include "TrainingSet.h"

NeuralNetwork::NeuralNetwork(vector<Layer> layers):layers(std::move(layers)) {}

Vector NeuralNetwork::output(Vector input) {
    for(Layer l : layers){
        input = l.output(input);
    }
    return input;
}

void NeuralNetwork::backProp(TrainingSet trainingSet) {
    for(const Vector& input : trainingSet.getInput()){
        this->output(input);
    }
}
