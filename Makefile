all:
	# building sort files
	#cc -Wall -g insertionsort.c -o InsertionSort.out
	cc -Wall -g mergesort.c -o Mergesort.out
run:
	# executing sort build
	#./InsertionSort.out
	./Mergesort.out
clean:
	# removing insertion sort build
	#rm -rf InsertionSort.out
	#rm -rf InsertionSort.out.dSYM
	rm -rf MergeSort.out
	rm -rf MergeSort.out.dSYM