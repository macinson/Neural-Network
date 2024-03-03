//
// Created by macie on 21/02/2024.
//

#include "Vector.h"
#include "WrongDimensionsException.h"

#include <utility>
#include <algorithm>
#include <iostream>

Vector::Vector(vector<double> components) : components{std::move(components)} {}

double Vector::operator*(Vector other) {
    try {
        if (this->getSize() != other.getSize()) throw WrongDimensionsException();
        double res = 0.0;
        for (int i = 0; i < this->components.size(); i++) {
            res += other.getComponents().at(i) * this->components.at(i);
        }
        return res;
    }
    catch (WrongDimensionsException &e){
        cout << e.message();
    }
}

string Vector::toString() {
    string res = "{";
    for (int i = 0; i < this->components.size(); i++) {
        res += to_string(this->components.at(i)) + ((i < this->components.size() - 1) ? ", " : "}");
    }
    return res;
}

Vector Vector::operator+(Vector other) {
    try {
        if(this->getSize() != other.getSize()) throw WrongDimensionsException();
        vector<double> res;
        res.reserve(this->components.size());
        for (int i = 0; i < this->components.size(); i++) {
            res.push_back(other.getComponents().at(i) + this->components.at(i));
        }
        return Vector(res);
    }
    catch (WrongDimensionsException &e){
        cout << e.message();
    }
}

Vector Vector::operator*(double scalar) {
    vector<double> res;
    res.reserve(this->components.size());
    for (double component: this->components) {
        res.push_back(component * scalar);
    }
    return Vector(res);
}

Vector Vector::ReLU() {
    vector<double> res;
    res.reserve(components.size());
    for (double d: components) res.push_back(max(0.0, d));
    return Vector(res);
}

double Vector::getComponent(int index) {
    try {
        return components.at(index);
    } catch (...) {
        cout << "Index out of bounds" << endl;
    }
}
