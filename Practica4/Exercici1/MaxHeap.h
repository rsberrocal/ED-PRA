/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MaxHeap.h
 * Author: rsudarbe117.alumnes
 *
 * Created on 16 / de maig / 2019, 09:42
 */

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>
#include<iostream>

#include "NodeMountain.h"

using namespace std;

template <class Type>
class MaxHeap {
public:
    MaxHeap();
    MaxHeap(const MaxHeap &orig);
    virtual ~MaxHeap();

    int size();
    bool isEmpty();
    void insert(int key, Type* element);
    int max(); //return the maxID
    Type& maxValues();
    void removeMax();
    void printHeap();
    Type* left(int pos);
    Type* right(int pos);
    Type* parent(int pos);
    Type* getRoot();
    Type* search();
    vector<Type*>* data;
private:
};

template <class Type>
MaxHeap<Type>::MaxHeap() {
    cout << "Creant Heap" << endl;
    vector<Type*>* v = new vector<Type*>();
    this->data = v;
}

template <class Type>
MaxHeap<Type>::MaxHeap(const MaxHeap& orig) {

}

template <class Type>
MaxHeap<Type>::~MaxHeap() {
    cout << "Deleting Heap" << endl;
}

template <class Type>
void MaxHeap<Type>::insert(int key, Type* element) {
    this->data->push_back(element);
    NodeMountain* parent = this->parent(this->size() - 1);
    NodeMountain* current = this->data->at(this->data->size() - 1);
    cout << "Parent Element " << parent->getKey() << endl;
    cout << "Actual Element " << current->getKey() << endl;
    bool needSwap = true;
    while (needSwap) {
        if (current->getHeight() > parent->getHeight()) {
            cout << "SWAP" << endl;
            swap(current, parent);
        }
    }
    cout << "Parent Element " << parent->getKey() << endl;
    cout << "Actual Element " << current->getKey() << endl;
}

template <class Type>
bool MaxHeap<Type>::isEmpty() {
    return this->size() == 0;
}

template <class Type>
int MaxHeap<Type>::size() {
    return this->data->size();
}

template <class Type>
int MaxHeap<Type>::max() {

}

template <class Type>
Type& MaxHeap<Type>::maxValues() {

}

template <class Type>
void MaxHeap<Type>::printHeap() {

}

template <class Type>
void MaxHeap<Type>::removeMax() {

}

template <class Type>
Type* MaxHeap<Type>::search() {

}

template <class Type>
Type* MaxHeap<Type>::left(int pos) {
    return this->data->at((2 * pos) + 1);
}

template <class Type>
Type* MaxHeap<Type>::right(int pos) {
    return this->data->at((2 * pos) + 2);
}

template <class Type>
Type* MaxHeap<Type>::parent(int pos) {
    return this->data->at((pos - 1) / 2);
}

template <class Type>
Type* MaxHeap<Type>::getRoot() {
    return this->data->front();
}

#endif /* MAXHEAP_H */

