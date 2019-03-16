/* 
 * File:   LinkedQueue.h
 * Author: Rocho
 *
 * Created on 13 de marzo de 2019, 0:44
 */

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "Node.h"

template <class T>
class LinkedQueue {
public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue& orig);
    virtual ~LinkedQueue();
    void enqueue(const T key);
    void dequeue();
    bool isEmpty();
    void print();
    const T getFront();

private:
    int _size;
    Node<T>* _front;
    Node<T>* _rear;
};

template <class T>
LinkedQueue<T>::LinkedQueue() {
    this->_size = 0;
    this->_front = nullptr;
    this->_rear = nullptr;
}

template <class T>
LinkedQueue<T>::~LinkedQueue() {

}

template <class T>
void LinkedQueue<T>::enqueue(const T key) {
    Node<T>* newNode = new Node<T>(key);
    if (this->isEmpty()) {
        this->_front = newNode;
    } else {
        this->_rear->setNext(newNode);
    }
    this->_rear = newNode;
    this->_size++;
}

template <class T>
void LinkedQueue<T>::dequeue() {
    this->_front = this->_front->getNext();
    this->_size--;
}

template <class T>
const T LinkedQueue<T>::getFront() {    
    return this->_front->getElement();
}

template <class T>
bool LinkedQueue<T>::isEmpty() {
    if (this->_size == 0)
        return true;
    return false;
}

template <class T>
void LinkedQueue<T>::print() {

}

#endif /* LINKEDQUEUE_H */

