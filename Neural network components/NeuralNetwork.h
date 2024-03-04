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

using namespace std;


class NeuralNetwork {
private:
    vector<Layer> layers;
public:
    explicit NeuralNetwork(vector<Layer> layers);
    Vector output(Vector input);
    void backProp(TrainingSet trainingSet);
};


#endif //CPP_NEURALNETWORK_H
