# 525 837799
import operator
import copy

top = 1000000
bottom = 1
seq = []
tsq = []
n = top
counter = 0
seqLen = []
j = 0
for i in range(top, bottom, -1):
	n = i * 2 #check if i need to do this
	tsq = []
	counter = 0
	while (n != 1):
		if (n % 2 == 0):
			n = n / 2
		else:
			n = 3 * n + 1
		if n in seq:
			j = seq.index(n)
			counter += (len(seq) - seq.index(n))
			break
		else:
			tsq.append(n)
			counter += 1
	seqLen.append(counter)
	if counter > len(seq):
		seq = tsq + seq[j:]
	# print(i, tsq)
# print(seqLen)
print (max(seqLen), top - seqLen.index(max(seqLen)))

