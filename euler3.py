#largest prime factor for 600851475143
#the brute force way that takes forever to compute
# list_of_factors = []

# for i in range(1, 600851475144):
# 	if ((600851475143 % i) == 0):
# 		list_of_factors = list_of_factors + [i]
# 		print (i)
# print (list_of_factors)


# for i in reversed(list_of_factors):
# 	counter = 0 
# 	for j in range(1, i):
# 		if ((i % j)==0):
# 			counter = counter + 1
# 		if (counter == 2):
# 			break
# 	if (counter == 1):
# 		print (i)
# 		break

#the elegant way
#but taken from http://stackoverflow.com/questions/14138053/project-euler-3-with-python-most-efficient-method
n = 600851475143
i = 2
while ((i * i) < n):
	while ((n % i) == 0):
		n = n / i
	i = i + 1
print(n)