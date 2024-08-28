package aed;

/*
InvRep SistemaCNE:

    - 0 <= primero,segundo < P, primero != segundo, donde primero y segundo indican la posición del partido con más votos y del segundo partido con más votos, respectivamente.
    - 0 <= votosTotales, es la sumatoria de todos los elementos en votosPresidente
    - votosDiputados es una matriz de D x P, donde se encuentran los votos de los diputados de cada partido en el distrito d, y para todo par d y p en rango VotosDiputados[d][p] >= 0. D = |nombreDistrito| y P = |nombrePartidos|
    - nombrePartidos es un array en el que en cada posicion se encuentra el nombre del partido y el indice es su id.
    - nombreDistrito es un array en el que en cada posicion se encuentra el nombre del distrito y el indice es su id.
    - dHondt es un array de maxHeaps en la que cada posicion del array representa su distrito, y donde en cada uno se encuentra un max heap con los votos a diputados para cada partido.
    - votosPresidente es un array donde se guardan los votos a presidente de cada partido. Para todo p valido votosPresidente[p] >= 0. con 0 <= p < |nombrePartidos|
    - bancasXdistrito es un array en el que en cada índice es la id de un distrito y se guarda la cantidad de bancas que tiene ese distrito. La cantidad de bancas debe ser >= 0.
    - ultimaMesaDeDistrito es un array en el que cada índice representa el id del distrito y lo que guarda en el array es el número de la última mesa que ya no pertenece al distrito y es un array ordenado de menor a mayor.
    - resultadoCalculado es un array en el se marca si fue o no calculado los ganadores de las bancas en ese distrito con un true o false. Los distritos son representados por el id del array.
    - mesasRegistrada es una ListaEnlazada en la cual se encuentran los ids de las mesas ya registradas.
    - votosTotalesDistrito es un array en el que los indices representa a los distritos y se guarda la suma de todos los votos del distrito, para todo d valido votosTotalesDistrito[d] >= 0. con 0 <= d < |nombreDistrito|
    - resultadosBancas es una matriz de D x P con D = |nombreDistrito| y P = |nombrePartidos| donde se guardan la cantidad de bancas que gana cada partido en cada distrito.
*/

public class SistemaCNE {
    private int primero;
    private int segundo;                                                
    private int votosTotales;
    private int[][] votosDiputados;
    private String[] nombrePartidos;
    private String[] nombreDistrito;
    private heap[] dHondt;
    private int[] votosPresidente;
    private int[] bancasXdistrito;
    private int[] ultimaMesaDeDistrito;
    private int[][] resultadosBancas;
    private boolean[] resultadoCalculado;
    private ListaEnlazada<Integer> mesasRegistrada; //! No es información que se use o que sea relevante, de hecho es inaccesible.              (Es cierto, pero la consigna lo pedía.)
    private int[] votosTotalesDistrito;


    public class VotosPartido{
        private int presidente;
        private int diputados;
        VotosPartido(int presidente, int diputados) {this.presidente = presidente; this.diputados = diputados;}
        public int votosPresidente(){return presidente;}
        public int votosDiputados(){return diputados;} 
    }

