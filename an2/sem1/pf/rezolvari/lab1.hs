import Data.List

main = putStrLn "Hello, world!"
myInt = 55555555555555555555555555555555555555555555555555555555555
double :: Integer -> Integer
double x = x+x

triple :: Integer -> Integer
triple x = 3*x

maxim :: Integer -> Integer -> Integer
maxim a b = if (a > b) then a else b

maxim3 :: Integer -> Integer -> Integer -> Integer
maxim3 a b c = let
                    u = maxim a b
                in
                    maxim u c

maxim4 :: Integer -> Integer -> Integer -> Integer -> Integer
maxim4 a b c d = let
                    u = maxim a b
                    v = maxim c d
                in 
                    maxim u v

-- Exercitii 
-- a)
suma_patrate :: Integer -> Integer -> Integer
suma_patrate a b = a*a + b*b

-- b)
par_impar :: Integer -> [Char]
par_impar a = if (mod a 2 == 0) then "par" else "impar" 

-- c)
factorial :: Integer -> Integer
factorial a = 
            if (a == 0) 
                then 1
                else a * factorial (a-1)


-- d)
dublu :: Integer -> Integer -> Bool
dublu a b = if (a > 2*b) then True else False
-- sau dublu a b = a > 2 * b


