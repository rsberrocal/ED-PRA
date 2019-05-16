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

#define <vector>

using namespace std;

template <class Type>
class MaxHeap {
public:
    MaxHeap();
    MaxHeap(const MaxHeap &orig);
    virtual ~MaxHeap();
    
    int size();
    bool isEmpty();
    void insert(int key, Type& element);
    int max(); //return the maxID
    Type& maxValues();
    void removeMax();
    void printHeap();
    Type& search();
private:
   vector<Type>* data; 
};

template <class Type>
MaxHeap<Type>::MaxHeap(){
    vector
}

template <class Type>
MaxHeap<Type>::MaxHeap(const MaxHeap& orig){
    
}

template <class Type>
MaxHeap<Type>::~MaxHeap(){
    
}

template <class Type>
void MaxHeap<Type>::insert(int key, Type& element){
    
}

template <class Type>
bool MaxHeap<Type>::isEmpty(){
    
}

template <class Type>
int MaxHeap<Type>::max(){
    
}

template <class Type>
Type& MaxHeap<Type>::maxValues(){
    
}

template <class Type>
void MaxHeap<Type>::printHeap(){
    
}

template <class Type>
void MaxHeap<Type>::removeMax(){
    
}

template <class Type>
Type& MaxHeap<Type>::search(){
    
}

#endif /* MAXHEAP_H */

