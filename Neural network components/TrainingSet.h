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
    static TrainingSet csvNumber(string path);
    static TrainingSet mnist();
    vector<Vector>* getInput();
    vector<Vector>* getOutput();
    void shuffle(int outputVectorSize);
    [[nodiscard]] int size() const;
    TrainingSet firstN(int n);
};


#endif //CPP_TRAININGSET_H
