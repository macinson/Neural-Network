//
// Created by macie on 30/03/2025.
//

#ifndef CROSSENTROPY_H
#define CROSSENTROPY_H
#include "Cost.h"


class CrossEntropy : public Cost{
    pair<double, Vector> calc(Vector y_true, Vector y_pred) override;
};



#endif //CROSSENTROPY_H
