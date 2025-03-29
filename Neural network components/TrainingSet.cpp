//
// Created by macie on 26/02/2024.
//

#include <fstream>
#include <iostream>
#include <cstring>
#include "TrainingSet.h"

#include <algorithm>

TrainingSet::TrainingSet(vector<Vector> input, vector<Vector> output) {
    this->input = std::move(input);
    this->output = std::move(output);
}


vector<Vector>* TrainingSet::getInput() {
    return &input;
}

vector<Vector>* TrainingSet::getOutput() {
    return &output;
}

TrainingSet TrainingSet::csvNumber(string path) {
    TrainingSet result({},{});
    ifstream file(path);
    try{
        if(!file.is_open()) throw "Couldn't open";
        string line;
        while(getline(file,line)){
            Vector currInput({});
            Vector currOutput({});
            char* arr = new char[line.length()+1];
            strcpy(arr,line.c_str());
            char *token = strtok(arr,",");
            int i = 0;
            while(token != NULL){
                if(i==0){
                    for(int j = 0; j < 10;j++){
                        if(j==stoi(token)) currOutput.addEntry(1);
                        else currOutput.addEntry(0);
                    }
                }else{
                    currInput.addEntry((double)stoi(token)/255);
                }
                token = strtok(NULL,",");
                i++;
            }
            if(i!=785){
                cout << "dupa" << endl;
            }
            result.getInput()->emplace_back(currInput);
            result.getOutput()->emplace_back(currOutput);
        }
        return result;
    }
    catch(...){
        cout << "Couldn't open file" << endl;
    }
}

TrainingSet TrainingSet::mnist() {
    TrainingSet result({},{});
    ifstream featuresFile("../Resources/MNIST.txt");
    ifstream targetFile("../Resources/MNIST_y.txt");

    try{
        if(!featuresFile.is_open()) throw "Couldn't open";
        if(!targetFile.is_open()) throw "Couldn't open";
        string line;
        string target;
        while(getline(featuresFile,line)){
            Vector currInput({});
            Vector currOutput({});
            char* arr = new char[line.length()+1];
            strcpy(arr,line.c_str());
            char *token = strtok(arr,",");
            int i = 0;
            while(token != NULL){
                currInput.addEntry((double)stoi(token)/255);
                token = strtok(NULL,",");
                i++;
            }
            getline(targetFile,target);
            int d = stoi(target);
            for(int j = 0; j < 10;j++){
                if(j==d) currOutput.addEntry(1);
                else currOutput.addEntry(0);
            }
            if(i!=784){
                cout << "dupa" << endl;
            }
            result.getInput()->emplace_back(currInput);
            result.getOutput()->emplace_back(currOutput);
        }
        return result;
    }
    catch(...){
        cout << "Couldn't open file" << endl;
    }
}

void TrainingSet::shuffle(int outputVectorSize) {
    vector<Vector> toShuffle = {};
    toShuffle.reserve(this->input.size());
    for(int i = 0; i < this->input.size(); i++) {

        Vector appended = this->input.at(i).append(this->output.at(i));

        toShuffle.push_back(appended);
    }

    random_shuffle(begin(toShuffle), end(toShuffle));

    vector<Vector> input = {};
    vector<Vector> output = {};

    input.reserve(this->input.size());
    for(int i = 0; i < this->input.size(); i++) {
        input.emplace_back(toShuffle.at(i).subVector(0,toShuffle.at(i).getSize()-outputVectorSize));
        output.emplace_back(toShuffle.at(i).subVector(toShuffle.at(i).getSize()-outputVectorSize,toShuffle.at(i).getSize()));
    }

    this->input = input;
    this->output = output;
}

int TrainingSet::size() const {
    return input.size();
}

TrainingSet TrainingSet::firstN(int n) {
    if(n <= 0) return {{},{}};
    vector<Vector> newInput (input.begin(),input.begin() + n);
    vector<Vector> newOutput (output.begin(),output.begin() + n);
    return {newInput,newOutput};
}



