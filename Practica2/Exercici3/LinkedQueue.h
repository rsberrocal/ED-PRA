/* 
 * File:   LinkedQueue.h
 * Author: Rocho
 *
 * Created on 13 de marzo de 2019, 0:44
 */

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <stdexcept>

#include "FlightNode.h"
using namespace std;

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
    FlightNode<T>* _front;
    FlightNode<T>* _rear;
};

template <class T>
LinkedQueue<T>::LinkedQueue() {
    this->_size = 0;
    this->_front = nullptr;
    this->_rear = nullptr;
    cout << "Estructura creada" << endl;
}

template <class T>
LinkedQueue<T>::~LinkedQueue() {
    FlightNode<T>* actualNode = this->_front;
    FlightNode<T>* nodeToDelete;
    while (actualNode) {
        nodeToDelete = actualNode;
        actualNode = actualNode->getNext();
        delete nodeToDelete;
    }
    cout << "Estructura eliminada" << endl;
}

template <class T>
void LinkedQueue<T>::enqueue(const T key) {
    FlightNode<T>* newNode = new FlightNode<T>(key);
    if (this->isEmpty()) {
        this->_front = newNode;
    } else {
        this->_rear->setNext(newNode);
    }
    this->_rear = newNode;
    //cout << "Element " << key << " agregat" << endl;
    this->_size++;
}

template <class T>
void LinkedQueue<T>::dequeue() {
    if (!isEmpty()) {
        this->_front = this->_front->getNext();
        this->_size--;
    } else {
        throw invalid_argument("L’estructura està buida");
    }
}

template <class T>
const T LinkedQueue<T>::getFront() {
    if (!isEmpty())
        return this->_front->getElement();
    throw invalid_argument("L’estructura està buida");
}

template <class T>
bool LinkedQueue<T>::isEmpty() {
    if (this->_size == 0)
        return true;
    return false;
}

template <class T>
void LinkedQueue<T>::print() {
    FlightNode<T>* actualNode = this->_front;
    std::cout << "[";
    while (actualNode) {
        std::cout << actualNode->getElement();
        actualNode = actualNode->getNext();
        if (actualNode)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
//Copy constructor

template <class T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue& orig) {
    FlightNode <T>* actualNode = orig._front;
    this->_front = nullptr;
    this->_rear = nullptr;
    this->_size = 0;
    while (actualNode) {
        FlightNode<T>* newNode = new FlightNode<T>(actualNode->getElement());
        //If is the first element, inserts front node, else, get rear and set next to newNode
        if (!this->_front) {
            this->_front = newNode;
        } else {
            this->_rear->setNext(newNode);
        }
        this->_rear = newNode;
        this->_size++;
        actualNode = actualNode->getNext();
    }
}

#endif /* LINKEDQUEUE_H */

