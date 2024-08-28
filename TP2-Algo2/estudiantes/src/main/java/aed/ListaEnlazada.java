package aed;

import java.util.*;

//! Habría que agregar las complejidades a las operaciones

/*
ListaEnlazada

    - primero apunta al primer nodo de la lista o es nula si la lista está vacía.
    - último apunta al último nodo de la lista o es nula si la lista está vacía.
    - La longitud de la lista se almacena en longi.

    Dentro de nodo
    - En valor esta el valor almacenado
    - Cada nodo tiene una referencia al siguiente nodo o es nula si el nodo es el último.
    - Cada nodo tiene una referencia al nodo anterior o es nula si el nodo es el primero.
    
*/

public class ListaEnlazada<T> implements Secuencia<T> {
    private Nodo primero;
    private Nodo ultimo;
    private int longi;

    private class Nodo {
        T valor;
        Nodo sig;
        Nodo ant;

        Nodo(T v){valor = v;}
    }

    // Constructor
    // Complejidad: O(1)
    public ListaEnlazada() {
        primero = null;
        ultimo = null;
    }

    // Obtener la longitud de la lista
    // Complejidad: O(n), donde n es la longitud de la lista
    public int longitud() {
        longi = 0;
        if(primero == null && ultimo == null){
            return longi;
        } else {
            Nodo actual = primero;
            while(actual != null){
                actual = actual.sig;
                longi++;
            }
        }
        return longi;
    }

    //! En el caso general podría no ser O(1), pero ok   
    
    //En casos generales sería O(|T|), siento T el tipo
    //A partir de aca asumimos que la longitud del tipo esta acotada por lo que las operaciones de comparación y copia ocurren en O(1)

    // Agregar un elemento al frente de la lista
    // Complejidad: O(1)
    public void agregarAdelante(T elem) {
        Nodo nuevo = new Nodo(elem);
        if (longi == 0){
            nuevo.sig = null;
            nuevo.ant = null;
            ultimo = nuevo;
        } else {
            nuevo.sig = primero;
            primero.ant = nuevo;
            nuevo.ant = null;
        }
        primero = nuevo;
        longi++;
    }

    // Agregar un elemento al final de la lista
    // Complejidad: O(1)
    public void agregarAtras(T elem) {
        Nodo nuevo = new Nodo(elem);
        if (longi == 0){
            nuevo.sig = null;
            nuevo.ant = null;
            primero = nuevo;
        } else {
            ultimo.sig = nuevo;
            nuevo.sig = null;
            nuevo.ant = ultimo;
        }
        ultimo = nuevo;
        longi++;
    }

    // Obtener el elemento en la posición i
    // Complejidad: O(n), en el peor caso, recorre n nodos, siendo n la cantidad de elementos
    public T obtener(int i) {
        int posicion = 0;
            Nodo actual = primero;
            while(posicion != i){
                actual = actual.sig;
                posicion++;
            }
            return actual.valor;
        }
    
    // Eliminar el elemento en la posición i
    // Complejidad: O(n), en el peor caso, recorre n nodos, siendo n la cantidad de elementos
    public void eliminar(int i) {
        if (i == 0 && longi > 1){
            primero = primero.sig;
            primero.ant = null;
        } else if (longi == 1){
            primero = null;
            ultimo = null;
        } else {
            Nodo actual = primero;
            Nodo prev = primero;
            for(int j = 0; j < i; j++){
                prev = actual;
                actual = actual.sig;
            }
            if (actual.sig == null){
                prev.sig = null;
                ultimo = prev;
            } else {
            prev.sig = actual.sig;
            (actual.sig).ant = prev;
            }
        }
        longi--;
        }

    // Modificar el elemento en la posición i
    // Complejidad: O(n), en el peor caso, recorre n nodos, siendo n la cantidad de elementos
    public void modificarPosicion(int indice, T elem) {
        Nodo actual = primero;
        for(int j = 0; j < indice; j++){
                actual = actual.sig;
            }
        actual.valor = elem;
    }

    // Crear una copia de la lista
    // Complejidad: O(n), donde n es la longitud de la lista
    public ListaEnlazada<T> copiar() {
        ListaEnlazada<T> copiaLista = new ListaEnlazada<T>();
        copiaLista.primero = this.primero;
        copiaLista.ultimo = this.ultimo;
        copiaLista.longi = 0;
        for(int i = 0; i < this.longitud(); i++){
            copiaLista.agregarAtras(this.obtener(i));
        }
        return copiaLista;
    }

    // Constructor de copia
    // Complejidad: O(n), donde n es la longitud de la lista
    public ListaEnlazada(ListaEnlazada<T> lista) {
        primero = lista.primero;
        ultimo = lista.ultimo;
        longi = 0;
        for(int i = 0; i < lista.longitud(); i++){
            agregarAtras(lista.obtener(i));
        }
    }

    // Método toString para representar la lista como una cadena de caracteres
    // Complejidad: O(n), donde n es la longitud de la lista
    @Override
    public String toString() {
        Nodo actual = primero;
        String res = "[";
        for(int j = 0; j < this.longitud()-1; j++){
            res = res + actual.valor + ", ";
            actual = actual.sig;
            }
        res = res + actual.valor + "]";
        return res;
    }

    
    private class ListaIterador implements Iterador<T> {    //Todas las operaciones del iterador son O(1)
        private int lugar = 0;

        public boolean haySiguiente() {                     //O(1)
            return lugar != longi;                          
        }
        
        public boolean hayAnterior() {                      //O(1)
            return lugar != 0;                              
        }

        public T siguiente() {                              //O(1)
            int i = lugar;                                  
            lugar++;
            return obtener(i);
        }

        public T anterior() {                               //O(1)
            lugar--;
            return obtener(lugar);
        }
    }

    // Método para obtener un iterador de la lista
    // Complejidad: O(1)
    public Iterador<T> iterador() {
        Iterador <T> iter = new ListaIterador();
        return iter;
    }
}
