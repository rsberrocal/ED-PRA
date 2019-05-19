/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Rocho
 *
 * Created on 28 de abril de 2019, 20:06
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

#include "BSTMountainFinder.h"

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
    if (opcion > options.size() || opcion < 1) {
        cout << "Opció no valida" << endl;
    }
    return opcion;
}

void insertMountains(BSTMountainFinder* bts) {
    string p = "Mountain_list_small.txt";
    string g = "Mountain_list.txt";
    string option;
    cout << "Quin fitxer vols (P/G)?" << endl;
    cin >> option;
    if (option == "p") {
        bts->appendMountains(p);
    } else {
        bts->appendMountains(g);
    }

}

void showMountainByID(BSTMountainFinder* bts) {
    cout << "Dona'm ID" << endl;
    int id;
    cin >> id;
    bts->printMountainsByID(id);
}

int main(int argc, char** argv) {
    BSTMountainFinder* btsMountain = new BSTMountainFinder();
    int opcio;
    vector<string> arr_options = {"Inserir Muntanyes", "Mostrar arbre segons ID", "Cercar Muntanyes", "Profunditat de l'arbre", "Sortir"};

    do {
        opcio = getOpcio(arr_options);
        switch (opcio) {
            case 1:
                insertMountains(btsMountain);
                break;
            case 2:
                showMountainByID(btsMountain);
                break;
            case 3:
                //
                break;
            case 4:
                //Profunditat
                break;
        }
    } while (opcio != 5);

    return 0;
}

