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

