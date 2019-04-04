/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayStack.h
 * Author: rsudarbe117.alumnes
 *
 * Created on 4 / d’abril / 2019, 11:15
 */

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include <vector>

class ArrayStack {
public:
    ArrayStack(const int max_size);
    ArrayStack(const ArrayStack& orig);
    virtual ~ArrayStack();
    void push(const int key);
    void pop();
    bool isFull();
    bool isEmpty();
    void print();
    const int top();
private:
    int _max_size;
    int _size;
    std::vector<int>_data;
};

#endif /* ARRAYSTACK_H */

