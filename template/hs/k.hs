module Main(main) where

import Control.Arrow
import qualified Data.ByteString.Char8 as B

main :: IO ()
main = interact $
	lines >>> solve >>> show >>> unlines

solve :: [[Char]] -> [[Char]]
solve input = do
	line <- input
	let t = (line :: Int)
  ans <- forM [1..t] (\a -> do
		s <- getLine
		let replace = map (\c -> if c=='1' then '2'; else c)
    let res = replace s
		return res)
	return ans

