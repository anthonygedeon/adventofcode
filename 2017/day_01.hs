-- sum - add up all digits in the list 

{-
	- if current and peek() have the same digit then
		sum += digit

	- if @ last digit in list then
		set current to beginning of digit list
		sum += digit
-}

list = [1, 1, 2, 2]

curr = 1

peek' :: Int -> [Int] -> Int
peek' idx arr = (tail arr)!!idx 

main = do
    print (peek' curr list)
