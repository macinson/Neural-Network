//
// Created by macie on 23/02/2024.
//

#include "NeuralNetwork.h"

#include <algorithm>
#include <iostream>

#include "TrainingSet.h"
#include "../Common/UsefulMethods.h"

NeuralNetwork::NeuralNetwork(vector<Layer> layers,vector<Activation*> activations) : layers(UsefulMethods::zip(std::move(layers), std::move(activations))) {}

Vector NeuralNetwork::output(Vector input) {
    for (pair<Layer,Activation*>& p: layers) {
        input = p.second->forward(p.first.forward(input));
    }
    return input;
}

void NeuralNetwork::backward(Vector upstream) {
    for(int i = layers.size()-1; i >=0; i--) {
        upstream = layers.at(i).first.backward(layers.at(i).second->backward(upstream));
    }
}

void NeuralNetwork::optimiserStep(double alpha) {
    for(pair<Layer,Activation*>& p : layers) {
        p.first.update(alpha);
    }
}

pair<vector<double>, vector<double>> NeuralNetwork::train(TrainingSet& trainingSet, double alpha, Cost* cost, int maxEpochs = 100) {
    vector<double> losses{};
    vector<double> accuracies{};
    for(int epoch = 0; epoch < maxEpochs; epoch++) {
        cout << "Epoch: " << epoch << endl;
        Vector epochLoss({});
        Vector accuracy({});
        for(int i = 0; i < trainingSet.size(); i++) {
            Vector x = trainingSet.getInput()->at(i);
            Vector y = trainingSet.getOutput()->at(i);

            Vector y_pred = output(x);

            if(isnan(y_pred.getComponent(0))) {
                cout << "Nan" << endl;
            }

            auto[loss, grad] = cost->calc(y,y_pred);
            epochLoss.addEntry(loss);

            vector<double> y_true_components = y.getComponents();
            vector<double> y_pred_components = y_pred.getComponents();

            int y_true_label = distance(y_true_components.begin(),max_element(y_true_components.begin(), y_true_components.end()));
            int y_pred_label = distance(y_pred_components.begin(),max_element(y_pred_components.begin(), y_pred_components.end()));

            if(y_pred_label == y_true_label) accuracy.addEntry(1);
            else accuracy.addEntry(0);

            backward(grad);
            optimiserStep(alpha);
        }
        losses.push_back(1.0 * epochLoss.sum()/epochLoss.getSize());
        accuracies.push_back(1.0 * accuracy.sum()/accuracy.getSize());
    }
    return make_pair(losses,accuracies);
}


