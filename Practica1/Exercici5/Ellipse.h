/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.h
 * Author: hmarkus
 *
 * Created on February 21, 2019, 1:13 PM
 */

#ifndef ELLIPSE_H
#define ELLIPSE_H

class Ellipse {
public:
    float r1,r2;
    
    Ellipse();
    Ellipse(const Ellipse& orig);
    virtual ~Ellipse();
    virtual bool checkRadi(float radi);
    virtual float getArea(float radi1,float radi2);
    
private:

};

#endif /* ELLIPSE_H */

