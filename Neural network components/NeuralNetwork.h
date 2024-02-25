//
// Created by macie on 23/02/2024.
//

#ifndef CPP_NEURALNETWORK_H
#define CPP_NEURALNETWORK_H
#include <vector>
#include "../Common/Vector.h"
#include "../Common/Matrix.h"

using namespace std;


class NeuralNetwork {
private:
    vector<Vector> biases;
    vector<Matrix> weights;
    Vector last = Vector({});
public:
    NeuralNetwork(vector<Vector> biases, vector<Matrix> weights);
    Vector output(Vector input);
    void backProp();
};


#endif //CPP_NEURALNETWORK_H
