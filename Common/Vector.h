//
// Created by macie on 21/02/2024.
//

#ifndef CPP_VECTOR_H
#define CPP_VECTOR_H

#include <functional>
#include <vector>
#include <string>

using namespace std;

class Vector {
private:
    vector<double> components;
    int size;
public:
    explicit Vector(vector<double> components);
    Vector(int n, const function<double()>& init);
    static Vector commaSeperatedToVector(string s);

    vector<double> getComponents() { return components; }

    double dot(Vector other);

    Vector operator-(Vector other);

    Vector operator+(Vector other);

    Vector operator*(double scalar);

    Vector operator/(double scalar);

    Vector operator*(Vector other);

    Vector operator/(Vector other);

    string toString(int precision);

    double getComponent(int index);

    int getSize() { return components.size(); }

    double addEntry(double d);

    Vector subVector(int begin, int end);

    Vector append(Vector other);

    double sum();

    Vector apply(function<double(double)>);

    Vector clip(double min = 0, double max = 1);
};


#endif //CPP_VECTOR_H
