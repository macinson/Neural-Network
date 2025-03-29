//
// Created by macie on 29/03/2025.
//

#ifndef RELU_H
#define RELU_H
#include "Activation.h"


class ReLu : public Activation{
private:
    double alpha;
public:
    ReLu(double);
    Vector forward(Vector) override;
    Vector backward(Vector) override;
};



#endif //RELU_H
