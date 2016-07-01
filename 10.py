# The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
# Find the sum of all the primes below two million.
import time
start_time = time.time()
n=1
total = 2
while n <= 2000000:
	n = n + 2 
	prime = True
	for i in range(2,int(n**0.5+1)):
		if n % i == 0:
			prime = False
			break
	if prime == True:
		total+=n
		# print (n, total)
print (total)
print(time.time()-start_time)