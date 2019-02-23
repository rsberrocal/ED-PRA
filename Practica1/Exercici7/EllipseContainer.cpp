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
    /*this->MAX_FIGURES = 10;
    vector<Ellipse> e(10);
    this->arrayEllipse = e*/;
}

EllipseContainer::EllipseContainer(const EllipseContainer& orig) {
}

EllipseContainer::~EllipseContainer() {
}

void EllipseContainer::addEllipse(Ellipse e) {
    this->arrayEllipse.push_back(e);
}

float EllipseContainer::getAreas() {
    float res = 0;
    for (int i = 0; i < this->arrayEllipse.size(); i++) {
        cout << endl << "Atencio:" << this->arrayEllipse.size() << endl;
        res = res + (this->arrayEllipse[i].r1 * this->arrayEllipse[i].r2 * 3.14);
    }
    return res;
}

