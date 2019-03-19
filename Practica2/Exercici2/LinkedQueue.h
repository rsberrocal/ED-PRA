/* 
 * File:   LinkedQueue.h
 * Author: Rocho
 *
 * Created on 13 de marzo de 2019, 0:44
 */

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <stdexcept>

#include "Node.h"
using namespace std;
//Class LinkedQueue with templates
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

//Constructor, node pointers null by default
template <class T>
LinkedQueue<T>::LinkedQueue() {
    this->_size = 0;
    this->_front = nullptr;
    this->_rear = nullptr;
    cout << "Estructura creada" << endl;
}

//On delete, delete each node
template <class T>
LinkedQueue<T>::~LinkedQueue() {
    Node<T>* actualNode = this->_front;
    Node<T>* nodeToDelete;
    //while actualNode is not null, delete and get the next node
    while (actualNode) {
        nodeToDelete = actualNode;
        actualNode = actualNode->getNext();
        delete nodeToDelete;
    }
    cout << "Estructura eliminada" << endl;
}

//On add, creates a new node with key and set it to the last node
template <class T>
void LinkedQueue<T>::enqueue(const T key) {
    Node<T>* newNode = new Node<T>(key);
    if (this->isEmpty()) {
        this->_front = newNode;
    } else {
        this->_rear->setNext(newNode);
    }
    this->_rear = newNode;
    cout << "Element " << key << " agregat" << endl;
    this->_size++;
}

//On remove, replace front to next node
template <class T>
void LinkedQueue<T>::dequeue() {
    if (!isEmpty()) {
        cout << "Element " << this->_front->getElement() << " elimnat" << endl;
        this->_front = this->_front->getNext();
        this->_size--;
    } else {
        throw invalid_argument("L’estructura està buida");
    }
}

//returns the front node, if is empty, throws an error
template <class T>
const T LinkedQueue<T>::getFront() {
    if (!isEmpty())
        return this->_front->getElement();
    throw invalid_argument("L’estructura està buida");
    return -1;
}

//Check if LinkedQueue is empty
template <class T>
bool LinkedQueue<T>::isEmpty() {
    if (this->_size == 0)
        return true;
    return false;
}

//On print, get each node and print his element
template <class T>
void LinkedQueue<T>::print() {
    Node<T>* actualNode = this->_front;
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
    Node <T>* actualNode = orig._front;
    this->_front = nullptr;
    this->_rear = nullptr;
    this->_size = 0;
    while (actualNode) {
        Node<T>* newNode = new Node<T>(actualNode->getElement());
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

