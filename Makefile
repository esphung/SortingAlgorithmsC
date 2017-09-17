main.o: utility.o insertionsort.o mergesort.o quicksort.o main.c
	# building sorting files
	cc main.c -o main.o

quicksort.o: utility.o
	cc quicksort.c -o quicksort.o

mergesort.o: utility.o
	cc mergesort.c -o mergesort.o

insertionsort.o: utility.o
	cc insertionsort.h -o insertionsort.o

# utility methods

utility.o: utility.h
	cc utility.h -o utility.o

run:
	# executing sort build
	#./insertionsort.o
	#./mergesort.o
	#./quicksort.o
	./main.o

clean:
	# removing compiles
	rm -rf *.out
	rm -rf *.out.dSYM
	rm -rf *.o.dSYM
	rm -rf *.o