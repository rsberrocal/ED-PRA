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
        this->insertMountain(stoi(id), name, stoi(height));
    }
}

void BSTMountainFinder::insertMountain(int mountainId, string name, int height) {
    Mountain* m = new Mountain(mountainId, name, height);
    this->tree->insert(m, mountainId);
}

void BSTMountainFinder::printMountainsByID(int mountainId) {
    this->tree->printFromNode(mountainId);
}

string BSTMountainFinder::showMountain(int mountainId) {
    Mountain m = findMountain(mountainId);
    return "" + to_string(m.getId()) + ", " + m.getName() + ", " + to_string(m.getHeight());
}

Mountain* BSTMountainFinder::findMountain(int mountainId) {
    return this->tree->getValue(mountainId);
}


