/* 
 * File:   LinkedQueue.cpp
 * Author: Rocho
 * 
 * Created on 13 de marzo de 2019, 0:44
 */

#include "LinkedQueue.h"

LinkedQueue::LinkedQueue() {
    this->_size = -1;
    this->_front = nullptr;
    this->_rear = nullptr;
}

LinkedQueue::LinkedQueue(const LinkedQueue& orig) {
}

LinkedQueue::~LinkedQueue() {
}

void LinkedQueue::enqueue(const int key) {
    Node n(key);
    this->_rear->setNext(&n);
    this->_rear = &n;
    if (this->_front) {
        this->_front = &n;
    }
}

void LinkedQueue::dequeue() {

}

const int LinkedQueue::getFront() {
    if (!isEmpty()) {
        this->_front->getElement();
    } else {
        //Error
    }

}

bool LinkedQueue::isEmpty() {

}

void LinkedQueue::print() {

}


