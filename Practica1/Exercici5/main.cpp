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
#include <fstream>

#include "Cercle.h"
#include "Ellipse.h"

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

void makeFigure(int *counterC, int *counterEl) {
    Cercle c;
    Ellipse e;
    string userInput;
    double area;
    string type;
    float r1, r2;
    cout << "Entra les dades de la teva figura (C o E, r1, r2, aquest ultim nomes en E)" << endl;
    cin >> type >> r1;
    if (type == "E") {
        cin >> r2;
        area = e.getArea(r1, r2);
        (*counterEl)++;
    } else if (type == "C") {
        area = c.getArea(r1);
        (*counterC)++;
    }
    if (area == -1) {
        cout << "S'ha produït una excepcio" << endl;
    } else {
        cout << "El area d'aquesta figura és de " << area << endl;
    }
}
getAreaCercle(float rad){
    //Cercle c;
    return Cercle.getArea(rad);
}

getAreaEllipse(float r1,float r2){
    return Ellipse.getArea(r1,r2);
}

void getTotalFigures(int *counterC, int *counterEl) {
    cout << "Tens " << *counterC << " Cercles i " << *counterEl << " El·lipses" << endl;
}

void getFileFigures() {
    std::ifstream file("figures.txt");
    std::string line;
    while (std::getline(file, line)) {
        if (line != "\r") {
            cout << "LA LINEA " << line << endl;            
        }
        // line contains the current line
    }
}

int main(int argc, char** argv) {
    string name;
    int opcio;
    int countCercle = 0;
    int countEl = 0;
    vector<string> arr_options = {"Sortir", "Afegir figura", "Glossari de figures", "Importar figures"};

    cout << "Hola, com et dius?" << endl;
    cin >> name;
    cout << "Hola, " << name << ", que vols fer?" << endl;

    do {
        opcio = getOpcio(arr_options);
        switch (opcio) {
            case 1:
                break;
            case 2:
                makeFigure(&countCercle, &countEl);
                break;
            case 3:
                getTotalFigures(&countCercle, &countEl);
                break;
            case 4:
                getFileFigures();
                break;
        }
    } while (opcio != 1);

    /*
     * Uno de los dudas que tengo es como validar que es numero, supongo que mas adelante lo sabre.
     */

    return 0;
}

