#include <iostream>
#include "Common/Vector.h"
#include <vector>
using namespace std;

int main() {
    Vector v1({1.5,2});
    Vector v2({3, 4});
    double result = v1 *v2;
    cout << result<<endl;
    return 0;
}
