cmake_minimum_required(VERSION 3.26)
project(cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp main.cpp
        Common/Vector.cpp
        Common/Vector.h
        Common/Matrix.cpp
        Common/Matrix.h
        "Neural network components/NeuralNetwork.cpp"
        "Neural network components/NeuralNetwork.h"
        "Neural network components/TrainingSet.cpp"
        "Neural network components/TrainingSet.h"
        Common/UsefulMethods.cpp
        Common/UsefulMethods.h
        "Neural network components/Layer.cpp"
        "Neural network components/Layer.h"
        Common/WrongDimensionsException.cpp
        Common/WrongDimensionsException.h
)
