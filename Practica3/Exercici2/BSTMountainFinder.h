/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BSTMountainFinder.h
 * Author: Rocho
 *
 * Created on 28 de abril de 2019, 20:14
 */

#ifndef BSTMOUNTAINFINDER_H
#define BSTMOUNTAINFINDER_H

#include <string>

#include "Mountain.h"
#include "BST.h"

using namespace std;

class BSTMountainFinder {
public:
    BSTMountainFinder();
    BSTMountainFinder(const BSTMountainFinder& orig);
    virtual ~BSTMountainFinder();
    void appendMountains(string fileName);
    void insertMountain(int mountainId, string name, int height);
    string showMountain(int mountainId);
    Mountain& findMountain(int mountainId);
private:
    BST<Mountain> tree;
};

#endif /* BSTMOUNTAINFINDER_H */

