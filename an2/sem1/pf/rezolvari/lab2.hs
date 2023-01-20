poly :: Double -> Double -> Double -> Double -> Double
poly a b c x = a*x*x + b*x + c

eeny :: Integer -> String
eeny x 
    | even x = "eeny"
    | otherwise = "meeny"

fizzbuzz :: Integer -> String
fizzbuzz x
        | mod x 15 == 0 = "FizzBuzz"
        | mod x 3 == 0 = "Fizz"
        | mod x 5 == 0 = "Buzz"
        | otherwise = ""

fizzbuzz2 :: Integer -> String
fizzbuzz2 x =   if (mod x 15 == 0)
                    then "FizzBuzz"
                else
                    if (mod x 3 == 0)
                    then "Fizz"
                    else 
                        if (mod x 5 == 0)
                            then "Buzz"
                        else ""

tribonacci :: Integer -> Integer
tribonacci n 
    | n < 3     = 1
    | n == 3    = 2
    | otherwise = tribonacci (n-1) + tribonacci (n-2) + tribonacci(n-3)

binomial :: Integer -> Integer -> Integer
binomial n k
    | k == 0 = 1
    | n == 0 = 0
    | otherwise = binomial (n-1) k + binomial (n-1) (k-1)


verifL :: [Int] -> Bool
verifL lst = even (length lst)
    
takefinal :: [a] -> Int -> [a]
takefinal lst n
    | length lst < n = lst
    | otherwise = drop (length lst - n) lst

remove :: [a] -> Int -> [a]
remove lst n = take (n-1) lst ++ drop n lst 


myreplicate :: Int -> v -> [v]
myreplicate 1 v = [v]
myreplicate n v = [v] ++ myreplicate (n-1) v

sumImp :: [Int] -> Int
sumImp [] = 0
sumImp (h:t)
    | odd h = h + t'
    | otherwise = t'
    where t' = sumImp t


totalLen :: [String] -> Int
totalLen [] = 0
totalLen (h:t)
    | head h == 'A' = length h + t'
    | otherwise = t'
    where t' = totalLen t
