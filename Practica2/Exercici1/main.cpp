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
    ArrayQueue aQ(3);
    try {
        aQ.enqueue(10);
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        aQ.enqueue(20);
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        aQ.enqueue(30);
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        aQ.enqueue(40); //Trhow exception
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        aQ.print();
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        aQ.dequeue();
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        aQ.enqueue(40);
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        aQ.print();
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }

    delete &aQ;
}

void casProva2() {
    ArrayQueue aQ(3);
    try {
        aQ.enqueue(10);
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        cout << aQ.getFront() << endl;
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        aQ.enqueue(20);
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        aQ.enqueue(30);
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        aQ.print();
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        aQ.dequeue();
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        cout << aQ.getFront() << endl;
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        aQ.dequeue();
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        aQ.dequeue();
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        aQ.dequeue(); //trhow exception
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        aQ.print();
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    delete &aQ;
}

int main(int argc, char** argv) {
    int opcio;
    int key;
    ArrayQueue aQ(100);
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
                cout << "Dona'm un element a afegir" << endl;
                cin >> key;
                try {
                    aQ.enqueue(key);
                } catch (invalid_argument &e) {
                    cout << "EXCEPTION:" << e.what() << endl;
                }
                break;
            case 2:
                try {
                    aQ.dequeue();
                } catch (invalid_argument &e) {
                    cout << "EXCEPTION:" << e.what() << endl;
                }
                break;
            case 3:
                try {
                    cout << "El primer numero es " << aQ.getFront() << endl;
                } catch (invalid_argument &e) {
                    cout << "EXCEPTION:" << e.what() << endl;
                }
                break;
            case 4:
                aQ.print();
                break;
        }
    } while (opcio != 5);

    return 0;
}

