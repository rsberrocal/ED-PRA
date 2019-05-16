/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeMountain.cpp
 * Author: rsudarbe117.alumnes
 * 
 * Created on 16 / de maig / 2019, 11:26
 */

#include "NodeMountain.h"

NodeMountain::NodeMountain() {
}

NodeMountain::NodeMountain(const NodeMountain& orig) {
}

NodeMountain::~NodeMountain() {
}

NodeMountain::NodeMountain(int key, string name, int height) {
    this->key = key;
    this->name = name;
    this->height = height;
}

int NodeMountain::getHeight() {
    return this->height;
}

int NodeMountain::getKey() {
    return this->key;
}

string NodeMountain::getName() {
    return this->name;
}

void NodeMountain::setHeight(int h) {
    this->height = h;
}

void NodeMountain::setKey(int k) {
    this->key = k;
}

void NodeMountain::setName(string n) {
    this->name = n;
}



