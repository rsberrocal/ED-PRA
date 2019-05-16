/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeMountain.h
 * Author: rsudarbe117.alumnes
 *
 * Created on 16 / de maig / 2019, 11:26
 */

#ifndef NODEMOUNTAIN_H
#define NODEMOUNTAIN_H

#include <string>
#include <vector>

using namespace std;

class NodeMountain {
public:
    NodeMountain();
    NodeMountain(int key, string name, int height);
    NodeMountain(const NodeMountain& orig);
    virtual ~NodeMountain();
    int getKey();
    string getName();
    int getHeight();
    void setKey(int k);
    void setName(string n);
    void setHeight(int h);
private:
    int key;
    string name;
    int height;
};

#endif /* NODEMOUNTAIN_H */

