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
}

Ellipse::Ellipse(const Ellipse& orig) {
}

Ellipse::~Ellipse() {
}

bool Ellipse::checkRadi(float r1) {

    if (r1 < 0.1) {
        throw std::invalid_argument(" Atencio: aquest valor no es acceptat ");
        return false;
    }
    return true;

}

float Ellipse::getArea(float r1, float r2) {
    try {
        if (this->checkRadi(r1) && this->checkRadi(r2))
            return 3.14 * r1 * r2;
    } catch (const std::invalid_argument& e) {
        std::cout << "Atencio: aquest valor no es acceptat" << std::endl;
        return -1;
    }
}

