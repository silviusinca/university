
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
                        