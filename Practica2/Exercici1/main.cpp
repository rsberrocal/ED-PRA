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
    if (opcion > 2 || opcion < 1) {
        cout << "Opció no valida" << endl;
    }
    return opcion;
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
    do {
        opcio = getOpcio(arr_options);
        switch (opcio) {
            case 1:
                break;
            case 2:
                break;
        }
    } while (opcio != 5);
    return 0;
}

