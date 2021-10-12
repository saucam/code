module Main(main) where
 
import qualified Data.ByteString.Char8 as B
import Data.Maybe
import Data.Functor
import Control.Arrow
 
main::IO ()
main = interact $
  lines >>> solve >>> map show >>> unlines

solve :: [String] -> [Integer]
solve (t:dat) = map (words >>> map read >>> solveOne) dat

solveOne:: [Integer] -> Integer
solveOne [n, k] = minimum $ divs (n, k)

divs :: (Integer, Integer) -> [Integer]
divs (n, k) = a ++ b
  where lst = filter (\x -> n `rem` x == 0) [1, 2 .. (ceiling $ sqrt $ fromIntegral n)::Integer]
        a = [ d | d <- lst, n `div` d <= k]
        b = [ n `div` d | d <- lst, d <= k]
