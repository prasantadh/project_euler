a = 1
b = 2
summ = 0
while (b < 4000000):
	if (b % 2) == 0:
		summ = summ + b
	c = b
	b = a + c
	a = c
	print (b)
print (summ)
	 
