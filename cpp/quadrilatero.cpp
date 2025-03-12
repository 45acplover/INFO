#include "quadrilatero.h"
#include <iostream>
#include <cmath>

using namespace std;

// Costruttore predefinito
quadrilatero::quadrilatero() : lato1(0), lato2(0), lato3(0), lato4(0) {}

// Costruttore con parametri
Quadrilatero::Quadrilatero(double l1, double l2, double l3, double l4) 
    : lato1(l1), lato2(l2), lato3(l3), lato4(l4) {}

// Metodo per settare i lati (con parametri opzionali)
void Quadrilatero::setLati(double l1, double l2, double l3, double l4) {
    lato1 = l1;
    lato2 = l2;
    lato3 = l3;
    lato4 = l4;
}

// Metodo per ottenere il valore di tutti e 4 i lati
void Quadrilatero::getLati() const {
    cout << "Lato 1: " << lato1 << endl;
    cout << "Lato 2: " << lato2 << endl;
    cout << "Lato 3: " << lato3 << endl;
    cout << "Lato 4: " << lato4 << endl;
}

// Metodo per calcolare il perimetro
double Quadrilatero::calcolaPerimetro() const {
    return lato1 + lato2 + lato3 + lato4;
}