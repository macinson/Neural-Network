//
// Created by macie on 28/03/2025.
//

#ifndef SOFTMAX_H
#define SOFTMAX_H
#include "Activation.h"


class SoftMax : public Activation{
public:
    SoftMax();
    Vector forward(Vector) override;
    Vector backward(Vector) override;
};



#endif //SOFTMAX_H
