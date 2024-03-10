//
// Created by macie on 23/02/2024.
//

#include "NeuralNetwork.h"
#include "TrainingSet.h"

NeuralNetwork::NeuralNetwork(vector<Layer> layers, double(*activation)(double),double(*derivative)(double)) : layers(std::move(layers)), activation(activation), derivative(derivative) {}

Vector NeuralNetwork::output(Vector input) {
    for (Layer& l: layers) {
        input = l.output(input,activation);
    }
    return input;
}

void NeuralNetwork::backProp(TrainingSet trainingSet, double learningRate) {
    for (int i = 0; i < trainingSet.getInput()->size(); i++) {
        this->output(trainingSet.getInput()->at(i));
        Vector derivatives({});
        for (int j = 0; j < trainingSet.getOutput()->at(i).getSize(); j++) {
            double d = layers.back().getNodes().getComponent(j);
            double c = trainingSet.getOutput()->at(i).getComponent(j);
            derivatives.addEntry(
                    2 * (layers.back().getNodes().getComponent(j)) - trainingSet.getOutput()->at(i).getComponent(j));
        }
        for(int j = layers.size()-1; j >=0;j--){
            Vector prev({});
            if(j == 0) prev = trainingSet.getInput()->at(i);
            else prev = layers.at(j-1).getNodes();
            derivatives = layers.at(j).update(derivatives, prev, learningRate, derivative);
        }
    }
}
