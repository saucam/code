module Main(main) where
 
import qualified Data.ByteString.Char8 as B
import Data.Maybe
import Data.Functor
import Control.Arrow
 
getNums :: B.ByteString -> [Int]
getNums =
	let
		f1 = (map ((fst.fromJust) . B.readInt))
		f2 = (B.split ' ')
	in f1.f2
readInts :: IO [Int]
readInts = getNums <$> B.getLine
 
main::IO ()
main = interact $
	lines >>> map (words >>> map read >>> solve >>> show) >>> unlines

solve :: [Integer] -> Integer
solve [a, b] = abs(a - b)
