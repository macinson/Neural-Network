//
// Created by macie on 27/02/2024.
//

#ifndef CPP_LAYER_H
#define CPP_LAYER_H


#include "../Common/Vector.h"
#include "../Common/Matrix.h"

class Layer {
private:
    Vector nodes;
public:
    Layer(Vector nodes);
};


#endif //CPP_LAYER_H