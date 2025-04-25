//
// Created by macie on 27/03/2025.
//

#ifndef MSE_H
#define MSE_H
#include "Cost.h"
#include "../ActivationFunc/Activation.h"


class MSE : public Cost{
    pair<double, Vector> calc(Vector y_true, Vector y_pred) override;
};



#endif //MSE_H
