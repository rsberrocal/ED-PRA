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
    NodeMountain* mountain1 = new NodeMountain(10, "eqwe", 3213);
    NodeMountain* mountain2 = new NodeMountain(12, "eqwe", 3300);
    m.insert(10, mountain1);
    m.insert(12, mountain2);
    return 0;
}

