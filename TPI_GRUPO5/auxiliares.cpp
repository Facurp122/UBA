//
// Este archivo contiene las definiciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con las 
// declaraciones de auxiliares.h
//

#include <iostream>

#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

bool coordenadaValida(int c, int n) {
    if(0<=c && c<n) {
        return true;
    } else {
        return false;
    }
}

bool posicionValida(pos p, int n) {
    if(coordenadaValida(p.first, n) && coordenadaValida(p.second, n)) {
        return true;
    } else {
        return false;
    }
}

int numeroDeMinas(tablero t) { // Al tener un for dentro de otro for que dependen de la longitud del tablero. Tomando t = |t|, la complejidad temporal de esta función nos queda O(t^2)
    int minas = 0;
    for (int i = 0; i < t.size(); i++) {
        for (int j = 0; j < t.size(); j++) {
            if (t[i][j]) {
                minas = minas + 1;
            }
        }
    }
    return minas;
}
bool hayminaEnjugadas (tablero t , jugadas j,bool res){
    for(int i = 0; (i < j.size()); i++){
        pos p = j[i].first;
        if (t[p.first][p.second]){
            res = true;
        }
    }
    return res;
}
void sinMinasAdjRecur (tablero& t, banderitas& b, pos p, jugadas& j){
    j.push_back (jugada(p,0));
    for(int i = p.first - 1; i <= p.first + 1;i++){
        for(int k =p.second-1;k<=p.second+1;k++ ){
            pos pAdj =pos  (i,k);
            if(posicionValida(pAdj,t.size())){
                if(esBandera(pAdj,b) || esJugada(pAdj,j)){ //esBandera y esJugada son O(n)
                    continue;
                }
                else if(minasAdyacentes(t,pAdj) != 0){ //minasAdyacentes es O(1)
                    j.push_back(jugada(pAdj, minasAdyacentes(t,pAdj)));

                }
                else if (minasAdyacentes(t,pAdj) == 0){
                    sinMinasAdjRecur(t,b,pAdj,j);
                }

            }
        }
    }
}
bool esta121EnHorizontal (tablero t ,jugadas j,banderitas b,pos &p){//O(n^2)
    bool res = false;
    for (int i = 0; i<j.size() ; i++){
        if (j[i].second == 2){
            pos p2 = j[i].first;
            pos p1 =pos (p2.first,p2.second - 1);
            pos p3 = pos (p2.first,p2.second + 1);
            if(!posicionValida(p1,t.size()) || !posicionValida(p3,t.size())) {
                continue;
            } else if ((!esBandera(p1,b) && esJugada(p1,j) &&
                        (numMinasDeEsaPosEnJugadas(p1,j) == 1)) && (!esBandera(p3,b) && esJugada(p3,j) &&
                                                                    (numMinasDeEsaPosEnJugadas(p3,j) == 1))){
                int px = p2.first;
                int py = p2.second;
                pos px1 = pos(px-1,py);
                pos px2 = pos(px+1,py);
                if((posicionValida(px1,t.size()) && !esJugada(px1,j) &&(!esBandera(px1,b) )) || (posicionValida(px2,t.size()) && !esJugada(px2,j) && !esBandera(px2,b))){
                    res = true;
                    p = pos(px,py);
                }
            }else{
                continue;
            }

        }
    }
    return res;
}

bool esta121EnVertical (tablero t ,jugadas j,banderitas b,pos &p){
    bool res = false;
    for (int i = 0; i<j.size() ; i++){ // en el peor caso de recorrer todas las jugadas la complejidad seria O(t^2)
        if (j[i].second == 2){
            pos p2 = j[i].first;
            pos p1 =pos (p2.first - 1,p2.second);
            pos p3 = pos (p2.first + 1,p2.second);
            if(!posicionValida(p1,t.size()) || !posicionValida(p3,t.size())) {
                continue;
            }
            else if ((!esBandera(p1,b) && esJugada(p1,j) &&
                      (numMinasDeEsaPosEnJugadas(p1,j) == 1)) && (!esBandera(p3,b) && esJugada(p3,j) &&
                                                                  (numMinasDeEsaPosEnJugadas(p3,j) == 1))){
                int px = p2.first;
                int py = p2.second;
                pos px1 = pos(px,py-1);
                pos px2 = pos(px,py+1);
                if((posicionValida(px1,t.size()) && !esJugada(px1,j) && (!esBandera(px1,b))) || (posicionValida(px1,t.size()) && !esJugada(px2,j) && !esBandera(px2,b))){
                    res = true;
                    p = pos(px,py);
                }
            }else{
                continue;
            }
        }
    }
    return res;
}








int numMinasDeEsaPosEnJugadas (pos p,jugadas j){ //Complejidad temporal : O(n)
    for (int i = 0; i < j.size(); i++) {
        if (j[i].first == p){
            return j[i].second;
        }
    }
}




bool esBandera(pos p ,banderitas b){ //Complejidad temporal : O(n)
    bool res = false;
    for(int i=0;i<b.size();i++){
        if (b[i] == p){
            res =true;
        }
    }
    return res ;
}
bool esJugada(pos p , jugadas j) { //Complejidad temporal : O(n)
    bool res = false;
    for (int i = 0; i < j.size(); i++) {
        if (j[i].first == p) {
            res = true;
        }
    }
    return res;
}