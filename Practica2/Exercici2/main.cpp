/* 
 * File:   main.cpp
 * Author: Rocho
 *
 * Created on 13 de marzo de 2019, 0:41
 */

#include <cstdlib>
#include <iostream>
#include <vector>

#include "LinkedQueue.h"


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
    LinkedQueue<int> prova1;
    try {
        prova1.enqueue(10);
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        prova1.enqueue(20);
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        prova1.enqueue(30);
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        prova1.enqueue(40);
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        prova1.print();
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        prova1.dequeue();
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        prova1.enqueue(40);
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        prova1.print();
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {

    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
}

void casProva2() {
    LinkedQueue<int> prova2;
    try {
        prova2.enqueue(10);
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        prova2.enqueue(20);
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        prova2.enqueue(30);
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        prova2.print();
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        prova2.dequeue();
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        cout << prova2.getFront() << endl;
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        prova2.dequeue();
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        prova2.dequeue();
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    try {
        prova2.print();
    } catch (invalid_argument &e) {
        cout << "EXCEPTION:" << e.what() << endl;
    }
}

int main(int argc, char** argv) {
    int opcio;
    int key;

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

    LinkedQueue<int> lQueue;
    do {
        opcio = getOpcio(arr_options);
        switch (opcio) {
            case 1:
                cout << "Dona'm un element a afegir" << endl;
                cin >> key;
                try {
                    lQueue.enqueue(key);
                } catch (invalid_argument &e) {
                    cout << "EXCEPTION:" << e.what() << endl;
                }
                break;
            case 2:
                try {
                    lQueue.dequeue();
                } catch (invalid_argument &e) {
                    cout << "EXCEPTION:" << e.what() << endl;
                }
                break;
            case 3:
                try {
                    cout << "El primer element es " << lQueue.getFront() << endl;
                } catch (invalid_argument &e) {
                    cout << "EXCEPTION:" << e.what() << endl;
                }
                break;
            case 4:
                lQueue.print();
                break;
        }
    } while (opcio != 5);
    //delete &lQueue;
    return 0;
}



