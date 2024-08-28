// Tests para la función minasAdyacentes.
// Ver el archivo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "../definiciones.h"
#include "gtest/gtest.h"

using namespace std;
tablero q = {
        { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
        { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};

pos p1 = {1,2};
TEST(minasAdyacentesTEST, medioSobreCasillaVacia){
    ASSERT_EQ(minasAdyacentes(q,p1),3);
}

pos p2={2,1};
TEST(minasAdyacentesTEST, medioSobreCasillaConMina){
    ASSERT_EQ(minasAdyacentes(q,p2),0);
}

pos p3={0,4};
TEST(minasAdyacentesTEST, esquinaSobreCasillaVacia){
    ASSERT_EQ(minasAdyacentes(q,p3),1);
}

pos p4={0,0};
TEST(minasAdyacentesTEST, esquinaSobreCasillaConMina){
    ASSERT_EQ(minasAdyacentes(q,p4),1);
}