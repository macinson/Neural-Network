//
// Created by macie on 21/02/2024.
//

#include <iostream>
#include "Matrix.h"
#include "UsefulMethods.h"
#include "WrongDimensionsException.h"

Matrix::Matrix(vector<Vector> columns) : columns{columns}, n{static_cast<int>(columns.size())} {
    m = (columns.empty()) ? 0 : columns.at(0).getComponents().size();
}

Vector Matrix::operator*(Vector v) {
    if(v.getSize()!=n) throw WrongDimensionsException();
    vector<double> temp;
    temp.reserve(m);
    for (int i = 0; i < m; i++) temp.push_back(0.0);
    Vector res(temp);
    for (int i = 0; i < n; i++) {
        res = res + columns.at(i) * v.getComponent(i);
    }
    return res;
}

Matrix Matrix::operator*(Matrix other) {
    if(n != other.getM()) throw WrongDimensionsException();
    Matrix res({});
    for(const Vector& c : other.getColumns()) {
        res.addColumn((*this) * c);
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
        comp.push_back(c.getComponent(0));
    }
    return Vector(comp);
}

string Matrix::toString(int precision) {
    string result = "";
    if(m == 1){
        result += "( ";
        for(int i = 0; i < n; i++){
            result += UsefulMethods::doubleToString(columns.at(i).getComponent(0),precision) + " ";
        }
        result += ")";
    }
    else{
        for(int i = 0; i < m; i++){
            if(i == 0) result += "/ ";
            else if(i ==m-1) result +="\\ ";
            else result +="| ";
            for(int j = 0; j < n; j++){
                result += UsefulMethods::doubleToString(columns.at(j).getComponent(i),precision) + " ";
            }
            if(i == 0) result += "\\\n";
            else if(i ==m-1) result +="/\n";
            else result +="|\n";
        }
    }
    return result;
}

void Matrix::appendRow(Vector row) {
    try{
        if(n!= 0 && n!= row.getSize()) throw WrongDimensionsException();
        if(n==0){
            for(int i =0; i < row.getSize(); i++){
                columns.emplace_back(Vector({}));
            }
            n = row.getSize();
        }
        for(int i = 0; i < n; i ++){
            columns.at(i).addEntry(row.getComponent(i));
        }
        m++;
    } catch(WrongDimensionsException e){
        cout << e.message();
    }
}

Matrix Matrix::operator+(Matrix other) {
    if(n != other.getN()) throw WrongDimensionsException();
    vector<Vector> columns;
    for(int i = 0; i < n; i++){
        columns.emplace_back(this->columns.at(i) + other.getColumn(i));
    }
    return Matrix(columns);
}

Matrix Matrix::operator-(Matrix other) {
    if(n != other.getN()) throw WrongDimensionsException();
    vector<Vector> columns;
    for(int i = 0; i < n; i++){
        columns.emplace_back(this->columns.at(i) - other.getColumn(i));
    }
    return Matrix(columns);
}

Matrix Matrix::operator*(double scalar) {
    vector<Vector> columns;
    for(int i = 0; i < n; i++){
        columns.emplace_back(this->columns.at(i) * scalar);
    }
    return Matrix(columns);
}

Matrix::Matrix(int m, int n, const function<double()>& init) {
    for(int i = 0; i < n; i++){
        Vector column({});
        for(int j = 0; j < m; j++){
            column.addEntry(init());
        }
        columns.emplace_back(column);
    }
    this->m = m;
    this->n = n;
}

void Matrix::addColumn(Vector column) {
    try{
        if(m != 0 && m!= column.getSize()) throw WrongDimensionsException();
        columns.emplace_back(column);
        m = column.getSize();
        n++;
    }catch (WrongDimensionsException e){
        cout << e.message() << endl;
    }
}

Matrix Matrix::transpose() {
    Matrix res({});
    for(int i = 0; i < m; i++) {
        Vector v({});
        for(int j = 0; j < n; j++) {
            v.addEntry(columns.at(j).getComponent(i));
        }
        res.addColumn(v);
    }
    return res;
}


Matrix Matrix::diagonalize(Vector v){
    const int n = v.getComponents().size();
    Matrix res({});
    for(int i = 0; i < n; i++) {
        Vector curr({});
        for(int j = 0; j < n;j++) {
            if(i ==j) curr.addEntry(v.getComponent(i));
            else curr.addEntry(0.0);
        }
        res.addColumn(curr);
    }
    return res;
}
