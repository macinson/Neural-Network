#include <iostream>
#include "Common/Vector.h"
#include "Common/Matrix.h"
#include <vector>
using namespace std;

int main() {
    Vector v1({0,1});
    Vector v2({-1,0});
    Vector v3({1,1});
    Matrix m1({v1,v2});
    cout << (v1 + v2).toString()<<endl;
    cout << v1*v2<<endl;
    cout << (v1 * 2).toString()<<endl;
    cout << (m1 * v3).toString() << endl;
    return 0;
}
