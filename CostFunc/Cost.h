//
// Created by macie on 27/03/2025.
//

#ifndef COST_H
#define COST_H

#include <utility>

#include "../Common/Vector.h"

using namespace std;

class Cost {
public:
    virtual pair<double,Vector> calc(Vector y_true, Vector y_pred) = 0;
};



#endif //COST_H
