//
// Created by macie on 26/02/2024.
//

#include "TrainingSet.h"

TrainingSet::TrainingSet(vector<Vector> input, vector<Vector> output) {
    this->input = std::move(input);
    this->output = std::move(output);
}

vector<Vector> TrainingSet::getInput() {
    return input;
}

vector<Vector> TrainingSet::getOutput() {
    return output;
}
