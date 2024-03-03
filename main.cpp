#include <iostream>
#include "Common/Vector.h"
#include "Common/Matrix.h"
#include "Neural network components/NeuralNetwork.h"
#include <utility>
#include <vector>

using namespace std;

int main() {
    vector<Layer> layers;
    layers.push_back(Layer(Matrix({Vector({1, 1}), Vector({1,1})}), Vector({0,-1})));
    layers.push_back(Layer(Matrix({Vector({1}),Vector({-2})}),Vector({0})));
    NeuralNetwork XOR(layers);

    cout << XOR.output(Vector({0,0})).getComponent(0) << endl;
    cout << XOR.output(Vector({1,0})).getComponent(0) << endl;
    cout << XOR.output(Vector({0,1})).getComponent(0) << endl;
    cout << XOR.output(Vector({1,1})).getComponent(0) << endl;

    Matrix m({Vector({1,2,3}), Vector({2,1,3}),Vector({4,1,7})});
    cout << endl << m.toString(0);
    return 0;
}
