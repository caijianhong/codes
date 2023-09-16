solve :: [Int] -> Integer
solve [x] = toInteger x
solve xs = max answer (solve now) where
    left = head xs
    right = last xs
    answer = (toInteger $ length xs - 1) * (toInteger $ min left right)
    now = if left < right then tail xs else init xs

readIntListLn :: IO [Int]
readIntListLn = fmap (map read . words) getLine

main = getLine >> readIntListLn >>= print . solve
