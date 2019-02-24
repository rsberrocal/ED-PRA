/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.cpp
 * Author: hmarkus
 * 
 * Created on February 21, 2019, 1:13 PM
 */

#include "Ellipse.h"
#include <stdexcept>
#include <iostream>

Ellipse::Ellipse() {
    this->r1 = 0;
    this->r2 = 0;
    std::cout << "Soc el constructor de Ellipse " << std::endl;
}

Ellipse::Ellipse(const Ellipse& orig) {
}

Ellipse::~Ellipse() {
    std::cout << "Soc el destructor de Cercle " << std::endl;
}

bool Ellipse::checkRadi(float r1) {

    if (r1 < 0.1) {
        throw std::invalid_argument(" Atencio: aquest valor no es acceptat ");
        return false;
    }
    return true;

}

void Ellipse::setRad(float r1, float r2) {
    this->r1 = r1;
    this->r2 = r2;
}

float Ellipse::getArea() {
    try {
        if (this->checkRadi(this->r1) && this->checkRadi(this->r2))
            return 3.14 * this->r1 * this->r2;
    } catch (const std::invalid_argument& e) {
        std::cout << "Atencio: aquest valor no es acceptat" << std::endl;
        return -1;
    }
}