    public SistemaCNE(String[] nombresDistritos, int[] diputadosPorDistrito, String[] nombresPartidos, int[] ultimasMesasDistritos) {
        primero = 0;                                                                                         //Asignación en O(1)
        segundo = 1;                                                                                         //O(1)
        votosTotales = 0;                                                                                    //O(1)
        votosDiputados = new int[nombresDistritos.length][nombresPartidos.length];                           //Creación de una matriz con arrays en O(P*D)
        nombrePartidos = nombresPartidos;                                                                    //Asignación de un array en O(P) //! Consideren que probablemente genere aliasing y sea O(1) hacer ese tipo de asignaciones, pero esta bien que lo hayan razonado de esa manera
        nombreDistrito = nombresDistritos;                                                                   //O(D)
        ultimaMesaDeDistrito = ultimasMesasDistritos;                                                        //O(D)
        votosPresidente = new int[nombresPartidos.length];                                                   //O(P)
        bancasXdistrito = diputadosPorDistrito;                                                              //O(D)
        dHondt = new heap[nombresDistritos.length];                                                          //Creación de un heap de tamaño D en O(D)
        resultadosBancas = new int[nombresDistritos.length][nombresPartidos.length - 1];                     //Creación de matriz en O(P*D)
        resultadoCalculado = new boolean[resultadosBancas.length];                                           //Creación de un array en O(D)
        votosTotalesDistrito = new int[nombresDistritos.length];                                             //O(D)

        for (int i = 0; i < nombresDistritos.length; i++)                                                   //For que se repite tantas veces como distritos haya.
        {              
            votosTotalesDistrito[i] = 0;                                                                    //O(1), como se repite D veces por el for, esto es O(D)
        }

        for (int i = 0; i < resultadosBancas.length; i++)                                                   //O(P*D)    Esto representaría la creación de un array (resultadoCalculado)
        {                                                                                                   //En O(D), pero debajo hay otro for que crea una matriz P*D, el cual tiene
            resultadoCalculado[i] = false;                                                                  //una complejidad de O(P*D).    
            for (int j = 0; j < resultadosBancas[i].length; j++)                                            //O(P*D) + O(D) = O(P*D)
                resultadosBancas[i][j] = 0;
        }

        mesasRegistrada = new ListaEnlazada<>();                                                            //O(1)

    }                                                                                                       //Entonces la creación del sistema es el mayor de estas complejidades. Es decir, O(P*D)


    public String nombrePartido(int idPartido) {
        return nombrePartidos[idPartido];                                                                   //O(1)  Se entra a un array dado un indice
    }

    public String nombreDistrito(int idDistrito) {
        return nombreDistrito[idDistrito];                                                                  //O(1)  Se entra a un array dado un indice
    }

    public int diputadosEnDisputa(int idDistrito) {
        return bancasXdistrito[idDistrito];                                                                 //O(1)  Se entra a un array dado un indice
    }

    public String distritoDeMesa(int idMesa) {
       return nombreDistrito[busquedaDistritoXmesa(idMesa)];                                                //O(log D)  Se utiliza una busqueda binaria usando los distritos
    }


    public int busquedaDistritoXmesa(int idMesa){                                                           //Este es el código de la busqueda binaria
        int izquierda = 0;
        int derecha = ultimaMesaDeDistrito.length - 1;
        int medio = (derecha + izquierda) / 2 ;

        while (izquierda <= derecha) {

            medio = (derecha + izquierda) / 2;

            if (ultimaMesaDeDistrito[medio + 1] > idMesa && ultimaMesaDeDistrito[medio] <= idMesa){
                return (medio + 1);
            }
            else if (idMesa < ultimaMesaDeDistrito[medio]) {
                derecha = medio - 1;
            }
            else  { 
                izquierda = medio + 1 ;
            }
           
        }

        return medio;
    }
    


    public void registrarMesa(int idMesa, VotosPartido[] actaMesa) {
        int distrito = busquedaDistritoXmesa(idMesa);                                                   //O(log D)  Se utiliza una busqueda binaria usando los distritos

        for (int i = 0; i < actaMesa.length; i++)                                                       //actaMesa tiene una longitud equivalente a los partidos. Entonces se ejecuta P veces.
        {
            votosPresidente[i] += actaMesa[i].votosPresidente();                                        //Suma en O(1)
            votosTotales += actaMesa[i].votosPresidente();                                              //O(1)

            if(votosPresidente[primero] < votosPresidente[i]){                                          //Comparación en O(1)
                segundo = primero;                                                                      //Asignación en O(1)
                primero = i;                                                                            //O(1)
            }
            else if(votosPresidente[segundo] < votosPresidente[i] && i != primero){                     //Comparacion en O(1)
                segundo = i;                                                                            //Asignación en O(1)
            }

            votosDiputados[distrito][i] += actaMesa[i].votosDiputados();                                //Suma en O(1)
            votosTotalesDistrito[distrito] += actaMesa[i].votosDiputados();                             //Suma en O(1)
        }                                                                                               //El for se ejecuta P veces con todas operaciones O(1) dentro, entonces el for es O(P)
        
        int[] votosSinBlancos = new int[votosDiputados[distrito].length - 1];                           //Crecion de un array de los votos de todos los partidos (menos el blanco) en O(P)

        for (int i = 0; i < votosSinBlancos.length; i++)                                                //Un for que itera P veces (por cantidad de partidos)
        {
            if((float)votosDiputados[distrito][i] / (float)votosTotalesDistrito[distrito] >= 0.03)      //Accede a valores de un array en O(1), los divide y hace una comparacion en O(1).
            {
                votosSinBlancos[i] = votosDiputados[distrito][i];                                       //Asignación si se cumple el if en O(1)
            }
            else votosSinBlancos[i] = 0;                                                                //Asignación si no se cumple el if en O(1)
        }                                                                                              

        dHondt[distrito] = new heap(votosSinBlancos);                                                   //En la funcion de crear un heap dado un array tiene la complejidad del tamaño del array, en este caso O(P)

        mesasRegistrada.agregarAdelante(idMesa);                                                        //agregar adelante en lista enlazada O(1)

    }                                                           //Complejidad de registrar mesa: O(log D) (busqueda binaria) + O(P) (creación de heap) + O(P) (primer for) + O(P) (segundo for). Que es igual a O(log D + P)



