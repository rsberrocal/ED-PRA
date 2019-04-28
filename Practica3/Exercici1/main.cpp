/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rsudarbe117.alumnes
 *
 * Created on 25 / d’abril / 2019, 11:35
 */

#include <cstdlib>

#include "BST.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    /* CAS DE PROVA */
    BST<int> bts;
    int testArray [] = {2,0,8,45,76,5,3,40};
    for(int i = 0; i<8;i++){
        bts.insert(testArray[i]);
    }     
    
    bts.showPreorder();
    bts.showInorder();
    bts.showPostorder();
    bts.showLeafNodes();
    return 0;
}

