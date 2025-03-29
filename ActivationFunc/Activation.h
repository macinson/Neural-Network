//
// Created by macie on 26/03/2025.
//

#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "../Common/Vector.h"

using namespace std;



class Activation {
protected:
    Vector* cache;
public:
    Activation();
    ~Activation();
    virtual Vector forward(Vector) = 0;
    virtual Vector backward(Vector) = 0;
};



#endif //ACTIVATION_H
