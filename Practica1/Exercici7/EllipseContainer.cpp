/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EllipseContainer.cpp
 * Author: hmarkus
 * 
 * Created on February 23, 2019, 12:43 AM
 */

#include "EllipseContainer.h"
#include "Ellipse.h"
#include <vector>
#include <iostream>

using namespace std;

EllipseContainer::EllipseContainer() {
    this->MAX_FIGURES = 10;
}

EllipseContainer::EllipseContainer(const EllipseContainer& orig) {
}

EllipseContainer::~EllipseContainer() {
}

void EllipseContainer::addEllipse(Ellipse *e) {
    if (this->arrayEllipse.size()<this->MAX_FIGURES) {
        this->arrayEllipse.push_back(e);
    } else {
        std::cout << "Maxim de 10 figures " << endl;
    }
}

float EllipseContainer::getAreas() {
    float res = 0;
    for (int i = 0; i < this->arrayEllipse.size(); i++) {
        res = res + this->arrayEllipse[i]->r1 * this->arrayEllipse[i]->r2 * 3.14;
    }
    return res;
}

