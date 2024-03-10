//
// Created by macie on 21/02/2024.
//

#include "Vector.h"
#include "WrongDimensionsException.h"
#include "UsefulMethods.h"

#include <utility>
#include <algorithm>
#include <iostream>
#include <cstring>

Vector::Vector(vector<double> components) : components{std::move(components)}, size(components.size()) {}

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

string Vector::toString(int precision) {
    string res = "{";
    for (int i = 0; i < this->components.size(); i++) {
        res += UsefulMethods::doubleToString(this->components.at(i),precision) + ((i < this->components.size() - 1) ? ", " : "}");
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

double Vector::addEntry(double d) {
    components.emplace_back(d);
    size++;
    return d;
}

Vector::Vector(int n, double (*random)()) {
    for(int i = 0; i < n; i++) components.emplace_back(random());
}

Vector Vector::commaSeperatedToVector(string s) {
    Vector result({});
    char* arr = new char[s.length()+1];
    strcpy(arr,s.c_str());
    char* token = strtok(arr,",");
    while(token != NULL){
        result.addEntry(stoi(token));
        token = strtok(NULL,",");
    }
    return result;
}
