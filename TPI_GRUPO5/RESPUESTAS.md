% Contesten aquí la pregunta sobre complejidad: 
En el caso de jugarPlus lo único que cambiaria es que no tenemos que recorrer la lista de jugadas para ver que el p no este, ya que usariamos (if (j[p.first][p.second]==-1){....)
que ayudaría con el tema de complejidad pero termina siendo casi lo mismo, un poquito mejor pero seguria teninendo  complejidad temporal  O(n^2) ()

Y en sugerirAutomatico121 si cambiaria bastante la complejidad ya que tendria que hacer un doble for recorriendo la lista de jugadas en busca de una posicion con 2 minas adyacentes,
lo que aumentaria la complejidad a O(n^3).