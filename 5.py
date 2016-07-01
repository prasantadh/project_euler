# 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
# What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

# n = 1
# got_answer = False
# while (got_answer != True and n <= 300000):
# 	for j in range(1,21):
# 		print (n,j,n%j)
# 		if n % j != 0:
# 			break
# 		if (j == 13 and n%j == 0):
# 			got_answer = True
# 			break
# 	n = n + 1
# n = 1
# got_answer = False
# while (got_answer != True): 
# 	for i in range(2,11):
# 		print (n, i)
# 		if (n % i != 0):
# 			n = n * i
# 		if (i == 10 and n%i == 0):
# 			got_answer = True
# 	# print (n)
# print (n)

n =  1
for i in range(1,21):
	if (n % i != 0):
		for j in range(1,4):
			if (i**j)>=20:
				n = n * i**(j-1)
				break
print (n) 

#or could have checked all the numbers in increment of 20