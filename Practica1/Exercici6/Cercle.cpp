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

Cercle::Cercle() : Ellipse() {
    std::cout << "Soc el constructor de Cercle" << std::endl;
}

Cercle::Cercle(const Cercle& orig) {
}

Cercle::~Cercle() {
}

bool Cercle::checkRad(float rad) {

    if (rad < 0.1) {
        throw std::invalid_argument(" Atencio: aquest valor no es acceptat ");
        return false;
    }
    return true;

}

void Cercle::setRad(float rad) {
    this->r1 = rad;
    this->r2 = rad;
}

