a = 0
b = 0
for i in range(1,101):
	a = a + i**2
	b = b + i
	print( i, i**2, a, b**2)
print (b**2-a)