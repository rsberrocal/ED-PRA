/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cercle.h
 * Author: hmarkus
 *
 * Created on February 21, 2019, 9:44 AM
 */

#ifndef CERCLE_H
#define CERCLE_H
#include <iostream>
#include <cstdlib>

class Cercle {
public:
    Cercle();
    Cercle(const Cercle& orig);
    virtual ~Cercle();
    virtual bool checkRadi(double radi);
    virtual double getArea(double rad);
private:

};

#endif /* CERCLE_H */

