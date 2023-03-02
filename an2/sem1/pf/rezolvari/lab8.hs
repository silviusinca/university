-- ex 1:
data Punct = Pt [Int]

data Arb = Vid | F Int | N Arb Arb 
        deriving Show

class ToFromArb a where
    toArb :: a -> Arb
    fromArb :: Arb -> a 

-- a)
instance Show Punct where
    show (Pt []) = "()"
    show (Pt (x:xs)) = "(" ++ show x ++ concat [virgula : show numar | (numar, virgula) <- zip xs [',',',' ..]] ++ ")"

-- ex 2:
data Geo a = Square a | Rectangle a a | Circle a 
    deriving Show

class GeoOps g where
    perimeter :: (Floating a) => g a -> a 
    area :: (Floating a) => g a -> a 

-- a)
instance GeoOps Geo where
    perimeter (Square l) = 4 * l 
    perimeter (Rectangle l1 l2 ) = 2 * (l1 + l2)
    perimeter (Circle r) = 2 * pi * r 

    area (Square l) = l * l 
    area (Rectangle l1 l2) = l1 * l2
    area (Circle r) = pi * r * r  

-- b)
instance (Floating l, Eq l) => Eq (Geo l) where
    a == b = perimeter a == perimeter b
