#include <iostream>
#include "Racional.h"

using namespace std;

int menu();

int main(int argc, char const *argv[]) {
    int opcion = 0;
    int numerador1 = 0, numerador2 = 0, denominador1 = 1, denominador2 = 1, entero = 0;
    int denominador1Temp = 1, denominador2Temp = 1;
    int suma = 0, resta = 0, multiplicacion = 0;
    int denominadorComun = 1;
    int* numeros = new int[2];
    Racional r;
    for (;opcion != 6;) {
        opcion = menu();
        if (opcion == 1) {
            cout << "Ingrese el valor del entero:";
            cin >> entero;
            cout << endl << "Ingrese el numerador del racional:";
            cin >> numerador1;
            cout << endl << "Ingrese el denominador del racional:";
            cin >> denominador1;
            if (denominador1 == 0) {
                for (;denominador1 == 0;) {
                    cout << "Lo sentimos, no puede ingresar 0 como denominador." << endl;
                    cout << "Ingrese el denominador del racional:";
                    cin >> denominador1;
                }//Fin del for
                cout << endl;
            }//Fin del if
            numeros = r.SimplificarFracciones(numerador1, denominador1);
            numerador1 = numeros[0];
            denominador1 = numeros[1];
            if (denominador1 < 0) {
                denominador1 = denominador1 * -1;
                entero = entero * denominador1;
                suma = entero - numerador1;
            } else {
                entero = entero * denominador1;
                suma = entero + numerador1;
            }//Fin del if
            cout << "La suma del entero y el racional da el siguiente resultado:" << endl;
            cout << suma << " / " << denominador1 << endl;
        }//Fin del if opcion 1

        if (opcion == 2) {
            cout << "Ingrese el numerador del primer racional:";
            cin >> numerador1;
            cout << endl << "Ingrese el denominador del primer racional:";
            cin >> denominador1;
            if (denominador1 == 0) {
                for (;denominador1 == 0;) {
                    cout << "Lo sentimos, no puede ingresar 0 como denominador." << endl;
                    cout << "Ingrese el denominador del primer racional:";
                    cin >> denominador1;
                }//Fin del for
                cout << endl;
            }//Fin del if
            cout << "Ingrese el numerador del segundo racional:";
            cin >> numerador2;
            cout << endl << "Ingrese el denominador del segundo racional:";
            cin >> denominador2;
            if (denominador2 == 0) {
                for (;denominador2 == 0;) {
                    cout << "Lo sentimos, no puede ingresar 0 como denominador." << endl;
                    cout << "Ingrese el denominador del segundo racional:";
                    cin >> denominador2;
                }//Fin del for
                cout << endl;
            }//Fin del if
            //Simplificar Fracciones
            numeros = r.SimplificarFracciones(numerador1, denominador1);
            numerador1 = numeros[0];
            denominador1 = numeros[1];
            numeros = r.SimplificarFracciones(numerador2, denominador2);
            numerador2 = numeros[0];
            denominador2 = numeros[1];
            //Denominador comun
            denominadorComun = r.ComunDenominador(denominador1, denominador2);
            denominador1Temp = denominador1;
            denominador2Temp = denominador2;
            denominador1 = denominadorComun;
            denominador2 = denominadorComun;
            numerador1 = (denominador1 / denominador1Temp) * numerador1;
            numerador2 = (denominador2 / denominador2Temp) * numerador2;
            suma = numerador1 + numerador2;
            numeros = r.SimplificarFracciones(suma, denominador1);
            if ((numeros[0] == 1) && (numeros[1] == 1)) {
                cout << "La suma de los racionales da el siguiente resultado:" << endl;
                cout << "1" << endl;
            } else if (numeros[1] == 1) {
                cout << "La suma de los racionales da el siguiente resultado:" << endl;
                cout << numeros[0] << endl;
            } else if (suma == 0) {
                cout << "La suma de los racionales da el siguiente resultado:" << endl;
                cout << "0" << endl;
            } else {
                cout << "La suma de los racionales da el siguiente resultado:" << endl;
                cout << suma << " / " << denominador1 << endl;
            }//Fin de la condicion
        }//Fin del if opcion 2

        if (opcion == 3) {
            cout << "Ingrese el numerador del primer racional:";
            cin >> numerador1;
            cout << endl << "Ingrese el denominador del primer racional:";
            cin >> denominador1;
            if (denominador1 == 0) {
                for (;denominador1 == 0;) {
                    cout << "Lo sentimos, no puede ingresar 0 como denominador." << endl;
                    cout << "Ingrese el denominador del primer racional:";
                    cin >> denominador1;
                }//Fin del for
                cout << endl;
            }//Fin del if
            cout << "Ingrese el numerador del segundo racional:";
            cin >> numerador2;
            cout << endl << "Ingrese el denominador del segundo racional:";
            cin >> denominador2;
            if (denominador2 == 0) {
                for (;denominador2 == 0;) {
                    cout << "Lo sentimos, no puede ingresar 0 como denominador." << endl;
                    cout << "Ingrese el denominador del segundo racional:";
                    cin >> denominador2;
                }//Fin del for
                cout << endl;
            }//Fin del if
            if ((numerador1 == numerador2) && (denominador1 == denominador2)) {
                cout << "La resta de los racionales da el siguiente resultado:" << endl;
                cout << "0" << endl;
            } else {
                //Simplifica fracciones
                numeros = r.SimplificarFracciones(numerador1, denominador1);
                numerador1 = numeros[0];
                denominador1 = numeros[1];
                numeros = r.SimplificarFracciones(numerador2, denominador2);
                numerador2 = numeros[0];
                denominador2 = numeros[1];
                //Denominador comun
                denominadorComun = r.ComunDenominador(denominador1, denominador2);
                denominador1Temp = denominador1;
                denominador2Temp = denominador2;
                denominador1 = denominadorComun;
                denominador2 = denominadorComun;

                numerador1 = (denominador1 / denominador1Temp) * numerador1;
                numerador2 = (denominador2 / denominador2Temp) * numerador2;
                if ((numerador1 < 0) || (numerador2 < 0) || (denominador1 < 0) || (denominador2 < 0)) {
                    resta = numerador1 + numerador2;
                } else {
                    resta = numerador1 - numerador2;
                }//Fin de la validacion
                numeros = r.SimplificarFracciones(resta, denominador1);
                resta = numeros[0];
                denominador1 = numeros[1];
                if (resta == 0) {
                    cout << "La resta de los racionales da el siguiente resultado:" << endl;
                    cout << "0" << endl;
                } else {
                    cout << "La resta de los racionales da el siguiente resultado:" << endl;
                    cout << resta << " / " << denominador1 << endl;
                }//Fin de la condicion
            }
        }//Fin del if opcion 3

        if (opcion == 4) {
            cout << "Ingrese el numerador del primer racional:";
            cin >> numerador1;
            cout << endl << "Ingrese el denominador del primer racional:";
            cin >> denominador1;
            if (denominador1 == 0) {
                for (;denominador1 == 0;) {
                    cout << "Lo sentimos, no puede ingresar 0 como denominador." << endl;
                    cout << "Ingrese el denominador del primer racional:";
                    cin >> denominador1;
                }//Fin del for
                cout << endl;
            }//Fin del if
            cout << "Ingrese el numerador del segundo racional:";
            cin >> numerador2;
            if (numerador2 == 0) {
                for (;numerador2 == 0;) {
                    cout << "Lo sentimos, no puede ingresar 0 como numerador en este caso." << endl;
                    cout << "Ingrese el numerador del segundo racional:";
                    cin >> numerador2;
                }//Fin del for
                cout << endl;
            }//Fin del if
            cout << endl << "Ingrese el denominador del segundo racional:";
            cin >> denominador2;
            cout << endl;
            if (denominador2 == 0) {
                for (;denominador2 == 0;) {
                    cout << "Lo sentimos, no puede ingresar 0 como denominador." << endl;
                    cout << "Ingrese el denominador del segundo racional:";
                    cin >> denominador2;
                }//Fin del for
                cout << endl;
            }//Fin del if
            //Simplifica fracciones
            if (numerador1 == 0) {
                cout << "La division de los racionales da el siguiente resultado:" << endl;
                cout << "0" << endl;
            } else {
                numeros = r.SimplificarFracciones(numerador1, denominador1);
                numerador1 = numeros[0];
                denominador1 = numeros[1];
                numeros = r.SimplificarFracciones(numerador2, denominador2);
                numerador2 = numeros[0];
                denominador2 = numeros[1];
                //Denominador comun
                denominadorComun = r.ComunDenominador(denominador1, denominador2);
                denominador1Temp = denominador1;
                denominador2Temp = denominador2;

                denominador1 = denominadorComun;
                denominador2 = denominadorComun;

                numerador1 = numerador1 * denominador2;
                denominador1 = denominador1 * numerador2;

                if ((denominador1Temp < 0) || (denominador2Temp < 0)) {
                    denominador1 = denominador1 * -1;
                }
                numeros = r.SimplificarFracciones(numerador1, denominador1);
                numerador1 = numeros[0];
                denominador1 = numeros[1];
                if ((numerador1 == 1) && (denominador1 == 1) ) {
                    cout << "La division de los racionales da el siguiente resultado:" << endl;
                    cout << "1" << endl;
                } else if (((numerador1 == -1) && (denominador1 == 1))) {
                    cout << "La division de los racionales da el siguiente resultado:" << endl;
                    cout << "-1" << endl;
                } else if ((numerador1 == 1) && (denominador1 == -1)) {
                    cout << "La division de los racionales da el siguiente resultado:" << endl;
                    cout << "-1" << endl;
                } else {
                    cout << "La division de los racionales da el siguiente resultado:" << endl;
                    cout << numerador1 << " / " << denominador1 << endl;
                }//Fin de la condicion
            }
        }//Fin del if opcion 4

        if (opcion == 5) {
            cout << "Ingrese el numerador del primer racional:";
            cin >> numerador1;
            cout << endl << "Ingrese el denominador del primer racional:";
            cin >> denominador1;
            if (denominador1 == 0) {
                for (;denominador1 == 0;) {
                    cout << "Lo sentimos, no puede ingresar 0 como denominador." << endl;
                    cout << "Ingrese el denominador del primer racional:";
                    cin >> denominador1;
                }//Fin del for
                cout << endl;
            }//Fin del if
            cout << "Ingrese el numerador del segundo racional:";
            cin >> numerador2;
            cout << endl << "Ingrese el denominador del segundo racional:";
            cin >> denominador2;
            if (denominador2 == 0) {
                for (;denominador2 == 0;) {
                    cout << "Lo sentimos, no puede ingresar 0 como denominador." << endl;
                    cout << "Ingrese el denominador del segundo racional:";
                    cin >> denominador2;
                }//Fin del for
                cout << endl;
            }//Fin del if
            //Simplifica fracciones
            if ((numerador1 == 0) || (numerador2 == 0)) {
                cout << "La multiplicacion de los racionales da el siguiente resultado:" << endl;
                cout << "0" << endl;
            } else {
                numeros = r.SimplificarFracciones(numerador1, denominador1);
                numerador1 = numeros[0];
                denominador1 = numeros[1];
                numeros = r.SimplificarFracciones(numerador2, denominador2);
                numerador2 = numeros[0];
                denominador2 = numeros[1];
                //Denominador comun
                denominadorComun = r.ComunDenominador(denominador1, denominador2);
                denominador1Temp = denominador1;
                denominador2Temp = denominador2;

                denominador1 = denominadorComun;
                denominador2 = denominadorComun;

                numerador1 = numerador1 * numerador2;
                denominador1 = denominador1 * denominador2;

                if ((denominador1Temp < 0) || (denominador2Temp < 0)) {
                    denominador1 = denominador1 * -1;
                }
                numeros = r.SimplificarFracciones(numerador1, denominador1);
                numerador1 = numeros[0];
                denominador1 = numeros[1];
                if ((numerador1 == 1) && (denominador1 == 1) ) {
                    cout << "La multiplicacion de los racionales da el siguiente resultado:" << endl;
                    cout << "1" << endl;
                } else if (((numerador1 == -1) && (denominador1 == 1))) {
                    cout << "La multiplicacion de los racionales da el siguiente resultado:" << endl;
                    cout << "-1" << endl;
                } else if ((numerador1 == 1) && (denominador1 == -1)) {
                    cout << "La multiplicacion de los racionales da el siguiente resultado:" << endl;
                    cout << "-1" << endl;
                } else {
                    cout << "La multiplicacion de los racionales da el siguiente resultado:" << endl;
                    cout << numerador1 << " / " << denominador1 << endl;
                }//Fin de la condicion
            }
        }//Fin del if opcion 5

        if (opcion == 6) {
            cout << "Gracias por usar la calculadora de Jose." << endl;
        }//Fin del if opcion 6
    }//For menu

    delete[] numeros;
    return 0;
}//Fin del main


int menu () {
    int opcion = 0;
    cout << "---------- Calculadora ----------" << endl;
    cout << "1. Sumar Entero con Racional." << endl;
    cout << "2. Sumar Racional con Racional." << endl;
    cout << "3. Restar Racional con Racional." << endl;
    cout << "4. Dividir Racional con Racional." << endl;
    cout << "5. Multiplicar Racional con Racional." << endl;
    cout << "6. Salir del programa." << endl;
    cout << endl;
    cout << "Ingrese su opcion:";
    cin >> opcion;
    if ((opcion <= 0) || (opcion > 6)) {
        for (;(opcion <= 0) || (opcion > 6);) {
            cout << "Lo sentimos, ingreso una opcion invalida." << endl;
            cout << "Ingrese su opcion:";
            cin >> opcion;
        }//Fin del for
    }//Fin del if verificacion
    cout << endl;
    return opcion;
}//Fin del menu
