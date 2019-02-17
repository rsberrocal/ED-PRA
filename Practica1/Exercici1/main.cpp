/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hmarkus
 *
 * Created on February 16, 2019, 7:45 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */


int main(int argc, char** argv) {
    string name;
    int opcion;
    string arr_options[] = {"Sortir", "Benvinguda"};

    cout << "Hola, com et dius?" << endl;
    cin >> name;
    cout << "Hola, " << name << ", que vols fer?" << endl;

    do {
        for (int i = 0; i<sizeof(arr_options)/sizeof(*arr_options); i++) {            
            cout << i + 1 << ". " << arr_options[i] << endl;
        }
        cin >> opcion;
        if(opcion==2){
            cout << "Benvingut/da a l'assignatura d'estructura de dades " << name << endl; 
        }
    } while (opcion!=1);
    /*
     *Los ficheros que hay son el main principal, que es donde se encuentra este codigo,
     *el fichero Makefile, que dice como se tiene que compilar,
     *el fichero stackdump, donde se recogen los datos cuando sucede un error.
     */
    return 0;
}