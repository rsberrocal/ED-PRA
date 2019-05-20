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
    Type* maxValues();
    void removeMax();
    void printHeap();
    void makeSwaps();
    Type* left(int pos);
    bool hasLeft(int pos);
    Type* right(int pos);
    bool hasRight(int pos);
    Type* parent(int pos);
    Type* getRoot();
    Type* search();
    vector<Type*>* data;
private:
};

template <class Type>
MaxHeap<Type>::MaxHeap() {
    cout << "Creating Heap" << endl;
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
    this->makeSwaps();
}

template<class Type>
void MaxHeap<Type>::makeSwaps() {
    int i = this->size() - 1;
    while (i > 0) {
        NodeMountain* actualNode = this->data->at(i);
        NodeMountain* parent = this->parent(i);
        if (actualNode->getKey() > parent->getKey()) {
            swap(this->data->at(i), this->data->at((i - 1) / 2));
        }
        i = (i - 1) / 2;
    }
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
    return this->getRoot()->getKey();
}

template <class Type>
Type* MaxHeap<Type>::maxValues() {
    return this->getRoot();
}

template <class Type>
void MaxHeap<Type>::printHeap() {
    int i = 0;
    while (i < this->size()) {
        NodeMountain* actualNode = this->data->at(i);
        cout << "ID: " << actualNode->getKey() << " NAME: " << actualNode->getName() << " HEIGHT: " << actualNode->getHeight();
        if (this->hasLeft(i)) {
            i = (2 * i) + 1;
        } else if (this->hasRight(i)) {
            i = (2 * i) + 2;
        }else{
            i++;
        }           
        cout << endl;
    }
}

template <class Type>
void MaxHeap<Type>::removeMax() {
    swap(this->data->at(0), this->data->at(this->size() - 1));
    this->data->pop_back();
    this->makeSwaps();
}

template <class Type>
Type* MaxHeap<Type>::search() {

}

template <class Type>
Type* MaxHeap<Type>::left(int pos) {
    return this->data->at((2 * pos) + 1);
}

template <class Type>
bool MaxHeap<Type>::hasLeft(int pos) {
    return (2 * pos) + 1 < this->data->size();
}

template <class Type>
Type* MaxHeap<Type>::right(int pos) {
    return this->data->at((2 * pos) + 2);
}

template <class Type>
bool MaxHeap<Type>::hasRight(int pos) {
    return (2 * pos) + 2 < this->data->size();
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

