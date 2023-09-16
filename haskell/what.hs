main = do
    a <- (map read . words) `fmap` getLine :: IO [Int]
    print a
