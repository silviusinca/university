factori :: Int -> [Int]
factori x = [d | d <- [1..x], x `mod` d == 0]

prim :: Int -> Bool
prim x = factori x == [1, x]

prim2 :: Int -> Bool
prim2 x = length(factori x) == 2

numerePrime :: Int -> [Int]
numerePrime n = [x | x <- [2..n], prim x]

myzip3 :: [a] -> [b] -> [c] -> [(a, b, c)]
myzip3 a b [c] = []
myzip3 a [] c = []
myzip3 [] b c = []
myzip3 (a1 : a2) (b1 : b2) (c1 : c2) = [(a1, b1, c1)] ++ myzip3 a2 b2 c2 
-- myzip3 l1 l2 l3 = [(x, y, z) | i <- [0.. (min (min (length l1) (length l2)) (length l3)- 1,)], let x = l1 !! i, let y = l2 !! i, let z = l3 !! i]


firstEl :: [(a, b)] -> [a]
firstEl = map fst
-- firstEl = map (\(x, y) -> x)


sumList :: [[Int]] -> [Int]
sumList = map sum

prel2 :: [Int] -> [Int]
prel2 = map (\x -> if even x then div x 2 else 2*x)

listaSiruri :: Char -> [String] -> [String]
listaSiruri ch = filter (\str -> elem ch str)

-- 9
impare :: [Int] -> [Int]
impare x = filter odd x
patrate :: [Int] -> [Int]
patrate = map(\x -> x*x)
patrateImpare :: [Int] -> [Int]
patrateImpare l = patrate (impare l)

-- 10
patratePozImpare lst = map (\(x1,x2) -> x1 * x1)(filter(\(x1,x2) -> odd x2) (zip lst [1..]))

-- 11
elimConsoane :: String -> String
elimConsoane str = filter f str where f x = elem x "aeiouAEIOU" 
numaiVocale :: [String] -> [String]
numaiVocale = map (\str -> elimConsoane str)

-- 12
mymap :: (a -> b) -> [a] -> [b]
mymap f [] = []
mymap f (h : t) = f h : mymap f t 

-- am testat sa vad daca merge bine
sumList2 :: [[Int]] -> [Int]
sumList2 = mymap sum

myfilter :: (a -> Bool) -> [a] -> [a]
myfilter f [] = []
myfilter f (h : t) = if f h then [h] ++ myfilter f t 
                     else myfilter f t
                        