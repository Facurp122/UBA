package aed;
import java.util.*;

/*
InvRep Heap: 

    - Arbol perfectamente balanceado , izquierdista, en el cual los hijos son menores o iguales al padre.(cada subarbol es un heap). 
    - heapArr es un array con los elementos donde si n es un nodo y su posición es i, el hijo izquierdo de n estará en la posición 2i+1 y el derecho de n estará en la posición 2i+2.
    - partido es el array donde cada elemento contenido es el id del partido. Para todo índice i, partido[i] se refiere al mismo partido que heapArr[i]. Para todo i valido, 0 <= partido[i] < P-1. 
    - longitud es la longitud del array que ya queda inicializado con el tamaño dado.

*/

public class heap{
    private int[] heapArr;
    private int[] partido;
    private int longitud;

    // Constructor para inicializar un heap vacío con tamaño especificado.
    // Complejidad: O(tamaño)
    public heap(int tamaño){
        heapArr = new int[tamaño];
        partido = new int[tamaño];
        for (int i = 0; i < tamaño; i++)
        {
            heapArr[i] = 0;
            partido[i] = 0;
        } 
        longitud = tamaño - 1;
    }

    // Constructor para inicializar un heap a partir de un array existente.
    // Complejidad: O(tamaño * log(tamaño))
    public heap(int[] array)
    {
        heapArr = new int[array.length];
        partido = new int[array.length];
        for (int i = 0; i < heapArr.length; i++)
        {
            heapArr[i] = array[i];
            partido[i] = i;
        } 
        longitud = heapArr.length;
        construirHeap();
    }

    // Reemplaza el máximo elemento en el heap y ajusta para mantener la propiedad de max-heap.
    // Complejidad: O(log(tamaño))
    public void ReemplazarMaximo(int nuevo){      //me permite no cambiar el tamaño del array
        heapArr[0] = nuevo;
        heapify(0);
    }

    // Devuelve el máximo elemento en el heap (ubicado en la raíz).
    // Complejidad: O(1)
    public int maximo(){
        return heapArr[0];
    }

    // Devuelve el identificador de partido correspondiente al máximo elemento en el heap.
    // Complejidad: O(1)
    public int maximoPartido(){
        return partido[0];
    }

    // Ajusta el heap para mantener la propiedad de max-heap desde el índice dado.
    // Complejidad: O(log(tamaño))
    public void heapify(int i){
        int max = i; 
        int izq = 2 * max + 1; 
        int der = 2 * max + 2; 
 
        if (izq < longitud){
            if (heapArr[izq] > heapArr[max]) max = izq;
        }

        if (der < longitud){
            if (heapArr[der] > heapArr[max]) max = der;
        }

        if (max != i) {
            int temp = heapArr[i];
            int temp2 = partido[i];
            heapArr[i] = heapArr[max];
            partido[i] = partido[max];
            heapArr[max] = temp;
            partido[max] = temp2;
 
            heapify(max);
        }
    }

    // Construye un max-heap a partir del array dado.
    // Complejidad: O(tamaño)
    public void construirHeap(){
        int inicio = (longitud / 2) - 1;

        for (int i = inicio; i >= 0; i--)
        {
            heapify(i);
        }
    }

}
