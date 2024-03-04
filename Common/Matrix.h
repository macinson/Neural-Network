//
// Created by macie on 21/02/2024.
//

#ifndef CPP_MATRIX_H
#define CPP_MATRIX_H


#include "Vector.h"
#include <vector>
using namespace std;

class Matrix {
private:
    vector<Vector> columns;
    int m;
    int n;
public:
    explicit Matrix(vector<Vector> columns);
    Vector operator * (Vector v);
    bool empty();
    Vector toVector();
    string toString(int precision);
    void appendRow(Vector row);
    Matrix operator+(Matrix other);
    Matrix operator*(double scalar);
    int getN(){return n;}
    Vector getColumn(int i){return columns.at(i);}
};


#endif //CPP_MATRIX_H
