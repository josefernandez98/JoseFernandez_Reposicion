#include <iostream>
#include "Racional.h"

using namespace std;

Racional::Racional() {
    numerador = 0;
    denominador = 1;
}//Fin del constructor

Racional::Racional(int numerador, int denominador) {
    this->numerador = numerador;
    this->denominador = denominador;
}//Fin del constructor

int Racional::ComunDenominador (int num1, int num2) {
    int mayor = 0;
    if (num1 > num2) {
        mayor = num1;
    } else {
        mayor = num2;
    }//Fin de la condicion
    int auxiliar = mayor;
    for (;(auxiliar % num1 != 0) || (auxiliar % num2 != 0);) {
        auxiliar+=1;
    }//Fin del for
    return auxiliar;
}//Fin del comun divisor

int Racional::MaximoComunDivisor (int num1, int num2) {
    int residuo = 1;
    for (int i = 1; i <= num1; i++) {
        if ((num1 % i == 0) && (num2 % i == 0)) {
            residuo = i;
        }//Fin del if
    }//Fin del for
    return residuo;
}//Fin del metodo


int* Racional::SimplificarFracciones (int num, int den) {
    int divisor = 0;
    int* numeros = new int[2];
    if (den % num == 0) {
        divisor = MaximoComunDivisor(num, den);
        num = num / divisor;
        den = den / divisor;
        numeros[0] = num;
        numeros[1] = den;
    } else {
        divisor = MaximoComunDivisor(num, den);
        num = num / divisor;
        den = den / divisor;
        numeros[0] = num;
        numeros[1] = den;
    }//Fin del if
    return numeros;
}//Fin del metodo


double Racional::operator+(int& der) {
    return this->numerador + der;
}//Fin del metodo

double Racional::operator-(int& der) {
    return this->numerador - der;
}//Fin del metodo

double Racional::operator*(int& der) {
    return this->numerador * der;
}//Fin del metodo

double Racional::operator/(int& der) {
    return this->numerador / der;
}//Fin del metodo
