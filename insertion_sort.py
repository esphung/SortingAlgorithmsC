"""
/*
FILENAME:     insertion_sort.py
PURPOSE:      insertion sort algorithm in python3.x
AUTHOR:       Eric Phung
CREATED:      10/29/2020 10:14 PM
*/
"""
import random
def swap(arr, pos):
	b = arr[pos]
	arr[pos] = arr[pos - 1]
	arr[pos - 1] = b
	return arr

limit = 16
def makeTestData():
	random_list = []
	for i in range(0, limit):
		n = random.randint(1, 30)
		random_list.append(n)
	return random_list

data = makeTestData()
print("orginal: {}".format(data))

# Insertionsort
keepGoing = True
i = 0
j = 0
for num in range(1, len(data)):
	i += 1
	# print("set i:{} to => j:{}".format(i, j))
	# set j to i
	j = i
	# swap data[j] and data[j - 1]
	while (j > 0) and (data[j - 1] > data[j]):
		# print("swapping {} and {}".format(data[j], data[j - 1]))
		swap(data, j)
		j = j - 1

print("formatted: {}".format(data))
