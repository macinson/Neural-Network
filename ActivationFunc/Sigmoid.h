//
// Created by macie on 26/03/2025.
//

#ifndef SIGMOID_H
#define SIGMOID_H
#include "Activation.h"


class Sigmoid : public Activation{
public:
    Vector forward(Vector) override;
    Vector backward(Vector) override;
};



#endif //SIGMOID_H
