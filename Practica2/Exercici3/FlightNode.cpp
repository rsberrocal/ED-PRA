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

//Default constructor, copy constructor and delete

FlightNode::FlightNode() {

}

FlightNode::FlightNode(const FlightNode& orig) {

}

FlightNode::~FlightNode() {

}
//Constructor with Flight object

FlightNode::FlightNode(Flight* el) {
    this->element = el;
    this->next = nullptr;
}

//Returns the flight object

Flight* FlightNode::getElement() const {
    return this->element;
}

//Returns get next Node, last node returns nullptr

FlightNode* FlightNode::getNext() const {
    return this->next;
}

//Print each variable from Flight

void FlightNode::printNode() const {
    cout << "{" << this->element->getId() << "," << this->element->getFrom() << "," << this->element->getTo() << "," << this->element->getTime() << "}" ;
}

//Set next Node

void FlightNode::setNext(FlightNode* n) {
    this->next = n;
}


