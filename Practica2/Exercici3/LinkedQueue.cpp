/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "LinkedQueue.h"
#include <iostream>

using namespace std;
//LinkedQueue on init, front and read nullptr by default

LinkedQueue::LinkedQueue() {
    this->_size = 0;
    this->_front = nullptr;
    this->_rear = nullptr;
    cout << "Estructura creada" << endl;
}

//On delete, delete each node

LinkedQueue::~LinkedQueue() {
    FlightNode* actualNode = this->_front;
    FlightNode* nodeToDelete;
    while (actualNode) {
        nodeToDelete = actualNode;
        actualNode = actualNode->getNext();
        delete nodeToDelete;
    }
    cout << "Estructura eliminada" << endl;
}

//On add, creates a new node with key and set it to the last nodes

void LinkedQueue::enqueue(Flight* key) {
    string id = key->getId();
    FlightNode* newNode = new FlightNode(key);
    if (this->isEmpty()) {
        this->_front = newNode;
    } else {
        this->_rear->setNext(newNode);
    }
    this->_rear = newNode;
    //cout << "Element " << key << " agregat" << endl;
    this->_size++;
}

//On remove, replace front to next node

void LinkedQueue::dequeue() {
    if (!isEmpty()) {
        this->_front = this->_front->getNext();
        this->_size--;
    } else {
        throw invalid_argument("L’estructura està buida");
    }
}

//returns the front node, if is empty, throws an error

const FlightNode* LinkedQueue::getFront() {
    if (!isEmpty())
        return this->_front;
    throw invalid_argument("L’estructura està buida");
}

//Check if LinkedQueue is empty

bool LinkedQueue::isEmpty() {
    if (this->_size == 0)
        return true;
    return false;
}

//On print, get each node and print his element

void LinkedQueue::print() {
    FlightNode* actualNode = this->_front;
    std::cout << "[";
    while (actualNode) {
        actualNode->printNode();
        actualNode = actualNode->getNext();
        if (actualNode)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

//Copy constructor

LinkedQueue::LinkedQueue(const LinkedQueue& orig) {
    FlightNode * actualNode = orig._front;
    this->_front = nullptr;
    this->_rear = nullptr;
    this->_size = 0;
    while (actualNode) {
        FlightNode* newNode = new FlightNode(actualNode->getElement());
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