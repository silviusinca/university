import Data.Char

palindrom :: String -> Bool
palindrom s = s == reverse s 

voc :: String -> Int
voc "" = 0
voc (h : t)
    | elem h "aeiouAEIOU" = 1 + t'
    | otherwise = t'
    where t' = voc t

-- voc s = sum[1 | c <- s, e `elem` "aeiouAEIOU"]

nrVocale :: [String] -> Int
nrVocale [] = 0
nrVocale (h : t)
    | palindrom h = voc h + t'
    | otherwise = t'
    where t' = nrVocale t
-- nrVocale l = sum[voc s | s <- l, s==reverse s]

f :: Int -> [Int] -> [Int]
f a [] = []
f a (h : t)
    | even h = [h, a] ++ t'
    | otherwise = h : t'
    where t' = f a t

divizori :: Int -> [Int]
divizori n = [i |i <- [1 .. n], n `mod` i == 0]

listadiv :: [Int] -> [[Int]]
listadiv l = [divizori n | n <- l]

inIntervalComp :: Int -> Int -> [Int] -> [Int]
inIntervalComp a b l = [x| x <- l, x >= a && x <= b]

inIntervalRec :: Int -> Int -> [Int] -> [Int]
inIntervalRec a b [] = []
inIntervalRec a b (h : t)
    | h >= a && h <= b = h : t'
    | otherwise = t'
    where t' = inIntervalRec a b t

pozitiveRec :: [Int] -> Int
pozitiveRec [] = 0
pozitiveRec (h : t)
    | h > 0 = 1 + t'
    | otherwise = t'
    where t' = pozitiveRec t

pozitiveComp :: [Int] -> Int
pozitiveComp l = sum[1 | x <- l, x > 0]

pozitiiImpareComp :: [Int] -> [Int]
pozitiiImpareComp l = [ poz | (elem, poz) <- zip l [0..], odd elem]

pAuxRec :: [Int] -> Int -> [Int]
pAuxRec [] _ = []
pAuxRec (h:t) index
    | odd h = index : t' 
    | otherwise = t'
    where t' = pAuxRec t (index+1)

pozitiiImpareRec :: [Int] -> [Int]
pozitiiImpareRec l = pAuxRec l 0

-- importurile se pun la inceputul fisierului
-- mersi

multiDigitsRec :: String -> Int
multiDigitsRec "" = 1
multiDigitsRec (h : t)
    | isDigit h = digitToInt h * t'
    | otherwise = t'
    where t' = multiDigitsRec t

multiDigitsComp :: String -> Int
multiDigitsComp s = product[ digitToInt c | c <- s, isDigit c]


