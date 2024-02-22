#include <iostream>
#include "Common/Vector.h"
#include "Common/Matrix.h"
#include "Neural network components/NeuralNetwork.h"
#include <utility>
#include <vector>
using namespace std;

int main() {
    NeuralNetwork XOR({Vector({0,-1})},{Matrix({Vector({1, 1}), Vector({1,1})})} ,Vector({1, -2}));
    cout << XOR.output(Vector({0,0})) << endl;
    cout << XOR.output(Vector({1,0})) << endl;
    cout << XOR.output(Vector({0,1})) << endl;
    cout << XOR.output(Vector({1,1})) << endl;
    return 0;
}