    public int votosPresidenciales(int idPartido) {
        return votosPresidente[idPartido];                                                                      //Acceder a un array con indice O(1)
    }



    public int votosDiputados(int idPartido, int idDistrito) {
        return votosDiputados[idDistrito][idPartido];                                                           //Acceder a un array de array con indice O(1)
    }



    public int[] resultadosDiputados(int idDistrito){

        if (resultadoCalculado[idDistrito]) return resultadosBancas[idDistrito];                     //Acceso a un array y asignacion si se cumple el if O(1)

        int i = 1;                                                                                   //Asignación O(1)

        while (i <= bancasXdistrito[idDistrito])                                                     //Ciclo que se repite hasta que i = 1 llege a ser mayor que las bancas por distrito. Se repite D_d veces
        {
            resultadosBancas[idDistrito][dHondt[idDistrito].maximoPartido()]++;
            dHondt[idDistrito].ReemplazarMaximo(votosDiputados[idDistrito][dHondt[idDistrito].maximoPartido()] / (resultadosBancas[idDistrito][dHondt[idDistrito].maximoPartido()]+ 1));
            i++;                                                                                                                                                      
        }
        
        /*
        Explicación de la complejidad del while de arriba.
        Primera linea: Acceder al maximo de un max heap, O(1) y con ese dato acceder a un array, O(1)
        Segunda Linea: ReemplazarMaximo utiliza el heapify, pero como solo cambiamos un solo valor del array que ya era heap, tener que reubicarlo dentro del heap puede llevar a lo sumo
        log(P) intercambios, ya que el heap se puede pensar como un arbol binario aunque este implementado con array. (siendo P la cantidad de elementos del arbol)
        Ya que el peor caso es si se intercambia el máximo por el menor valor dentro del heap, hay que llevarlo hasta abajo, y la cantidad de intercambios es proporcional a la altura de un heap, que es log (P).
        Luego, máximo partido es O(1) por ser un max heap, y la division tambien se realiza en O(1). Entonces reemplazar máximo es O(log P)           
        Tercera linea: (i++ es O(1))
        Entonces el ciclo tiene una complejidad de D_d * log P = O(D_d*log(P)) log P se repite D_d veces.
        */

        resultadoCalculado[idDistrito] = true;                                      //asignación en un array, O(1)

        return resultadosBancas[idDistrito];                                        //return en O(1)
    }                                                                               //Entonces resultadosDiputados se hace en O(D_d*log (P))




    public boolean hayBallotage(){
        
        if((((float)votosPresidente[primero] / (float)votosTotales) * 100) < 40){
            return true;
        }
        else if ((((float)votosPresidente[primero] / (float)votosTotales) * 100) >= 45 ){
            return false;
        }
        else if (((float)(votosPresidente[primero]-votosPresidente[segundo]) / (float)votosTotales * 100) > 10){
            return false;
        }
        return true;
    }                       //Son todas comparaciones, divisiones y multiplicaciones que se hacen en O(1)
}

