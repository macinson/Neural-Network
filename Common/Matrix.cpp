//
// Created by macie on 21/02/2024.
//

#include "Matrix.h"

Matrix::Matrix(vector<Vector> columns) : columns{columns}, n{static_cast<int>(columns.size())} {
    m = (columns.empty()) ? 0 : columns.at(0).getComponents().size();
}

Vector Matrix::operator*(Vector v) {
    vector<double> temp;
    temp.reserve(m);
    for (int i = 0; i < m; i++) temp.push_back(0.0);
    Vector res(temp);
    for (int i = 0; i < n; i++) {
        res = res + columns.at(i) * v.getComponents().at(i);
    }
    return res;
}

bool Matrix::empty() {
    return columns.empty();
}

Vector Matrix::toVector() {
    if (m != 1) return Vector({});
    vector<double> comp;
    comp.reserve(columns.size());
    for (Vector c: columns) {
        comp.push_back(c.getComponents().at(0));
    }
    return Vector(comp);
}
