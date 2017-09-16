all:
	# building sort files
	cc -Wall -g insertionsort.c -o InsertionSort.out
	cc -Wall -g mergesort.c -o Mergesort.out
	cc -Wall -g mytimer.h -o mytimer.out
run:
	# executing sort build
	./InsertionSort.out
	./Mergesort.out
clean:
	# removing insertion sort build
	rm -rf InsertionSort*
	#rm -rf InsertionSort.out.dSYM
	rm -rf Mergesort*
	#rm -rf MergeSort.out.dSYM
	rm -rf mytimer.out*