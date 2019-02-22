/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cercle.cpp
 * Author: hmarkus
 * 
 * Created on February 21, 2019, 9:44 AM
 */

#include "Cercle.h"

#include <stdexcept>

Cercle::Cercle() {
}

Cercle::Cercle(const Cercle& orig) {
}

Cercle::~Cercle() {
}

bool Cercle::checkRadi(float radi) {

    if (radi < 0.1) {
        throw std::invalid_argument(" Atencio: aquest valor no es acceptat ");
        return false;
    }
    return true;

}

double Cercle::getArea(float rad) {
    try {
        if (this->checkRadi(rad))
            return 3.14 * rad * rad;        
    } catch (const std::invalid_argument& e) {
        std::cout << "Atencio: aquest valor no es acceptat" << std::endl;
        return -1;
    }
}
