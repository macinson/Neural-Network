//
// Created by macie on 21/02/2024.
//

#ifndef CPP_VECTOR_H
#define CPP_VECTOR_H
#include <vector>
#include <string>

using namespace std;

class Vector {
private:
    vector<double> components;
public:
    Vector(vector<double> components);
    vector<double> getComponents(){return components;}
    double operator * (Vector other);
    string toString();
};


#endif //CPP_VECTOR_H
