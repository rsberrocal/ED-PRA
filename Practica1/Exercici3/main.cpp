/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hmarkus
 *
 * Created on February 21, 2019, 9:41 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

#include "Cercle.h"

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

void makeCircle(int *counter) {
    Cercle c;
    int radi;

    cout << "Introdueix un radi" << endl;
    cin >> radi;
    cout << "El area d'aquest cercle és de " << c.getArea(radi) << endl;
    (*counter)++;
}

int main(int argc, char** argv) {
    string name;
    int opcio;
    int countCercle = 0;    
    vector<string> arr_options = {"Sortir", "Introduir cercle"};

    cout << "Hola, com et dius?" << endl;
    cin >> name;
    cout << "Hola, " << name << ", que vols fer?" << endl;

    do {
        opcio = getOpcio(arr_options);
        switch (opcio) {
            case 1:
                break;
            case 2:
                cout << "Cercle num " << countCercle << endl;
                makeCircle(&countCercle);
                break;
        }
    } while (opcio != 1);

    /*
     * Uno de los dudas que tengo es como validar que es numero, supongo que mas adelante lo sabre.
     */

    return 0;
}

