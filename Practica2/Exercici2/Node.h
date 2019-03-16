/* 
 * File:   Node.h
 * Author: Rocho
 *
 * Created on 13 de marzo de 2019, 0:56
 */

#ifndef NODE_H
#define NODE_H

#include <cstddef>

template <class T>
class Node {
public:
    Node();
    Node(const T el);
    Node(const Node& orig);
    virtual ~Node();
    T getElement()const;
    Node<T>* getNext()const;
    void setNext(Node<T> *n);
private:
    T element;
    Node<T>* next;
};

template <class T>
T Node<T>::getElement() const {    
    return this->element;
}

template <class T>
Node<T>::Node(const T el) {
    this->element = el;
    this->next = nullptr;
}

template <class T>
void Node<T>::setNext(Node* n) {
    this->next = n;
}

template <class T>
Node<T>* Node<T>::getNext() const{
    return this->next;
}

template <class T>
Node<T>::~Node(){};
#endif /* NODE_H */

