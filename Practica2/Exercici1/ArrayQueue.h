/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayQueue.h
 * Author: rsudarbe117.alumnes
 *
 * Created on 28 / de febrer / 2019, 12:19
 */

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <vector>

class ArrayQueue {
public:
    ArrayQueue(const int max_size);
    //ArrayQueue(const ArrayQueue& orig);    
    virtual ~ArrayQueue();
    void enqueue(const int key);
    void dequeue();
    bool isFull();
    bool isEmpty();
    void print();
    const int getFront();
private:
    int _max_size;
    int _size;
    std::vector<int> _data;
};

#endif /* ARRAYQUEUE_H */

