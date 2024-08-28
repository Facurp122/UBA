
//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

bool hayminaEnjugadas(tablero t, jugadas j,bool res);
bool coordenadaValida(int c, int n);
bool posicionValida(pos p, int n);
int numeroDeMinas(tablero t);
void sinMinasAdjRecur (tablero& t, banderitas& b, pos p, jugadas& j);
bool esta121EnHorizontalSinp (tablero t ,jugadas j,banderitas b);
bool esta121EnVerticalSinp (tablero t ,jugadas j,banderitas b);
bool esta121EnHorizontal (tablero t ,jugadas j,banderitas b,pos &p);
bool esta121EnVertical (tablero t ,jugadas j,banderitas b,pos &p);
int numMinasDeEsaPosEnJugadas (pos p,jugadas j);
bool esBandera(pos p ,banderitas b);
bool esJugada(pos p, jugadas j);