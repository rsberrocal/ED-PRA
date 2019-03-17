/* 
 * File:   FlightNode.h
 * Author: Rocho
 *
 * Created on 13 de marzo de 2019, 0:56
 */

#ifndef NODE_H
#define NODE_H

#include <cstddef>

template <class T>
class FlightNode {
public:
    FlightNode();
    FlightNode(const T el);
    FlightNode(const FlightNode& orig);
    virtual ~FlightNode();
    T getElement()const;
    FlightNode<T>* getNext()const;
    void setNext(FlightNode<T> *n);
private:
    T element;
    FlightNode<T>* next;
};

template <class T>
T FlightNode<T>::getElement() const {    
    return this->element;
}

template <class T>
FlightNode<T>::FlightNode(const T el) {
    this->element = el;
    this->next = nullptr;
}

template <class T>
void FlightNode<T>::setNext(FlightNode* n) {
    this->next = n;
}

template <class T>
FlightNode<T>* FlightNode<T>::getNext() const{
    return this->next;
}

template <class T>
FlightNode<T>::~FlightNode(){};
#endif /* NODE_H */

