/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EllipseContainer.h
 * Author: hmarkus
 *
 * Created on February 23, 2019, 12:43 AM
 */

#ifndef ELLIPSECONTAINER_H
#define ELLIPSECONTAINER_H

#include "Ellipse.h"
#include <vector>

using namespace std;

class EllipseContainer {
public:
    int MAX_FIGURES;
    vector <Ellipse> arrayEllipse;

    EllipseContainer();
    EllipseContainer(const EllipseContainer& orig);
    virtual ~EllipseContainer();
    virtual void addEllipse(Ellipse e);
    virtual float getAreas();
private:

};

#endif /* ELLIPSECONTAINER_H */

