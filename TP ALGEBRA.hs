type Polinomio = [Float]
type Monomio = (Float,Int)

--Ejercicio 1
crearPolinomio :: [Float] -> Polinomio
crearPolinomio [] = []
crearPolinomio p | (head p) == 0 = crearPolinomio (tail p)
                 | otherwise = p

--Ejercicio 2
grado :: Polinomio -> Int
grado p | p == [] = undefined
        | tail p == [] = 0
        | otherwise = grado (tail p) + 1  

--Ejercicio 3
evaluar :: Polinomio -> Float -> Float
evaluar p a | p == [] = undefined
            | grado p == 0 = head p
            | otherwise = head p * (a^(grado p)) + evaluar (tail p) a


--Ejercicio 4
productoPorMonomio :: Monomio -> Polinomio -> Polinomio
productoPorMonomio (a,n) p = crearPolinomio (productoPorMonomioAux (a,n) p)

productoPorMonomioAux :: Monomio -> Polinomio -> Polinomio
productoPorMonomioAux (a,n) p | p == [] = generadorCeros n
                              | otherwise = ((a*head p) : productoPorMonomioAux (a,n) (tail p))

generadorCeros :: Int -> Polinomio
generadorCeros n | n == 0 = []
                 | otherwise = 0 : generadorCeros (n-1)

--Ejercicio 5
producto :: Polinomio -> Polinomio -> Polinomio
producto p1 p2 = crearPolinomio (sumadeListaPolinomios (monomiosXpolinomios(hacerMonomio p1) p2))

hacerMonomio :: Polinomio -> [Monomio]
hacerMonomio p | p == [] = []
               | otherwise = ((head p),(grado p)) : hacerMonomio (tail p)

sumadePolinomios :: Polinomio -> Polinomio -> Polinomio
sumadePolinomios p1 p2 | p1 == [] && p2 == [] = []  
                       | p1 == [] = p2 
                       | p2 == [] = p1
                       | grado p1 > grado p2 = head p1 : sumadePolinomios (tail p1) p2
                       | grado p1 < grado p2 = head p2 : sumadePolinomios p1 (tail p2) 
                       | grado p1 == grado p2 = ((head p1) + (head p2)) : sumadePolinomios (tail p1)(tail p2)

monomiosXpolinomios :: [Monomio] ->Polinomio ->[Polinomio]
monomiosXpolinomios a p | a == [] =[]
                        | otherwise = productoPorMonomio (head a) p : monomiosXpolinomios (tail a) p 

sumadeListaPolinomios :: [Polinomio] -> Polinomio
sumadeListaPolinomios lp | lp == [] = []
                         | otherwise = sumadePolinomios (head lp) (sumadeListaPolinomios(tail lp))

--Ejercicio 6
posicionDeLista :: [Float] -> Int
posicionDeLista ls | tail ls == [] = 0
                   | otherwise = posicionDeLista (tail ls) + 1  

evaluacionMultiple :: [Float] -> Polinomio -> Polinomio -> [Float]
evaluacionMultiple ls p q | ls == [] = []
                          | mod (posicionDeLista ls)2 == 0 = evaluar p (head ls) : evaluacionMultiple (tail ls) p q
                          | mod (posicionDeLista ls)2 /= 0 = evaluar q (head ls) : evaluacionMultiple (tail ls) p q