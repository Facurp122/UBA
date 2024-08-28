// Tests para la función jugarPlus.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../definiciones.h"
#include "gtest/gtest.h"

using namespace std;

// ┌───┬───┬───┬───┬───┐
// │ * │ * │ 2 │ 1 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 3 │ 3 │ 3 │ * │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 1 │ * │ 2 │ 1 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 2 │ 3 │ 2 │ 1 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ * │ 2 │ * │ 1 │ 0 │
// └───┴───┴───┴───┴───┘


tablero t4 = {
        { cMINA,  cVACIA,  cVACIA, cVACIA, cVACIA, cVACIA, cMINA, cVACIA, cVACIA},//1-7
        { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA ,cMINA ,cVACIA ,cVACIA, cVACIA},//6
        { cVACIA, cVACIA,  cVACIA, cVACIA, cVACIA ,cVACIA,cMINA,cVACIA,cVACIA},//7
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA , cVACIA,cVACIA,cVACIA,cVACIA},//
        { cVACIA,  cVACIA, cMINA,  cVACIA, cVACIA ,cVACIA,cVACIA,cMINA,cVACIA},//3,8
        { cVACIA,  cMINA, cVACIA,  cVACIA, cVACIA , cMINA,cVACIA,cVACIA,cVACIA},//2,6
        { cVACIA,  cMINA, cVACIA,  cVACIA, cVACIA ,cVACIA,cVACIA,cVACIA,cVACIA},//2
        { cVACIA,  cVACIA, cVACIA,  cVACIA, cMINA ,cVACIA,cVACIA,cVACIA,cVACIA},//5
        { cVACIA,  cVACIA, cVACIA,  cVACIA, cVACIA ,cVACIA,cVACIA,cVACIA,cVACIA},//

};

jugadas jugadasValidas10 = {
        jugada(pos(3, 1), 1), jugada(pos(3, 2), 1), jugada(pos(3, 3), 1),
};
jugadas jugadasValidas20 = {
        jugada(pos(3, 1), 1), jugada(pos(3, 2), 1), jugada(pos(3, 3), 1),
};
jugadas jugadasValidas30 = {
        jugada(pos(3, 1), 1), jugada(pos(3, 2), 1), jugada(pos(3, 3), 1),
};
jugadas jugadasRES1 = {
        jugada(pos(3, 1), 1),jugada(pos(3,2),1),jugada(pos(3, 3), 1),jugada(pos(0,8),0),jugada(pos(0,7),1),jugada(pos(1,7),2),jugada(pos(1,8),0),
        jugada(pos(2,7),1),jugada(pos(2,8),0),jugada(pos(3,7),2),jugada(pos(3,8),1),
};
jugadas jugadasRES2 = {
        jugada(pos(3, 1), 1), jugada(pos(3, 2), 1), jugada(pos(3, 3), 1),jugada(pos(4,1),2),
};
jugadas jugadasRES3= {
        jugada(pos(3, 1), 1), jugada(pos(3, 2), 1), jugada(pos(3, 3), 1),jugada(pos(0,0),0),};
banderitas ba={{{4,2}}};


TEST(jugarPlusTEST, minasAdjIguala0) {
    pos p1={0,8};
    jugarPlus(t4,ba,p1,jugadasValidas10);
    ASSERT_EQ(jugadasValidas10,jugadasRES1);
}

TEST(jugarPlusTEST,minasAdjIguala2){
    pos p2 ={4,1};
    jugarPlus(t4,ba,p2,jugadasValidas20);
    ASSERT_EQ(jugadasValidas20,jugadasRES2);

}

TEST(jugarPlusTEST,pTieneMina){
    pos p3 = {0,0};
    jugarPlus(t4,ba,p3,jugadasValidas30);
    ASSERT_EQ(jugadasValidas30,jugadasRES3);
}