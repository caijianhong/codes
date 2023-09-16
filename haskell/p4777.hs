-- Prelude.gcd
-- gcd :: Integral a => a -> a -> a
-- gcd x 0 = x
-- gcd x y = gcd y (x `mod` y)

-- Prelude.lcm
-- lcm :: Integral a => a -> a -> a
-- lcm x y = x * (y `div` (gcd x y))

exgcd :: Integral a => (a, a) -> (a, a)
exgcd (a, 0) = (1, 0)
exgcd (a, b) = let (x, y) = exgcd (b, a `mod` b) in (y, x - (a `div` b) * y)

merge :: Integral a => (a, a) -> (a, a) -> (a, a)
-- Promise: there is at least one vaild solution
--          or check it by (r1 - r2) `mod` (gcd m1 m2) == 0
merge (r1, m1) (r2, m2) = (r3 `mod` l, l) where
    d = gcd m1 m2
    l = lcm m1 m2
    (x, y) = exgcd (m1 `div` d, m2 `div` d)
    k = (r2 - r1) `div` d
    r3 = r1 + k * x * m1

reduce :: (a -> a -> a) -> [a] -> a
reduce f (x:xs) = foldl f x xs

readIntListLn :: IO [Int]
readIntListLn = fmap (map read . words) getLine

readIntegerListLn :: IO [Integer]
readIntegerListLn = fmap (map read . words) getLine

main :: IO ()
main = do
    [n] <- readIntListLn
    input <- sequence $ replicate n readIntegerListLn
    let (r, m) = reduce merge $ map (\[x, y] -> (y, x)) input
    print r
