#A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
# Find the largest palindrome made from the product of two 3-digit numbers.
n = 0
ans = []
for i in range(1000,300,-1):
	for j in range(1000,300,-1):
		n = i*j
		if ((n//100000==n%10) and ((n//10000)%10==(n//10)%10) and ((n//1000)%10 == (n//100)%10)):
			#or i could have just converted it to string, reversed it and checked
			ans = ans + [[n,i,j]]
			break
print (max(ans))

