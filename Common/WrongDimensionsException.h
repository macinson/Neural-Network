//
// Created by macie on 03/03/2024.
//

#ifndef CPP_WRONGDIMENSIONSEXCEPTION_H
#define CPP_WRONGDIMENSIONSEXCEPTION_H


#include <exception>
#include <string>
using namespace std;

class WrongDimensionsException: public exception {
public:
    string message(){return "Wrong dimensions";}
};


#endif //CPP_WRONGDIMENSIONSEXCEPTION_H
