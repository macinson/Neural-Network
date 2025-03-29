#include <iostream>
#include <cmath>
#include <memory>

#include "Common/Vector.h"
#include "Common/Matrix.h"
#include "Neural network components/NeuralNetwork.h"
#include <utility>
#include <vector>
#include <string>

#include "ActivationFunc/ReLu.h"
#include "ActivationFunc/Sigmoid.h"
#include "ActivationFunc/SoftMax.h"
#include "Common/Initialization.h"
#include "Common/UsefulMethods.h"
#include "CostFunc/MSE.h"

using namespace std;

double random() {
    return (2.0* ((double) rand() / RAND_MAX)) -1.0;
}

int main() {
    TrainingSet trainingSet = TrainingSet::mnist();
    trainingSet.shuffle(10);

    TrainingSet test = trainingSet.firstN(3000);

    default_random_engine generator;
    uniform_real_distribution<double> distribution1(-sqrt(6.0/(784 + 16)), -sqrt(6.0/(784 + 16)));
    uniform_real_distribution<double> distribution2(-sqrt(6.0/(16 + 16)), -sqrt(6.0/(16 + 16)));
    uniform_real_distribution<double> distribution3(-sqrt(6.0/(10 + 16)), -sqrt(6.0/(10 + 16)));

    // Initialization firstInit(784,16);
    // Initialization secondInit(16,16);
    // Initialization thirdInit(16,10);

    Layer l1(784,16, &random, []() {return 0.0;});
    Layer l2(16,16, &random, []() {return 0.0;});
    Layer l3(16,10, &random, []() {return 0.0;});

    Activation* a1 = new ReLu(0.01);
    Activation* a2 = new ReLu(0.01);
    Activation* a3 = new SoftMax();

    Cost* mse = new MSE();


    NeuralNetwork network ({l1,l2,l3},{a1,a2,a3});

    auto res = network.train(test,0.1,mse,10);

    cout << network.output(trainingSet.getInput()->at(0)).toString(2) << endl;
    cout << trainingSet.getOutput()->at(0).toString(2) << endl;

    for(int i = 0; i< res.first.size(); i++) {
        cout << UsefulMethods::doubleToString(res.first.at(i),2) << ", " << UsefulMethods::doubleToString(res.second.at(i),2) << endl;
    }

    delete a1;
    delete a2;
    delete a3;

    delete mse;

    return 0;
}


