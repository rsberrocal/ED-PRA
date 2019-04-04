/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayQueue.cpp
 * Author: rsudarbe117.alumnes
 * 
 * Created on 28 / de febrer / 2019, 12:19
 */

#include "ArrayQueue.h"
#include <iostream>

using namespace std;

ArrayQueue::ArrayQueue(const int max_size) {
    this->_max_size = max_size;
    std::vector<int> arr(max_size);
    this->_data = arr;
    this->_size = -1;
    cout << "Estructura creada" << endl;
}

void ArrayQueue::dequeue() {
    if (!this->isEmpty()) {
        cout << "Element " << this->_data[0] << " Eliminat" << endl;
        for (int i = 0; i < this->_size; i++) {
            this->_data[i] = this->_data[i + 1];
        }
        this->_data[this->_size] = false; //null means removed
        this->_size--;
    } else {
        throw invalid_argument("L’estructura està buida");
    }

}

void ArrayQueue::enqueue(const int key) {
    if (!this->isFull()) {
        this->_size++;
        this->_data[this->_size] = key;
        cout << "Element " << key << " agregat" << endl;
    } else {
        throw invalid_argument("L’estructura està plena");
    }
}

const int ArrayQueue::getFront() {
    if (!this->isEmpty()) {
        return this->_data[0];
    }
    throw invalid_argument("L’estructura està buida");
    return -1;
}

bool ArrayQueue::isEmpty() {
    if (this->_size == -1)
        return true;
    return false;
}

bool ArrayQueue::isFull() {
    if (this->_size == this->_max_size - 1)
        return true;
    return false;
}

void ArrayQueue::print() {
    cout << "[";
    string hasComma = ",";
    for (int i = 0; i <= this->_size; i++) {
        if (i == this->_size) hasComma = "";
        cout << this->_data[i] << hasComma;
    }
    cout << "]" << endl;
    //sfor(int i=0;i<this->_data)
}

/*ArrayQueue::ArrayQueue(const ArrayQueue& orig) {
}*/

ArrayQueue::~ArrayQueue() {
    this->_data.clear();
}

