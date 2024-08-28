// Tests para la función sugerir121.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;
tablero tabl ={
        {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cMINA,cVACIA,cVACIA},
        {cMINA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cMINA},
        {cVACIA,cVACIA,cVACIA,cVACIA,cMINA,cVACIA,cVACIA,cMINA},
        {cMINA,cVACIA,cMINA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
        {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cMINA,cVACIA,cVACIA},
        {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
        {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cMINA,cVACIA,cVACIA},
        {cVACIA,cMINA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
};
tablero tabl2 = {
        {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cMINA,cVACIA},
        {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
        {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cMINA},
        {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
        {cMINA,cVACIA,cMINA,cVACIA,cVACIA,cMINA,cMINA,cVACIA},
        {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cMINA,cVACIA,cVACIA},
        {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cMINA,cMINA},
        {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cMINA,cVACIA,cVACIA},
};
tablero tabl3 = {
        {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
        {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
        {cMINA,cMINA,cVACIA,cVACIA,cMINA,cVACIA,cVACIA,cVACIA},
        {cVACIA,cVACIA,cVACIA,cMINA,cVACIA,cVACIA,cMINA,cVACIA},
        {cVACIA,cVACIA,cVACIA,cVACIA,cMINA,cMINA,cVACIA,cVACIA},
        {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
        {cMINA,cVACIA,cVACIA,cVACIA,cVACIA,cMINA,cVACIA,cMINA},
        {cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA,cVACIA},
};

jugadas jug1 = { jugada  (pos (0,0) ,1),jugada(pos(0,6),2),jugada (pos(4,0),1), jugada (pos(7,0),1),
                 jugada(pos(4,1),2),jugada(pos(0,1),1),jugada(pos(4,2),1)};
jugadas jug2={jugada (pos(0,0),1),jugada(pos(5,4),2)};
jugadas jug3={jugada(pos(4,4),1),jugada(pos(0,0),1),jugada(pos(5,4),2),jugada(pos(0,7),1),jugada(pos(6,4),1)};
jugadas jug4= {jugada(pos(4,0),1),jugada(pos(4,1),2),jugada(pos(4,2),1),jugada(pos(3,1),2),jugada(pos(5,1),0),
               jugada(pos(4,4),1),jugada(pos(5,4),2),jugada(pos(6,4),1),jugada(pos(5,5),2)};
jugadas jug5= {jugada(pos(4,4),1),jugada(pos(5,4),2),jugada(pos(6,4),1),jugada(pos(5,5),2),jugada(pos(5,6),2),
               jugada(pos(4,6),1),jugada(pos(6,6),1),jugada(pos(5,7),0)};

jugadas juga6={jugada (pos(3,0),1),jugada(pos(3,1),2),jugada(pos(3,2),1),jugada(pos(2,1),0),jugada(pos(5,0),1),
               jugada(pos(5,1),2),jugada(pos(5,2),1),jugada(pos(6,1),0),jugada(pos(4,1),2)};
jugadas juga7={jugada (pos(3,0),1),jugada(pos(3,1),2),jugada(pos(3,2),1),jugada(pos(2,1),0),jugada(pos(5,0),1),
               jugada(pos(5,1),2),jugada(pos(5,2),1),jugada(pos(4,1),2)};
jugadas jug8= {jugada(pos(3,1),2),jugada(pos(4,4),1),
               jugada(pos(5,4),2),jugada(pos(6,4),1),jugada(pos(5,5),2),jugada(pos(4,0),1),
               jugada(pos(4,1),2),jugada(pos(4,2),1),jugada(pos(5,3),0)};
jugadas jug9={jugada (pos(3,0),1),jugada(pos(3,1),2),jugada(pos(3,2),1),jugada(pos(5,0),1),
               jugada(pos(5,1),2),jugada(pos(5,2),1),jugada(pos(4,1),2)};
jugadas jug10={jugada (pos(3,0),1),jugada(pos(3,1),2),jugada(pos(3,2),1),jugada(pos(5,0),1),
              jugada(pos(5,1),2),jugada(pos(5,2),1),jugada(pos(4,1),2)};
jugadas jug11 = {jugada(pos(7,5),1),jugada(pos(7,6),2),jugada(pos(7,7),1),jugada(pos(6,6),2)};
jugadas jug12 = {jugada(pos(7,5),1),jugada(pos(7,6),2),jugada(pos(7,7),1)};
banderitas band = {};
banderitas band2={pos(3,1)};
banderitas band3={pos(5,3)};
banderitas band4 = {pos(6,1)};
banderitas  band5 = {pos(6,1),pos(2,1)};
pos posible1 = pos (3,1);
pos posible2 = pos(5,1);
pos posible3 = pos(5,3);
pos posible4 = pos(5,5);
pos posible5 = pos(6,1);
pos posible6 = pos(5,1);
pos posible7 = pos(2,1);
pos posible8 = pos(6,6);
TEST(sugerir121TEST,tiene121){
    pos p;
    sugerirAutomatico121(tabl,band,jug1,p);
    ASSERT_EQ(p,posible1);
}

TEST(sugerir121TEST,noTiene121){
    pos p;
    ASSERT_FALSE(sugerirAutomatico121(tabl,band2,jug2,p));
}

TEST(sugerir121TEST,tiene121PeroHaybanderaEn31){
    pos p;
    sugerirAutomatico121(tabl,band2,jug1,p);
    ASSERT_EQ(p,posible2);
}

TEST(sugerir121TEST,Vertical){
    pos p;
    sugerirAutomatico121(tabl,band,jug3,p);
    ASSERT_EQ(p,posible3);
}

TEST(sugerir121TEST,verticalPeroConBandera){
    pos p;
    sugerirAutomatico121(tabl,band3,jug3,p);
    ASSERT_EQ(p,posible4);
}
TEST(sugerir121TEST,esElsegundo121){
    pos p;
    ASSERT_TRUE(sugerirAutomatico121(tabl,band,jug4,p));

}

TEST(sugerir121TEST,esElsegundo121POS){
    pos p;
    sugerirAutomatico121(tabl,band,jug4,p);
    ASSERT_EQ(p,posible3);
}
TEST(sugerir121TEST,esElsegundo121POSvertical){
    pos p;
    ASSERT_TRUE(esta121EnVertical(tabl,jug4,band,p));
}
TEST(sugerir121TEST,dosjugadasHorizontal121){
    pos p;
    ASSERT_TRUE(sugerirAutomatico121(tabl,band,jug5,p));

}
TEST(sugerir121TEST,dosjugadas121Horizontal){
    pos p;
    sugerirAutomatico121(tabl,band,jug5,p);
    ASSERT_EQ(p,posible3);
}
TEST(sugerir121TEST,hay2verticalCumpleLa2DA){
    pos p;
    ASSERT_TRUE(esta121EnVertical(tabl,jug5,band,p));
}

TEST(sugerir121TEST,dosHorizontal){
    pos p;
    ASSERT_FALSE(esta121EnHorizontal(tabl2,juga6,band,p));
}
TEST(sugerir121TEST,dosHorizontal2){
    pos p;
    sugerirAutomatico121(tabl2,band,juga7,p);
    ASSERT_EQ(p,posible5);
}
TEST(sugerir121TEST,dosHorizontal3){
    pos p;
    ASSERT_TRUE(esta121EnHorizontal(tabl2,juga7,band,p));
}

TEST(SUGERIR121test,unoVerticalOtroHorizontal){
    pos p ;
    sugerirAutomatico121(tabl,band,jug8,p);
    ASSERT_EQ(p,posible6);

}
TEST(SUGERIR121test,dosHorizontalBandera) {
    pos p;
    ASSERT_FALSE(sugerirAutomatico121(tabl2, band4, juga7, p));
}
TEST(SUGERIR121test,dosHorizontalconDosBanderas) {
    pos p;
    ASSERT_FALSE(sugerirAutomatico121(tabl2, band5, jug9, p));
}
TEST(SUGERIR121test,dosHorizontalV3) {
    pos p;
    sugerirAutomatico121(tabl2, band4, jug10, p);
    ASSERT_EQ(p,posible7);
}
TEST(SUGERIR121test,posInvalida) {
    pos p;
    ASSERT_FALSE(sugerirAutomatico121(tabl3, band, jug11, p));

}
TEST(SUGERIR121test,posInvalida2) {
    pos p;
    sugerirAutomatico121(tabl3, band, jug12, p);
    ASSERT_EQ(p,posible8);
}