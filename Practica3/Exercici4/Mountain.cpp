/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mountain.cpp
 * Author: Rocho
 * 
 * Created on 28 de abril de 2019, 20:13
 */

#include "Mountain.h"

#include <string>
using namespace std;

Mountain::Mountain(int id, string name, int height) {
    this->ID = id;
    this->name = name;
    this->height = height;
}

Mountain::Mountain(const Mountain& orig) {
}

Mountain::~Mountain() {
}

void Mountain::setId(int id) {
    this->ID = id;
}

int Mountain::getId() {
    return this->ID;
}

void Mountain::setName(string name) {
    this->name = name;
}

string Mountain::getName() {
    return this->name;
}

int Mountain::getHeight() {
    return this->height;
}

void Mountain::setHeight(int height) {
    this->height = height;
}

string Mountain::toString() {
    return to_string(this->getId()) + "::" + this->getName() + "::" + to_string(this->getHeight());
}


