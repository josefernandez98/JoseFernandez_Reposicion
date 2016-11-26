#pragma once
#include <iostream>

using namespace std;

class Racional {
    public:
        Racional();
        Racional(int, int);
        double operator+(int&);
        double operator-(int&);
        double operator*(int&);
        double operator/(int&);
        int ComunDenominador(int, int);
        int MaximoComunDivisor(int, int);
        int* SimplificarFracciones(int, int);
    private:
        int numerador;
        int denominador;
};
