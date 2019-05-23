/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mountain.h
 * Author: Rocho
 *
 * Created on 28 de abril de 2019, 20:13
 */

#ifndef MOUNTAIN_H
#define MOUNTAIN_H
#include <string>

using namespace std;

class Mountain {
public:
    Mountain(int id, string name, int height);
    Mountain(const Mountain& orig);
    virtual ~Mountain();
    int getId();
    string getName();
    int getHeight();
    void setId(int id);
    void setName(string name);
    void setHeight(int height);
    string toString();
private:
    int ID;
    string name;
    int height;

};

#endif /* MOUNTAIN_H */

