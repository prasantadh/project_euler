import time
start_time = time.time()
prime_counter = 6
n = 13
while prime_counter!= 10001:
	n = n + 1 
	prime = True
	for i in range(2,int(n**0.5+1)):
		if n % i == 0:
			prime = False
			break
	if prime == True:
		prime_counter+=1
		print(prime_counter, n)
print (n)
print(time.time()-start_time)