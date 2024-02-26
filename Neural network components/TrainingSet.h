//
// Created by macie on 26/02/2024.
//

#ifndef CPP_TRAININGSET_H
#define CPP_TRAININGSET_H


#include "../Common/Vector.h"

class TrainingSet {
private:
    vector<Vector> input;
    vector<Vector> output;
public:
    TrainingSet(vector<Vector> input, vector<Vector> output);
    virtual vector<Vector> getInput();
    virtual vector<Vector> getOutput();
};


#endif //CPP_TRAININGSET_H
