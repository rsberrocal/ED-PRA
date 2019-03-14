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
    Node* getNext()const;
    void setNext(Node *n);
private:
    T element;
    Node next;
};

template <class T>
Node<T>:: getElement() const{
    return this->element;
}

template <class T>
Node<T>::Node(const T el){
    this->element = el;
    this->next = nullptr;
}

Node<>::setNext(Node* n){
    
}

#endif /* NODE_H */

