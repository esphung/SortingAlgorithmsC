/*

FILENAME:	insertionsort.h

PURPOSE:	Insertionsort header file in C language

AUTHOR:		eric phung

*/


//Define developer-configurable array length, static (on the stack)
//#define ARR_SIZE 100
#include <stdio.h>

int startTimer();
int endTimer();
void fillArray(int a[],int n);
void printArray(int a[],int n);
int getClockCyclesPerSecond(int start, int end);

void myInsertionSort(int a[],int n, int steps) {

	// sorting algorithm variables
	int i = 1;
	int j;
	int x; // swap variable


    // start time
    int start;
    start = startTimer();

    // loop thru array until reaches the end

    //int iCounter = 0;
    while(i < n) {

    	// step: compare array size
		steps += 1;
		// sync j with i

	    j = i;

	    // compare a[j-1] < a[j]

	    while((j > 0)&&((a[j-1]) > (a[j]))) {

	    	// (compare n and compare n) compare n
	    	steps += 3;
	        /* swap a[j] and a[j-1] */
	        x = a[j];
	        a[j] = a[j-1];
	        a[j-1] = x;
	        // count steps for swap, copy, copy
	        steps += 3;
	        // recursive i
	        j = j-1;		//Move the inside index left 1
	        steps++;
	    }// end while j-1 > j

	    // increment i
	    i = i + 1;

	    // steps: addition

	    steps += 1;

    }// end while i is less than length of array

    // end timer
    int end;
    end = endTimer();

    int cycles = getClockCyclesPerSecond(start, end);

	printf("Insertion Sort => \n");
    printArray(a, n);
    printf("Steps: %i\n", steps);
    printf("Elements: %i\n", n);
    printf("Cycles: %i\n", cycles);



}
