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
#include <string>

using namespace std;

//Default constructor, copy constructor and delete
Flight::Flight() {
}

Flight::Flight(const Flight& orig) {
}

Flight::~Flight() {
}

//Constructor with all parameters
Flight::Flight(const string id, const string from, const string to, const string time) {
    this->_id = id;
    this->_from = from;
    this->_time = time;
    this->_to = to;
}

//Getters, setters
string Flight::getFrom()const {
    return this->_from;
}

string Flight::getId()const {
    return this->_id;
}

string Flight::getTime()const {
    return this->_time;
}

string Flight::getTo()const {
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
