//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <stdio.h>
#include <iostream>


#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"



using namespace std;

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/

// Complejidad temporal : O(1), ya que los "for" no dependen de la longitud del tablero t, en el peor caso va a recorrer los 8 lugares adyacentes a la posición que se le da a la función.

int minasAdyacentes(tablero& t, pos p) {
    int contador = 0;
    for (int i = p.first - 1; i <= p.first + 1 ; i++) {
        for (int j = p.second - 1; j <= p.second+1 ; j++) {
            if (i == p.first && j == p.second) {
                continue;
            }
            else if (posicionValida(pos (i, j), t.size())) {
                if (t[i][j]){
                    contador = contador + 1;
                }
            }
        }
    }
    return contador;
}






/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/
// Tomando, t = |t| (módulo de t)
// Complejidad temporal : O(t^2), ya que el "for" recorre la lista banderitas que en el peor caso puede llegar a ser la totalidad de casilleros del tablero menos algunos casilleros descubiertos.
// Pero estos casilleros ya descubiertos tienen complejidad O(1). Por lo que la cuenta nos queda, O(t^2) - O(1) = O(t^2) de complejidad.

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    int esta = 0;
    vector<pos> v ;
    for (int i = 0; i < b.size(); i++) {
        if(p != b[i]){
            v.push_back(b[i]);
        }
        else esta = esta +1;
    }
    if (esta == 0){
        v.push_back(p);
    }
    b = v ;
}


/******++++**************************** EJERCICIO perdio ***********+++***********************/
// Tomando, t = |t| (módulo de t)
// Complejidad temporal : O(t^2), ya que el "for" en el peor caso recorre la totalidad de casilleros(|t|*|t|), y dentro del ciclo realiza 12*t*t iteraciones. En el peor caso el cálculo de la función complejidad resulta
// 12*t*t + 2 lo cual tiene una complejidad de O(t*t)

bool perdio(tablero& t, jugadas& j) {
    bool res = false;
    for(int i = 0; (i < j.size() && !res); i++){ // este ciclo tiene 12 operaciones elementales sino contamos el res = true, el cual solo se ejecuta cuando hayamos la mina que nos hace perder.
        pos p = j[i].first;                      // por lo que tiene una complejidad de O(12*t^2)
        if (t[p.first][p.second]){
            res = true;
        }
    }
    return res;
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
// Tomando t = |t|
// Complejidad temporal : O(t^2) ya que numeroDeMinas tiene una complejidad temporal de O(t^2), y solo hay operaciones elementales de complejidad O(1) en el resto de la función, las cuales no incrementan la complejidad temporal.

bool gano(tablero& t, jugadas& j) {
    int minas = numeroDeMinas(t); //numeroDeMinas tiene complejidad O(t^2)
    bool res = false;
    if (((j.size() + minas) == (t.size() * t.size())) && !hayminaEnjugadas(t, j, res)) {
        res = true;
    }

    return res;
}


/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
// Complejidad temporal :
//Al ser recursivo no se puede calcular bien la complejidad, la recursion se hace en base a si la
// posicion tiene 0 minas adyacentes, con todos los lugares adyacentes a la pos dada, entonces si el tablero tuviese que seria el peor caso , se repetiria n^2 donde n es t.size().

void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    if (t[p.first][p.second]) {
        j.push_back(jugada(p, minasAdyacentes(t, p)));
    } else if(minasAdyacentes(t, p) != 0) {   //minasAdyacentes(t,p) es O(1)
        j.push_back(jugada(p, minasAdyacentes(t, p)));
    } else {
        sinMinasAdjRecur(t, b, p, j);
    }
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
// Tomando t = |t|.
// Complejidad temporal : O(t^2)

bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    pos p0 ;
    bool res = false;
if(esta121EnHorizontal(t,j,b,p0)){ //esta121EnHorizontal es O(t^2), ya que en el peor caso debe recorrer todas las jugadas que abarcarian todas las casillas por lo que la complejidad seria de t^2
    res=true;
    int px = p0.first;
    int py = p0.second;
    if(posicionValida(pos(px-1,py),t.size()) && (!esBandera(pos(px-1,py),b)) && (!esJugada(pos(px-1,py),j))){
        p = pos(px - 1,py);
    }
    else  if(posicionValida(pos(px+1,py),t.size()) && (!esBandera(pos(px+1,py),b)) && (!esJugada(pos(px+1,py),j))) {
        p = pos(px+1,py);
    }
}
else if (esta121EnVertical(t,j,b,p0)) {//esta121EnVertical es O(t^2) por lo mismo que esta121EnHorizontal.
    res = true;
    int px = p0.first;
    int py = p0.second;
    if (posicionValida(pos(px, py -1), t.size()) && (!esBandera(pos(px, py -1), b)) &&
        (!esJugada(pos(px, py -1), j))) {
        p = pos(px, py -1);
    } else if (posicionValida(pos(px, py + 1), t.size()) &&
               (!esBandera(pos(px, py + 1), b)) && (!esJugada(pos(px, py + 1), j))) {
        p = pos(px, py + 1);
    }

}
return res;
    }