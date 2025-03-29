//
// Created by macie on 26/03/2025.
//

#include "Initialization.h"

Initialization::Initialization(int in_f, int out_f): in_f(in_f), out_f(out_f) {

}


double Initialization::glorot() {
    uniform_real_distribution<double> distribution(-sqrt(6.0/(in_f + out_f)), -sqrt(6.0/(in_f + out_f)));
    return distribution(generator);
}

double Initialization::uniform() {
    return defaultUniform;
}
