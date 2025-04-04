//
// Created by macie on 27/02/2024.
//

#include "UsefulMethods.h"
#include <iostream>

#include "WrongDimensionsException.h"

string UsefulMethods::doubleToString(double d, int precision) {
    string result;
    string temp = to_string(d);
    for (int i = 0; i < temp.length(); i++) {
        if (temp[i] == '.') {
            if(precision <= 0) break;
            for (int j = 0; j < precision+1; j++) {
                result += temp[i + j];
            }
            break;
        }
        result += temp[i];
    }
    return result;
}

double UsefulMethods::ReLUDerivative(double d) {
    return (d <= 0.0) ? 0.0 : 1.0;
}

double UsefulMethods::sigmoidDerivative(double d) {
    return exp(-d)/ pow((1.0+ exp(-d)),2.0);
}

double UsefulMethods::ReLU(double d){
    return max(0.0,d);
}

double UsefulMethods::sigmoid(double d){
    return 1.0/(1.0+exp(-d));
}

// template<class A, class B>
// vector<pair<A, B> > UsefulMethods::zip(vector<A> a, vector<B> b) {
//     if(a.size() != b.size()) throw WrongDimensionsException();
//     vector<pair<A,B>> res{};
//     for(int i = 0; i < a.size(); i++) {
//         res.push_back(std::make_pair(a.at(i), b.at(i)));
//     }
//     return res;
// }
//
// template<class A, class B>
// vector<pair<A, B*> > UsefulMethods::zip(vector<A> a, vector<B*> b) {
//     if(a.size() != b.size()) throw WrongDimensionsException();
//     vector<pair<A,B*>> res{};
//     for(int i = 0; i < a.size(); i++) {
//         res.push_back(std::make_pair(a.at(i), b.at(i)));
//     }
//     return res;
// }


