quickSort :: Ord a => [a] -> [a]
quickSort [] = []
quickSort xs = smaller ++ equal ++ larger where
    x = xs !! (length xs `div` 2)
    smaller = quickSort $ filter (< x) xs
    equal   =             filter (==x) xs
    larger  = quickSort $ filter (> x) xs

readIntList :: IO [Int]
readIntList = fmap (map read . words) getLine

main :: IO()
main = getLine >> readIntList >>= putStrLn . unwords . map show . quickSort
