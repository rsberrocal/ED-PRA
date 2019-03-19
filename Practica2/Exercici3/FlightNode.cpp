/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "FlightNode.h"
#include "Flight.h"
#include <string>
#include <iostream>
using namespace std;

FlightNode::FlightNode() {

}

FlightNode::FlightNode(const FlightNode& orig) {

}

FlightNode::FlightNode(Flight* el) {
    this->element = el;
    this->next = nullptr;
}

Flight* FlightNode::getElement() const {
    return this->element;
}

FlightNode* FlightNode::getNext() const {
    return this->next;
}

void FlightNode::printNode() const {
    cout << this->element->getId() << "," << this->element->getFrom() << "," << this->element->getTo() << "," << this->element->getTime();
}

void FlightNode::setNext(FlightNode* n) {
    this->next = n;
}

FlightNode::~FlightNode() {

}
