//
// Created by macie on 27/02/2024.
//

#ifndef CPP_USEFULMETHODS_H
#define CPP_USEFULMETHODS_H

#include <string>
#include <cmath>

using namespace std;

//for some methods I may need while making this project
class UsefulMethods {
public:
    static string doubleToString(double d, int precision);
    static double ReLUDerivative(double d);

    static double sigmoidDerivative(double d);
};


#endif //CPP_USEFULMETHODS_H
