/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayStack.cpp
 * Author: rsudarbe117.alumnes
 * 
 * Created on 4 / d’abril / 2019, 11:15
 */

#include "ArrayStack.h"
#include <iostream>

using namespace std;

ArrayStack::ArrayStack(const ArrayStack& orig) {
}

ArrayStack::~ArrayStack() {
}

ArrayStack::ArrayStack(const int max_size) {
    this->_max_size = max_size;
    this->_size = -1;
    std::vector<int> arr(max_size);
    this->_data = arr;
}

void ArrayStack::push(const int key) {
    if (!this->isFull()) {
        this->_size++;
        this->_data[this->_size] = key;
    } else {
        string errorMsg = "Queue is Full";
        throw errorMsg;
    }
}

bool ArrayStack::isEmpty() {
    return this->_size == -1;
}

bool ArrayStack::isFull() {
    return this->_size ==this->_max_size-1;
}

void ArrayStack::pop() {
    if(!this->isEmpty()){
        this->_size--; //El elemento seguira en memoria pero al añadir, dicho elemento se sobrescribe
    }else{
        string errorMsg = "Queue is Empty";
        throw errorMsg;
    }
}

void ArrayStack::print() {
    cout << "[";
    string hasComma = ",";
    for (int i = 0; i <= this->_size; i++) {
        if (i == this->_size) hasComma = "";
        cout << this->_data[i] << hasComma;
    }
    cout << "]" << endl;
}

const int ArrayStack::top() {
    return this->_data[this->_size];
}

