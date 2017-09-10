all:
	# building insertion sort files
	cc -Wall -g insertionsort.c -o InsertionSort.out
run:
	# executing insertion sort build
	./InsertionSort.out
clean:
	# removing insertion sort build
	rm -rf InsertionSort.out
	rm -rf InsertionSort.out.dSYM