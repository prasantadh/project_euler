import time
start_time = time.time()
prime_counter = 0
n = 1
while prime_counter!= 10001:
	n = n + 1 
	factorcounter = 0
	for i in range(1,n+1):
		if n % i == 0:
			factorcounter += 1
			if (factorcounter > 2):
				break
	if factorcounter==2:
		prime_counter+=1
		print(prime_counter, n)
print (n)
print(time.time()-start_time)

