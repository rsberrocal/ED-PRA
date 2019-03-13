/* 
 * File:   Node.cpp
 * Author: Rocho
 * 
 * Created on 13 de marzo de 2019, 0:56
 */

#include <stddef.h>

#include "Node.h"

Node::Node() {

}

Node::Node(int el) {
    this->element=el;
    this->next = nullptr;
}

Node::Node(const Node& orig) {
}

Node::~Node() {
}

Node* Node::getNext() const {
    return this->next;
}

void Node::setNext(Node* n) {
    this->next = n;
}

int Node::getElement() const {
    return this->element;
}

