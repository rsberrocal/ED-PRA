/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rsudarbe117.alumnes
 *
 * Created on 16 / de maig / 2019, 09:39
 */

#include <cstdlib>

#include "MaxHeap.h"
#include "NodeMountain.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    MaxHeap<NodeMountain> m;
    NodeMountain* tmp;
    NodeMountain* mountain1 = new NodeMountain(10, "eqwe", 3213);
    NodeMountain* mountain2 = new NodeMountain(12, "eqwe", 3300);
    NodeMountain* mountain3 = new NodeMountain(14, "eqwe", 3500);
    NodeMountain* mountain4 = new NodeMountain(15, "eqwe", 2800);
    NodeMountain* mountain5 = new NodeMountain(20, "eqwe", 1300);
    m.insert(10, mountain1);
    m.insert(12, mountain2);
    m.insert(14, mountain3);
    m.insert(15, mountain4);
    tmp = m.parent(2);
    int x = tmp->getKey();
    m.insert(20, mountain5);
    return 0;
}

