import time
start_time = time.time()
n = 1
triangle = 0
factor_counter = 0
while factor_counter <= 500:	
	triangle = triangle + n
	factor_counter = 0
	for i in range(1, int((triangle)**0.5)+1):
		if triangle % i == 0:
			factor_counter += 1
	if int(triangle**0.5) == triangle**0.5:
		factor_counter = factor_counter * 2 -1 
	else:
		factor_counter = factor_counter * 2 
	# print ( n, triangle, factor_counter)
	n = n + 1
	
print (triangle, time.time()-start_time)