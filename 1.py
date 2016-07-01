summ = 0 #variable for final summation
for i in range(1,1000):
	if (i % 3 == 0) or (i % 5 == 0):
		print (i)
		summ = summ + i
print (summ)