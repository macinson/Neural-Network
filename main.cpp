#include <iostream>
#include "Common/Vector.h"
#include "Common/Matrix.h"
#include <utility>
#include <vector>
using namespace std;

int XOR(Vector);

int main() {
    cout << XOR(Vector({0,0})) << endl;
    cout << XOR(Vector({1,0})) << endl;
    cout << XOR(Vector({0,1})) << endl;
    cout << XOR(Vector({1,1})) << endl;
    return 0;
}

int XOR(Vector input){
    Matrix W({Vector({1, 1}), Vector({1,1})});
    Vector c({0,-1});
    Vector w({1,-2});
    return static_cast<int> (((W*std::move(input))+c).ReLU()*w);
}
