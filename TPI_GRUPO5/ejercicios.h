//
// Este archivo contiene las declaraciones de las funciones (no el código).
// Tienen que coincidir exactamente con el código que se encuentra en ejercicios.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

int minasAdyacentes(tablero& t, pos p);
void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b);
bool perdio(tablero& t, jugadas& j);
bool gano(tablero& t, jugadas& j);
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j);//Al ser recursivo no se puede calcular bien la complejidad, la recursion se hace en base a si la posicion tiene 0 minas adyacentes,// con todos los lugares adyacentes a la pos dada, entonces si el tablero no tuviese minas que seria el peor caso , se repetiria n^2 donde n es t.size().
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p);
