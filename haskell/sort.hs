sort' :: Ord a => [a] -> [a]
sort' [] = []
sort' (x:xs) = smaller ++ [x] ++ larger
    where smaller = sort' [a | a <- xs, a <= x]
          larger  = sort' [a | a <- xs, a > x]

join' :: [Int] -> String
join' [] = ""
join' (x:xs) = foldl (\acc x -> acc ++ " " ++ show x) (show x) xs

main :: IO()
main = do
    getLine
    a <- (map read . words) `fmap` getLine :: IO [Int]
    putStrLn . join' . sort' $ a
