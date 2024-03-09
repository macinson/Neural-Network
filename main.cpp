#include <iostream>
#include <cmath>
#include "Common/Vector.h"
#include "Common/Matrix.h"
#include "Neural network components/NeuralNetwork.h"
#include <utility>
#include <vector>

using namespace std;

double random(){
    return ((double) rand()/RAND_MAX);
}

int main() {
    TrainingSet trainingSet = TrainingSet::csvNumber("../Resources/testSetNumbers.txt");
    Matrix m1(16,784,&random);
    Matrix m2(16,16,&random);
    Matrix m3(10,16,&random);
    Vector b1(16,&random);
    Vector b2(16,&random);
    Vector b3(10,&random);
    vector<Layer> layers;
    layers.emplace_back(m1,b1);
    layers.emplace_back(m2,b2);
    layers.emplace_back(m3,b3);
    NeuralNetwork numbers(layers);

    numbers.backProp(trainingSet,0.01);

    

    return 0;
}


