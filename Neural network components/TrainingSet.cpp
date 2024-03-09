//
// Created by macie on 26/02/2024.
//

#include <fstream>
#include <iostream>
#include <cstring>
#include "TrainingSet.h"

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
