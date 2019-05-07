/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BSTMountainFinder.cpp
 * Author: Rocho
 * 
 * Created on 28 de abril de 2019, 20:14
 */

#include "BSTMountainFinder.h"

#include <fstream>
#include <string>

using namespace std;

BSTMountainFinder::BSTMountainFinder() {
    this->tree = new BST<Mountain>();
}

BSTMountainFinder::BSTMountainFinder(const BSTMountainFinder& orig) {
}

BSTMountainFinder::~BSTMountainFinder() {
}

void BSTMountainFinder::appendMountains(string fileName) {
    ifstream file(fileName);
    string id, name, height, tmp;

    while (file.good()) {
        getline(file, id, ':');
        getline(file, tmp, ':');
        getline(file, name, ':');
        getline(file, tmp, ':');
        getline(file, height, '\n');
        Mountain* m = new Mountain(stoi(id), name, stoi(height));
        this->tree->insert(m, stoi(id));
    }
}
