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
    try {
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
    catch (WrongDimensionsException &e){
        cout << e.message();
    }
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
    try{
        if(n != other.getN()) throw WrongDimensionsException();
        vector<Vector> columns;
        for(int i = 0; i < n; i++){
            columns.emplace_back(this->columns.at(i) + other.getColumn(i));
        }
        return Matrix(columns);
    }catch (WrongDimensionsException e){
        cout << e.message();
    }
}

Matrix Matrix::operator*(double scalar) {
    vector<Vector> columns;
    for(int i = 0; i < n; i++){
        columns.emplace_back(this->columns.at(i) * scalar);
    }
    return Matrix(columns);
}

Matrix::Matrix(int m, int n, double (*random)()) {
    for(int i = 0; i < n; i++){
        Vector column({});
        for(int j = 0; j < m; j++){
            column.addEntry(random());
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
