/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flight.cpp
 * Author: Rocho
 * 
 * Created on 17 de marzo de 2019, 13:44
 */

#include "Flight.h"

Flight::Flight() {
}

Flight::Flight(const Flight& orig) {
}

Flight::~Flight() {
}

string Flight::getFrom() {
    return this->_from;
}

string Flight::getId() {
    return this->_id;
}

string Flight::getTime() {
    return this->_time;
}

string Flight::getTo() {
    return this->_to;
}

void Flight::setFrom(string from) {
    this->_from = from;
}

void Flight::setId(string id) {
    this->_id = id;   
}

void Flight::setTime(string time) {
    this->_time = time;    
}

void Flight::setTo(string to) {
    this->_to = to;
}
