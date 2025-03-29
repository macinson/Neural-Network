//
// Created by macie on 23/02/2024.
//

#ifndef CPP_NEURALNETWORK_H
#define CPP_NEURALNETWORK_H
#include <vector>
#include "../Common/Vector.h"
#include "../Common/Matrix.h"
#include "TrainingSet.h"
#include "Layer.h"
#include "../ActivationFunc/Activation.h"
#include "../CostFunc/Cost.h"

using namespace std;

class NeuralNetwork {
private:
    vector<pair<Layer,Activation*>> layers;
public:
    NeuralNetwork(vector<Layer> layers,vector<Activation*> activations);
    Vector output(Vector input);
    void backward(Vector);
    void optimiserStep(double);
    pair<vector<double>,vector<double>> train(TrainingSet&, double,Cost*, int);
};


#endif //CPP_NEURALNETWORK_H
