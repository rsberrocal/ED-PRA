/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rsudarbe117.alumnes
 *
 * Created on 28 / de febrer / 2019, 12:16
 */

#include <cstdlib>
#include <iostream>
#include <vector>

#include "ArrayQueue.h"

using namespace std;

/*
 * 
 */
int getOpcio(vector<string> options) {
    int opcion = -1;
    for (int i = 0; i < options.size(); i++) {
        cout << i + 1 << ". " << options[i] << endl;
    }
    cin >> opcion;
    if (opcion < 0 || opcion > options.size()) {
        cout << "Opció no valida" << endl;
    }
    return opcion;
}

void casProva1() {
    try {
        ArrayQueue aQ(3);
        aQ.enqueue(10);
        aQ.enqueue(20);
        aQ.enqueue(30);
        aQ.enqueue(40); //Trhow exception
        aQ.print();
        aQ.dequeue();
        aQ.enqueue(40);
        aQ.print();
        delete &aQ;
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
}

void casProva2() {
    try {
        ArrayQueue aQ(3);
        aQ.enqueue(10);
        cout << aQ.getFront() << endl;
        aQ.enqueue(20);
        aQ.enqueue(30);        
        aQ.print();
        aQ.dequeue();
        cout << aQ.getFront() << endl;
        aQ.dequeue();
        aQ.dequeue();
        aQ.dequeue();//trhow exception
        aQ.print();
        delete &aQ;
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
}

int main(int argc, char** argv) {
    int opcio;
    vector<string> arr_options = {
        "Inserir element a la cua",
        "Treure element de la cua",
        "Consultar el primer element",
        "Imprimir tot el contingut de l'ArrayQueue",
        "Sortir"
    };
    /* PER AL CAS PROVA 1 */
    casProva1();
    /* PER AL CAS PROVA 2 */
    casProva2();
    
    do {
        opcio = getOpcio(arr_options);
        switch (opcio) {
            case 1:                
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
        }
    } while (opcio != 5);

    return 0;
}

