//
// Created by macie on 26/03/2025.
//

#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include <random>
using namespace std;

class Initialization {
    default_random_engine generator;
    int in_f;
    int out_f;
    double defaultUniform = 0;
public:
    Initialization(int in_f, int out_f);
    double glorot();
    double uniform();
};



#endif //INITIALIZATION_H
