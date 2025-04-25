//
// Created by macie on 27/02/2024.
//

#ifndef CPP_LAYER_H
#define CPP_LAYER_H


#include "../Common/Vector.h"
#include "../Common/Matrix.h"

class Layer {
private:
    Matrix inWeights;
    Vector biases;
    Vector nodes;
    Matrix weightGrad;
    Vector biasGrad;
    function<double()> weightInit;
    function<double()> biasInit;

public:
    Layer(int, int, const function<double()>& weightInit, const function<double()>& biasInit);

    Vector forward(Vector input);

    Vector getNodes() { return nodes; }

    Vector backward(const Vector&);

    void update(double alpha);

};


#endif //CPP_LAYER_H
