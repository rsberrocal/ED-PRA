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
#include <sstream>
#include <fstream>

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

void readFromFile(LinkedQueue* lQ) {
    ifstream file("flights.csv");
    string id, from, to, time, line;
    while (file.good()) {
        getline(file, id, ',');
        getline(file, from, ',');
        getline(file, to, ',');
        getline(file, time, '\n');
        try {
            Flight * f = new Flight(id, from, to, time);
            lQ->enqueue(f);
        } catch (invalid_argument &e) {
            cout << e.what() << endl;
        }
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    int opcio;
    string id, from, to, time;

    vector<string> arr_options = {
        "Llegir un fitxer amb les entrades de vols",
        "Eliminar un vol",
        "Inserir n entrades de vols des de teclat (0 per finalizar)",
        "Imprimir la cua de vols",
        "Sortir"
    };

    LinkedQueue lQueue;
    do {
        opcio = getOpcio(arr_options);
        switch (opcio) {
            case 1:
                readFromFile(&lQueue);
                cout << "Fitxer carregat al programa" << endl;

                break;
            case 2:
                try {
                    lQueue.dequeue();
                } catch (invalid_argument &e) {
                    cout << "EXCEPTION:" << e.what() << endl;
                }
                break;
            case 3:
                do {
                    cout << "Nou vol:" << endl;
                    cout << "Dona'm el id del vol" << endl;
                    cin >> id;
                    if (id == "0")
                        break;
                    cout << "Dona'm l'origen del vol" << endl;
                    cin >> from;
                    if (from == "0")
                        break;
                    cout << "Dona'm el desti del vol" << endl;
                    cin >> to;
                    if (to == "0")
                        break;
                    cout << "Dona'm el temps del vol" << endl;
                    cin >> time;
                    if (time == "0")
                        break;
                    try {
                        Flight* f = new Flight(id, from, to, time);
                        lQueue.enqueue(f);
                    } catch (invalid_argument &e) {
                        cout << "EXCEPTION:" << e.what() << endl;
                    }
                } while (true);
                break;
            case 4:
                lQueue.print();
                break;
        }
    } while (opcio != 5);

    return 0;
}

