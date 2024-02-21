#include <iostream>
#include "Common/Vector.h"
#include <vector>
using namespace std;

int main() {
    Vector v1({1.5,2});
    Vector v2({3, 4});
    cout << (v1 + v2).toString()<<endl;
    cout << v1*v2<<endl;
    cout << (v1 * 2).toString()<<endl;
    return 0;
}
