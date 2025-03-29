//
// Created by macie on 27/02/2024.
//

#ifndef CPP_USEFULMETHODS_H
#define CPP_USEFULMETHODS_H

#include <string>
#include <cmath>
#include <vector>
#include "WrongDimensionsException.h"

using namespace std;

//for some methods I may need while making this project
class UsefulMethods {
public:
    static string doubleToString(double d, int precision);
    static double ReLUDerivative(double d);

    static double sigmoidDerivative(double d);

    static double ReLU(double d);

    static double sigmoid(double d);

    template <class A, class B> static vector<pair<A,B>> zip(vector<A> a, vector<B> b){
        if(a.size() != b.size()) throw WrongDimensionsException();
        vector<pair<A,B>> res{};
        for(int i = 0; i < a.size(); i++) {
            res.push_back(std::make_pair(a.at(i), b.at(i)));
        }
        return res;
    }
};


#endif //CPP_USEFULMETHODS_H
