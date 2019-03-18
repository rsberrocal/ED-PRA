/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Rocho
 *
 * Created on 17 de marzo de 2019, 12:34
 */

#include <cstdlib>
#include <iostream>
#include <vector>

#include "Flight.h"
#include "LinkedQueue.h"

using namespace std;

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

/*
 * 
 */
int main(int argc, char** argv) {
    int opcio;
    string id, from, to, time;

    vector<string> arr_options = {
        "Inserir un vol a la cua",
        "Treure un vol de la cua",
        "Consultar el primer vol",
        "Imprimir tot el contingut dels vols",
        "Sortir"
    };

    LinkedQueue<Flight> lQueue;
    do {
        opcio = getOpcio(arr_options);
        switch (opcio) {
            case 1:
                cout << "Dona'm el id del vol" << endl;
                cin >> id;
                cout << "Dona'm l'origen del vol" << endl;
                cin >> from;
                cout << "Dona'm el desti del vol" << endl;
                cin >> to;
                cout << "Dona'm el temps del vol" << endl;
                cin >> time;
                try {
                    Flight f(id, from, to, time);
                    lQueue.enqueue(f);
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
                    cout << "El primer element es " << lQueue.getFront().getId() << endl;
                } catch (invalid_argument &e) {
                    cout << "EXCEPTION:" << e.what() << endl;
                }
                break;
            case 4:
                lQueue.print();
                break;
        }
    } while (opcio != 5);

    return 0;
}

