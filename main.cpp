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
//    vector<Layer> layers;
//    layers.emplace_back(Matrix({Vector({1, 1}), Vector({1,1})}), Vector({0,-1}));
//    layers.emplace_back(Matrix({Vector({1}),Vector({-2})}),Vector({0}));
//    NeuralNetwork XOR(layers);

    vector<Vector> inputs;
    inputs.emplace_back(vector<double>{0,0});
    inputs.emplace_back(vector<double>{0,1});
    inputs.emplace_back(vector<double>{1,0});
    inputs.emplace_back(vector<double>{1,1});

    vector<Vector> outputs;
    outputs.emplace_back(vector<double>{0});
    outputs.emplace_back(vector<double>{1});
    outputs.emplace_back(vector<double>{1});
    outputs.emplace_back(vector<double>{0});

    TrainingSet trainingSet(inputs,outputs);

    Matrix m1(2,2,&random);
    Matrix m2(1,2,&random);
    Vector b1(2, &random);
    Vector b2(1,&random);
    vector<Layer> layers;
    layers.emplace_back(m1,b1);
    layers.emplace_back(m2,b2);
    NeuralNetwork XOR(layers);

    XOR.backProp(trainingSet,0.001);

    cout << round(XOR.output(Vector(vector<double>{0,0})).getComponent(0)) << endl;
    cout << round(XOR.output(Vector(vector<double>{1,0})).getComponent(0)) << endl;
    cout << round(XOR.output(Vector(vector<double>{0,1})).getComponent(0)) << endl;
    cout << round(XOR.output(Vector(vector<double>{1,1})).getComponent(0)) << endl;

    Matrix m({Vector({1,2,3}), Vector({2,1,3}),Vector({4,1,7})});
    cout << endl << m.toString(0);



    return 0;
}


