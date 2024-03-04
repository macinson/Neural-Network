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
public:
    Layer(Matrix inWeights, Vector biases);
    Vector output(Vector input);
    Vector getNodes(){return nodes;}
    void update(Vector derivatives);
};


#endif //CPP_LAYER_H
