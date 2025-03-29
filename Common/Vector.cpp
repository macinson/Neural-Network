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
#include <cmath>

Vector::Vector(vector<double> components) : components{std::move(components)} {
    this->size = components.size();
}

double Vector::dot(Vector other) {
    if (this->getSize() != other.getSize()) throw WrongDimensionsException();
    double res = 0.0;
    for (int i = 0; i < this->components.size(); i++) {
        res += other.getComponents().at(i) * this->components.at(i);
    }
    return res;
}

Vector Vector::operator*(Vector other) {
    if (this->getSize() != other.getSize()) throw WrongDimensionsException();
    vector<double> res{};
    for (int i = 0; i < this->components.size(); i++) {
        res.push_back(other.getComponents().at(i) * this->components.at(i));
    }
    return Vector(res);
}

string Vector::toString(int precision) {
    string res = "{";
    for (int i = 0; i < this->components.size(); i++) {
        res += UsefulMethods::doubleToString(this->components.at(i),precision) + ((i < this->components.size() - 1) ? ", " : "}");
    }
    return res;
}

Vector Vector::operator+(Vector other) {
    if(this->getSize() != other.getSize()) throw WrongDimensionsException();
    vector<double> res;
    res.reserve(this->components.size());
    for (int i = 0; i < this->components.size(); i++) {
        res.push_back(other.getComponents().at(i) + this->components.at(i));
    }
    return Vector(res);
}

Vector Vector::operator-(Vector other) {
    return *this + (other * (-1));
}

Vector Vector::append(Vector other) {
    vector<double> res ={};
    res.reserve(this->components.size() + other.getComponents().size());

    for(int i = 0; i < this->components.size(); i++) {
        res.emplace_back(this->components.at(i));
    }
    for(int i = 0; i < other.getComponents().size(); i++) {
        res.emplace_back(other.getComponents().at(i));
    }

    return Vector(res);
}

Vector Vector::operator*(double scalar) {
    vector<double> res;
    res.reserve(this->components.size());
    for (double component: this->components) {
        res.push_back(component * scalar);
    }
    return Vector(res);
}

Vector Vector::operator/(double scalar) {
    vector<double> res;
    res.reserve(this->components.size());
    for (double component: this->components) {
        res.push_back(1.0 * component / scalar);
    }
    return Vector(res);
}


Vector Vector::activation(double (*func)(double)) {
    vector<double> res;
    res.reserve(components.size());
    for (double d: components) res.push_back(func(d));
    return Vector(res);
}


double Vector::getComponent(int index) {
    return components.at(index);
}

double Vector::addEntry(double d) {
    components.emplace_back(d);
    size++;
    return d;
}

Vector::Vector(int n, double (*random)()) {
    for(int i = 0; i < n; i++) components.emplace_back(random());
    size = n;
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

Vector Vector::subVector(int begin, int end) {
    begin = max(begin,0);
    end = min(static_cast<int>(this->components.size()),end);

    Vector output({});

    for(int i = begin; i<end; i++) {
        output.addEntry(this->components.at(i));
    }

    return output;
}

double Vector::sum() {
    double s = 0.0;
    for(double d : components) {
        s += d;
    }
    return s;
}

Vector Vector::apply(function<double(double)> f) {
    vector<double> res{};
    res.reserve(components.size());
    for(const double d : components) {
        res.push_back(f(d));
    }
    return Vector(res);
}




