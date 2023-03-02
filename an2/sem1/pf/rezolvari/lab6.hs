data Fruct = Mar String Bool | Portocala String Int

listaFructe :: [Fruct]
listaFructe =
  [ Mar "Ionatan" False,
    Portocala "Sanguinello" 10,
    Portocala "Valencia" 22,
    Mar "Golden Delicious" True,
    Portocala "Sanguinello" 15,
    Portocala "Moro" 12,
    Portocala "Tarocco" 3,
    Portocala "Moro" 12,
    Portocala "Valencia" 2,
    Mar "Golden Delicious" False,
    Mar "Golden" False,
    Mar "Golden" True
  ]

ePortocalaDeSicilia :: Fruct -> Bool
ePortocalaDeSicilia (Mar tip viermi) = False
ePortocalaDeSicilia (Portocala tip felii) = elem tip ["Tarocco", "Moro", "Sanguinello"]


nrFeliiSicilia :: [Fruct] -> Int
nrFeliiSicilia [] = 0
nrFeliiSicilia ((Mar tip viermi) : fruct) = nrFeliiSicilia fruct
nrFeliiSicilia ((Portocala tip felii) : fructe) 
    | ePortocalaDeSicilia (Portocala tip felii) = felii + nrFeliiSicilia fructe
    | otherwise = nrFeliiSicilia fructe


nrMereViermi :: [Fruct] -> Int
nrMereViermi [] = 0
nrMereViermi ((Portocala tip felii) : lista_fructe) = nrMereViermi lista_fructe
nrMereViermi ((Mar tip viermi) : lista_fructe) = if viermi then 1 + nrMereViermi lista_fructe else nrMereViermi lista_fructe


type NumeA = String
type Rasa = String
data Animal = Pisica NumeA | Caine NumeA Rasa
    deriving Show

vorbeste :: Animal -> String
vorbeste (Pisica _) = "Meow!"
vorbeste (Caine _ _) = "Woof!"

rasa :: Animal -> Maybe String
rasa (Caine _ rasa) = Just rasa
rasa (Pisica _) = Nothing


data Linie = L [Int] deriving Show
data Matrice = M [Linie] deriving Show

liniaMea = L [1, 3, 3]
matriceaMea = M [L [1, 1, 1], L [0, 1, 2], L [0, 3, 0], L [1, 0, 2]]

sumaLinie :: Linie -> Int
sumaLinie (L lista) = sum lista

getSumaLinii :: Matrice -> [Int]
getSumaLinii (M []) = []
getSumaLinii (M (L x : xs)) = sum x : getSumaLinii (M xs)

verifica :: Matrice -> Int -> Bool
verifica (M m) n = and (foldr (\x y -> if x == n then True : y else False : y) [] (getSumaLinii (M m)))
-- verifica (M m) n = foldr (\x y -> (x == n) && y) True (getSumaLinii (M m))

getLungimeLinii :: Matrice -> [Int]
getLungimeLinii (M []) = []
getLungimeLinii (M (L x : xs)) = length x : getLungimeLinii (M xs)

lungimeLinie :: Linie -> Int
lungimeLinie (L lista) = length lista

pozitive :: Linie -> Bool
pozitive (L lst) = and (map (>0) lst)

doarPozNAux :: Matrice -> Int -> [Int]
doarPozNAux (M []) n = []
doarPozNAux (M (L x) : xs) n 
    | pozitive x && length x == n = 1 + doarPozNAux M xs n
    | lungimeLinie x == n = 2 + doarPozNAux M xs n
    | otherwise = 0 + doarPozNAux xs  n


getPrima :: Matrice -> Int
getPrima (M L lst) = length head lst

corect :: Matrice -> Bool
corect (M (L lst)) = length lst == corect (M (L tail lst))
