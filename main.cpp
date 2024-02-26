#include <iostream>
#include "Common/Vector.h"
#include "Common/Matrix.h"
#include "Neural network components/NeuralNetwork.h"
#include <utility>
#include <vector>

using namespace std;

int main() {
//    NeuralNetwork XOR({Vector({0,-1}),Vector({0,0})},{Matrix({Vector({1, 1}), Vector({1,1})}),Matrix({Vector({1}), Vector({-2})})});
//    cout << XOR.output(Vector({0,0})).getComponents().at(0) << endl;
//    cout << XOR.output(Vector({1,0})).getComponents().at(0) << endl;
//    cout << XOR.output(Vector({0,1})).getComponents().at(0) << endl;
//    cout << XOR.output(Vector({1,1})).getComponents().at(0) << endl;

    Matrix m({Vector({1,2,3}), Vector({2,1,3}),Vector({4,1,7})});
    cout << m.toString();
    return 0;
}
