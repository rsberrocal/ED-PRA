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

using namespace std;

BSTMountainFinder::BSTMountainFinder() {
    BST<Mountain> x;
    this->tree = x;
}

BSTMountainFinder::BSTMountainFinder(const BSTMountainFinder& orig) {
}

BSTMountainFinder::~BSTMountainFinder() {
}

void BSTMountainFinder::appendMountains(string fileName) {
    ifstream file(fileName);
    string id, name, height;
    while (file.good()) {
        getline(file, id, '::');
        getline(file, name, '::');
        getline(file, height, '\n');
        this->tree.insert(new Mountain(id, name, height));
    }
}
