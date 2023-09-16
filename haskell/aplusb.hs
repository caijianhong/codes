main :: IO()
main = sum . map read . words <$> getLine >>= print
