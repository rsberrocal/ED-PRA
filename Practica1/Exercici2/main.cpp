/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hmarkus
 *
 * Created on February 17, 2019, 12:33 PM
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
    string name;
    int opcio;
    vector<string> arr_options = {"Sortir", "Benvinguda", "Redefinir el nom"};

    cout << "Hola, com et dius?" << endl;
    cin >> name;
    cout << "Hola, " << name << ", que vols fer?" << endl;

    do {
        opcio = getOpcio(arr_options);
        switch (opcio) {
            case '1':
                break;
            case '2':
                cout << "Benvingut/da a l'assignatura d'estructura de dades " << name << endl;
                break;
            case '3':
                cout << "Tornam a dir el teu nom" << endl;
                cin >> name;
                break;
        }
    } while (opcio != 1);

    /*
     * Uno de los dudas que tengo es como validar que es numero, supongo que mas adelante lo sabre.
     */
    
    return 0;
}

