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
    cout << "Estructura creada" << endl;
}

void ArrayQueue::dequeue() {

}

void ArrayQueue::enqueue(const int key) {
    this->_data.push_back(key);
    cout << key <<endl;
    cout << this->_data[0] << endl;
}

const int ArrayQueue::getFront() {

}

bool ArrayQueue::isEmpty() {

}

bool ArrayQueue::isFull() {

}

void ArrayQueue::print() {

}

/*ArrayQueue::ArrayQueue(const ArrayQueue& orig) {
}*/

ArrayQueue::~ArrayQueue() {
}

